#include "CourtRoom.h"
#include "Trial.h"
#include "TmUtilities.h"

int CourtRoom::SERIAL_NUMBER = 0;

CourtRoom::CourtRoom()
{
	roomNumber = ++SERIAL_NUMBER;
	numOfTrials = 0;
	allTrials = nullptr;
}

CourtRoom::~CourtRoom()
{
	for(int i = 0; i < numOfTrials; i ++)
	{
		delete allTrials[i];
	}

	delete []allTrials;
}

// TODO: Do we need it? maybe not safe... consider not implementing
inline Trial** CourtRoom::getAllTrials() const
{
	return allTrials;
}

int CourtRoom::getTrialIndexById(int trialId) const
{
	// Returning TRIAL_NOT_IN_COURT if not belong to the court
	int indexOfTrial = CourtRoom::TRIAL_NOT_IN_COURT;

	for(int i = 0; i < numOfTrials; i ++ )
	{
		if(this->allTrials[i]->getTrialId() == trialId)
		{
			indexOfTrial = i;
		}
	}

	return indexOfTrial;
}

void CourtRoom::addTrial(Trial& trial) throw(const char*)
{
	if(isTaken(trial.getStartTime(),trial.getEndTime()))
	{
		throw("Court room is busy (while adding trial)");
	}
	else
	{
		Trial** updatedTrials = new Trial*[numOfTrials + 1];
		
		// Coppying all the old trials:

		for(int i = 0; i < numOfTrials; i ++)
		{
			updatedTrials[i] = allTrials[i];
		}

		// No need for the old array anymore
		delete []allTrials;

		trial.setTrialRoom(*this);

		updatedTrials[numOfTrials] = &trial;

		++numOfTrials;

		allTrials = updatedTrials;
	}
}//throws exception if the room isTaken(tm,tm)

void CourtRoom::removeTrial(int trialId) throw(const char*)
{
	int indexOfTrial = getTrialIndexById(trialId);

	// Checking if the trial is in the court
	if(indexOfTrial == CourtRoom::TRIAL_NOT_IN_COURT)
	{
		throw("Court room does not conatin trial (while removing trial)");
	}
	else
	{	
		Trial* removedTrial = this->allTrials[indexOfTrial];

		// Shifting all trials one slot left until the end
		for(int i = indexOfTrial; i < numOfTrials - 1; i++)
		{
			this->allTrials[i] = this->allTrials[i+1];
		}

		// TODO: Maybe it will be used later?
		// No need for that trial
		delete removedTrial;

		numOfTrials --;
	}
}//throws an exception if trialId doesn't exist

bool CourtRoom::isTaken(const tm& startTime, const tm& endTime) const
{
	bool isTaken = false;

	// Checking all trials for collision:

	for(int i = 0; i < numOfTrials; i ++)
	{
		if(TmUtilities::doesColide(allTrials[i]->getStartTime(), allTrials[i]->getEndTime(), startTime, endTime))
		{
			isTaken = true;
			break;
		}
	}

	return isTaken;
}

bool CourtRoom::operator==(const CourtRoom& other) const
{
	bool isEqual = true;

	if(other.roomNumber == roomNumber && numOfTrials == other.numOfTrials)
	{
		for(int i = 0; i < other.numOfTrials; i ++)
		{
			if((*other.allTrials[i] != *allTrials[i]))
			{
				isEqual = false;
				break;
			}
		}
	}

	return isEqual;
}

Trial& CourtRoom::operator[](int index) throw(const char*)
{
	if (index >= 0 && index < numOfTrials)
	{
		return *(this->allTrials[index]);
	}
	else
	{
		throw("Wrong trial index (in CourtRoom operator[])");
	}
}

const Trial& CourtRoom::operator[](int index) const throw(const char*)
{
	if (index >= 0 && index < numOfTrials)
	{
		return *(this->allTrials[index]);
	}
	else
	{
		throw("Wrong trial index (in CourtRoom operator[])");
	}
}

ostream& operator<<(ostream& os, const CourtRoom& courtRoom)
{
	os << "Court room number " << courtRoom.roomNumber << " Trials: " << endl;

	if(courtRoom.numOfTrials == 0)
	{
		os << "empty";
	}
	else
	{
		for(int i = 0; i < courtRoom.numOfTrials; i ++ ) 
		{
			os << courtRoom.allTrials[i] << endl;
		}
	}

	return os;
}