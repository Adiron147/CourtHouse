#include "Judge.h"
#include "Trial.h"
#include <ctime>
#include "TmUtilities.h"

Judge::Judge(const char* name, int id, //Person
        const char* academicInstitution, int graduatedYear, //Lawyer
        int startingYear, int salary) throw(int): 
		Person(name, id), 
		Lawyer(name, id, academicInstitution, graduatedYear),
		CourtWorker(name, id,startingYear, salary)
{
	trials = nullptr;
	numOfTrials = 0;
}//CourtWorker

Judge::~Judge()
{
	delete[] trials;
}

inline int Judge::getNumOfTrials() const
{
	return numOfTrials;
}

const Trial* Judge::getTrialById(int id) const
{
	Trial* foundTrial = nullptr;

	for(int i = 0; i < numOfTrials; i ++)
	{
		if(this->trials[i]->getTrialId() == id)
		{
			foundTrial = this->trials[i];
		}
	}

	return foundTrial;
}

void Judge::addTrial(Trial& trial) throw(const char*)
{
	if(isBusy(trial.getStartTime(),trial.getEndTime()))
	{
		throw("judge is busy (while adding trial)");
	}
	else
	{
		Trial** updatedTrials = new Trial*[numOfTrials + 1];
		
		// Coppying all the old trials:

		for(int i = 0; i < numOfTrials; i ++)
		{
			updatedTrials[i] = trials[i];
		}

		// No need for the old array anymore
		delete trials;

		updatedTrials[++numOfTrials] = &trial;

		trials = updatedTrials;
	}
}//throws exception if the judge isBusy(tm,tm)

bool Judge::isBusy(const tm& startTime, const tm& endTime) const
{
	bool isBusy = false;

	for(int i = 0; i < numOfTrials; i ++)
	{
		// Checking if the current trial colides with the given time
		if(TmUtilities::doesColide(this->trials[i]->getStartTime(), this->trials[i]->getEndTime(), startTime, endTime) )
		{
			isBusy = true;
			break;
		}
	}

	return isBusy;
}

void Judge::operator+=(Trial& trial) throw(const char*)
{
	addTrial(trial);
}

void Judge::toOs(ostream &os) const
{
	Lawyer::toOs(os);
	CourtWorker::toOs(os);
}