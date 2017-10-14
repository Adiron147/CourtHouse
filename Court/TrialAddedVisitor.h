#ifndef __TRIAL_ADDED_VISITOR_H
#define __TRIAL_ADDED_VISITOR_H

#include "IVisitor.h"
#include "Judge.h"

class TrialAddedVisitor : public IVisitor
{
public:
	virtual void visit(IVisitable* element) override
	{
		Judge* judge = (Judge*)element;
		judge->setSalary(judge->getSalary()+ TRIAL_BONUS);
	}
private:
	static const int TRIAL_BONUS = 100;
};

#endif __TRIAL_ADDED_VISITOR_H