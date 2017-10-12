#include "Trial.h"
#include "TmUtilities.h"
#include "Party.h"
#include "Jury.h"
#include "CourtRoom.h"
#include "Judge.h"

const char* Trial::strTrialSubject[] = {"Criminal", "Youth", "Civil", "Property", "Family", "Class Action", "Transportation", "Contracts"};
int Trial::ID = 0;

// TODO: Check if we are using all set methods

//judge shouldn't be busy, room shouldn't be taken and defense != prosecution
Trial::Trial(eTrialSubject subject, Judge& judge, Party& defense, Party& prosecution,
		CourtRoom& trialRoom, const tm& startTime, const tm& endTime) throw(const char*) : 
defense(nullptr), prosecution(nullptr), trialRoom(nullptr), jury(nullptr), judge(nullptr)
{
	trialId=++ID;

	// TODO: already initiated judge... Is it ok?
	setJudge(&judge);
	setDefense(defense);
	setProsecution(prosecution);
	// Setting start time as it is cause at this point 
	// there is no end time to check validation with
	this->startTime = startTime;
	setEndTime(endTime);
	setSubject(subject);
	setTrialRoom(trialRoom);

	// Still no jury
	setJury(nullptr);
}

Trial::~Trial()
{
	delete defense;
	delete prosecution;
	delete jury;
}

void Trial::setSubject(eTrialSubject subject)
{
	this->subject = subject;
}

void Trial::setDefense(Party& defense)  throw(const char*)
{
	// TODO: implement != on party
	if(prosecution == nullptr || defense != *prosecution)
	{
		delete this->defense;
		this->defense = &defense;
	}
	else
	{
		throw("Defense could not be the same as prosecution! (while setting defense)");
	}
}

void Trial::setProsecution(Party& prosecution)  throw(const char*)
{
	// TODO: implement != on party
	if(defense == nullptr || *defense != prosecution)
	{
		delete this->prosecution;
		this->prosecution = &prosecution;
	}
	else
	{
		throw("Defense could not be the same as prosecution! (while setting prosecution)");
	}
}

void Trial::setStartTime(const tm& startTime) throw(const char*)
{
	if(TmUtilities::compareTimes(this->endTime, startTime) == TmUtilities::FIRST_LARGER )
	{
		this->startTime = startTime;
	}
	else
	{
		throw("Trial start time can not be later than end time");
	}
}

void Trial::setEndTime(const tm& endTime) throw(const char*)
{
	if(TmUtilities::compareTimes(endTime, this->startTime) == TmUtilities::FIRST_LARGER )
	{
		this->endTime = endTime;
	}
	else
	{
		throw("Trial end time can not be earlier than start time");
	}
}

Trial::eTrialSubject Trial::getSubject() const
{
	return subject;
}

inline const Party& Trial::getDefense() const
{
	return *defense;
}

const Party& Trial::getProsecution() const
{
	return *prosecution;
}

void Trial::setJury(Jury* jury)
{
	delete this->jury;
	this->jury = jury;
}//jury == nullptr means no jury in trial

inline const Jury* Trial::getJury() const
{
	return jury;
}

void Trial::setJudge(Judge* judge) throw(const char*)
{
	if(judge == nullptr)
	{
		throw("Every trial must have a judge (judge can not be null)!");
	}
	else
	{
		if(judge->isBusy(startTime,endTime))
		{
			throw("Judge is busy! (while initiating trial)");
		}
		else
		{
			if(this->judge != nullptr)
			{
				this->judge->removeTrial(this->trialId);
			}
			this->judge = judge;
			judge->addTrial(*this);
		}	
	}
}

inline const Judge& Trial::getJudge() const
{
	return *judge;
}

void Trial::setTrialRoom(CourtRoom& trialRoom) throw(const char*)
{
	if(trialRoom.isTaken(startTime,endTime))
	{
		throw("Trial room is taken! (while initiating trial)");
	}
	else
	{
		if(this->trialRoom != &trialRoom)
		{
			if(this->trialRoom != nullptr)
			{
				this->trialRoom->removeTrial(this->trialId);
			}

			this->trialRoom = &trialRoom;
		}
	}
}

inline const CourtRoom& Trial::getTrialRoom() const
{
	return *trialRoom;
}

inline bool Trial::hasJury() const
{
	return jury != nullptr;
}

bool Trial::operator==(const Trial& other) const
{
	bool isEqual = false;

	if(this->trialId == other.trialId &&
		*this->defense == *other.defense &&
		*this->prosecution == *other.prosecution &&
		TmUtilities::isEquals(this->endTime, other.endTime) &&
		TmUtilities::isEquals(this->startTime, other.startTime) &&
		*this->judge == *other.judge &&
		this->subject == other.subject)
		{
			if((this->trialRoom == nullptr && other.trialRoom == nullptr) ||
				(this->trialRoom != nullptr && *this->trialRoom == *other.trialRoom) ||
				(other.trialRoom != nullptr && *other.trialRoom == *this->trialRoom))
			{
				// TODO: Add jury == and != operators
				if((this->jury == nullptr && other.jury == nullptr) ||
					(this->jury != nullptr && *this->jury == *other.jury) ||
					(other.jury != nullptr && *other.jury == *this->jury))
				{
					isEqual = true;
				}
			}
		}

	return isEqual;
}

bool Trial::operator!=(const Trial& other) const
{
	return !(other == *this);
}

ostream& operator<<(ostream& os, const Trial& trial)
{
	os << "Trial id = " << trial.trialId <<
		" start: ";
	
	TmUtilities::tmToOs(os, trial.startTime);

	os << " end: ";

	TmUtilities::tmToOs(os, trial.endTime);

	os << " subject: " << Trial::strTrialSubject[trial.subject] <<
		" Judge: " << *trial.judge;
	
	if(trial.hasJury())
	{
		os << " has jury: " << endl;
		os << *trial.jury;
	}
	else
	{
		os << " no jury" << endl ;
	}

	return os;
}