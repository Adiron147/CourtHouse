#ifndef __TRIAL_REMOVED_VISITOR_H
#define __TRIAL_REMOVED_VISITOR_H

#include "IVisitor.h"
#include "CourtWorker.h"

class TrialRemovedVisitor : public IVisitor
{
public:
	virtual void visit(IVisitable* element) override
	{
		CourtWorker* judge = (CourtWorker*)element;
		judge->setSalary(judge->getSalary() - TRIAL_REMOVAL_PENALTY);
	}
private:
	static const int TRIAL_REMOVAL_PENALTY = 200;
};

#endif __TRIAL_REMOVED_VISITOR_H