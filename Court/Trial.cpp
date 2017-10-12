#include "Trial.h"
#include "TmUtilities.h"
#include "Party.h"
#include "CourtRoom.h"
#include "Jury.h"

int Trial::ID = 0;

// TODO: Check if we are using all set methods

//judge shouldn't be busy, room shouldn't be taken and defense != prosecution
Trial::Trial(eTrialSubject subject, Judge& judge, Party& defense, Party& prosecution,
		CourtRoom& trialRoom, const tm& startTime, const tm& endTime) throw(const char*)
{
	// TODO: already initiated judge... Is it ok?
	setJudge(&judge);
	setDefense(defense);
	setProsecution(prosecution);
	setStartTime(startTime);
	setEndTime(endTime);
	setSubject(subject);
	setTrialRoom(trialRoom);

	// Still no jury
	setJury(nullptr);

	trialId=++ID;
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
	if(defense != *prosecution)
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
	if(*defense != prosecution)
	{
		delete this->prosecution;
		this->prosecution = &prosecution;
	}
	else
	{
		throw("Defense could not be the same as prosecution! (while setting prosecution)");
	}
}

inline int Trial::getTrialId() const
{
	return trialId;
}

void Trial::setStartTime(const tm& startTime) throw(const char*)
{
	if(TmUtilities::tmDiff(this->endTime, startTime) > 0 )
	{
		this->startTime = startTime;
	}
	else
	{
		throw("Trial start time can not be later than end time");
	}
}

inline const tm& Trial::getStartTime() const
{
	return startTime;
}

void Trial::setEndTime(const tm& endTime) throw(const char*)
{
	if(TmUtilities::tmDiff(endTime, this->startTime) > 0 )
	{
		this->endTime = endTime;
	}
	else
	{
		throw("Trial end time can not be earlier than start time");
	}
}

inline const tm& Trial::getEndTime() const
{
	return endTime;
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
	if(judge != nullptr)
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
			this->judge = judge;
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
		if(this->trialRoom != nullptr)
		{
			this->trialRoom->removeTrial(this->trialId);
		}

		trialRoom.addTrial(*this);
		this->trialRoom = &trialRoom;
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
	os << "Trial id = " << trial.trialId << endl <<
		" start: ";
	
	TmUtilities::tmToOs(os, trial.startTime);

	os << endl << " end: ";

	TmUtilities::tmToOs(os, trial.endTime);

	os << endl << " subject: " <<trial.subject << endl <<
		" Judge: " << trial.judge << endl;
	
	if(trial.hasJury())
	{
		os << " has jury" << endl;
	}
	else
	{
		os << " no jury" << endl ;
	}

	return os;
}