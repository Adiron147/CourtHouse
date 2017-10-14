#include "Judge.h"
#include "Trial.h"
#include "TmUtilities.h"

Judge::Judge(const string& name, int id, //Person
        const string& academicInstitution, int graduatedYear, //Lawyer
        int startingYear, int salary) throw(const char*): 
		Person(name, id), 
		Lawyer(name, id, academicInstitution, graduatedYear),
		CourtWorker(name, id,startingYear, salary)
{
}//CourtWorker

inline int Judge::getNumOfTrials() const
{
	return trials.getSize();
}

const Trial* Judge::getTrialById(int id) const
{
	const Trial* foundTrial = nullptr;

	const Node<Trial*> *head = this->trials.getHead();

	while(head != nullptr)
	{
		if(head->getData()->getTrialId() == id)
		{
			foundTrial = head->getData();
			break;
		}

		head = head->getNext();
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
		trials.addToEnd(&trial);
	}
}//throws exception if the judge isBusy(tm,tm)

void Judge::removeTrial(int trialId)
{
	if(getTrialById(trialId) != nullptr)
	{
		const Node<Trial*> *head = this->trials.getHead();

		while(head != nullptr)
		{
			if(head->getData()->getTrialId() == trialId)
			{
				this->trials.removeFirstNodeOf(head->getData());
				break;
			}

			head = head->getNext();
		}
	}
}

bool Judge::isBusy(const tm& startTime, const tm& endTime) const
{
	bool isBusy = false;

	const Node<Trial*> *head = this->trials.getHead();

	while(head != nullptr)
	{
		const tm& currTrialStart = head->getData()->getStartTime();
		const tm& currTrialEnd = head->getData()->getEndTime();
		if(TmUtilities::doesColide(currTrialStart, currTrialEnd, startTime, endTime))
		{
			isBusy = true;
			break;
		}

		head = head->getNext();
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
	os << " ";
	CourtWorker::toOs(os);
}