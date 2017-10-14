#include "CourtRoom.h"
#include "Trial.h"
#include "TmUtilities.h"

int CourtRoom::SERIAL_NUMBER = 0;

CourtRoom::CourtRoom()
{
	roomNumber = ++SERIAL_NUMBER;
}

CourtRoom::~CourtRoom()
{
	vector<Trial*>::iterator  itr    = allTrials.begin();
	vector<Trial*>::iterator  itrEnd = allTrials.end();
	
	for ( ; itr != itrEnd; ++itr)
	{
	    delete *itr;
	}
}

inline int CourtRoom::getNumOfTrials() const
{
	return allTrials.size();
}

Trial* CourtRoom::getTrialByIndex(int index)
{
	// Returning TRIAL_NOT_IN_COURT if not belong to the court
	vector<Trial*>::iterator  itr    = allTrials.begin();
	vector<Trial*>::iterator  itrEnd = allTrials.end();

	for(int i = 0; itr != itrEnd && i < index; ++i, ++itr );

	return *itr;
}

const Trial* CourtRoom::getTrialByIndex(int index) const
{
	// Returning TRIAL_NOT_IN_COURT if not belong to the court
	vector<Trial*>::const_iterator  itr    = allTrials.begin();
	vector<Trial*>::const_iterator  itrEnd = allTrials.end();

	for(int i = 0; itr != itrEnd && i < index; ++i, ++itr );

	return *itr;
}

void CourtRoom::addTrial(Trial& trial) throw(const char*)
{
	if(isTaken(trial.getStartTime(),trial.getEndTime()))
	{
		throw("Court room is busy (while adding trial)");
	}
	else
	{
		trial.setTrialRoom(*this);

		allTrials.push_back(&trial);
	}
}//throws exception if the room isTaken(tm,tm)

void CourtRoom::removeTrial(int trialId) throw(const char*)
{
	bool wasTrialFound = false;

	vector<Trial*>::iterator  itr    = allTrials.begin();
	vector<Trial*>::iterator  itrEnd = allTrials.end();
	
	for ( ; itr != itrEnd; ++itr)
	{
		if((*itr)->getTrialId() == trialId)
		{
			delete *itr;
			allTrials.erase(itr);
			wasTrialFound = true;
		}
	}

	// Checking if the trial is in the court
	if(!wasTrialFound)
	{
		throw("Court room does not conatin trial (while removing trial)");
	}
}//throws an exception if trialId doesn't exist

bool CourtRoom::isTaken(const tm& startTime, const tm& endTime) const
{
	bool isTaken = false;

	// Checking all trials for collision:

	vector<Trial*>::const_iterator  itr    = allTrials.begin();
	vector<Trial*>::const_iterator  itrEnd = allTrials.end();
	
	for ( ; itr != itrEnd; ++itr)
	{
	    if(TmUtilities::doesColide((*itr)->getStartTime(), (*itr)->getEndTime(), startTime, endTime))
		{
			isTaken = true;
			break;
		}
	}

	return isTaken;
}

bool CourtRoom::operator==(const CourtRoom& other) const
{
	bool isEqual = false;

	if(other.roomNumber == roomNumber && allTrials.size() == other.allTrials.size() && 
		other.allTrials == this->allTrials)
	{
		isEqual = true;
	}

	return isEqual;
}

Trial& CourtRoom::operator[](int index) throw(const char*)
{
	if (index >= 0 && index < getNumOfTrials())
	{
		return *getTrialByIndex(index);
	}
	else
	{
		throw("Wrong trial index (in CourtRoom operator[])");
	}
}

const Trial& CourtRoom::operator[](int index) const throw(const char*)
{
	if (index >= 0 && index < getNumOfTrials())
	{
		return *getTrialByIndex(index);
	}
	else
	{
		throw("Wrong trial index (in CourtRoom operator[])");
	}
}

ostream& operator<<(ostream& os, const CourtRoom& courtRoom)
{
	os << "Court room number " << courtRoom.roomNumber << " Trials: " << endl;

	if(courtRoom.getNumOfTrials() == 0)
	{
		os << "empty";
	}
	else
	{
		vector<Trial*>::const_iterator  itr    = courtRoom.allTrials.begin();
		vector<Trial*>::const_iterator  itrEnd = courtRoom.allTrials.end();
	
		for ( ; itr != itrEnd; ++itr)
		{
			os << *itr;
		}
	}

	return os;
}