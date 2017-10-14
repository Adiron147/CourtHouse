//
// Created by Roie Danino on 18/08/2017.
//

#ifndef __JUDGE_H
#define __JUDGE_H

#include "CourtWorker.h"
#include "Lawyer.h"
#include <ctime>
#include "MyList.h"
#include "IVisitable.h"
#include "IVisitor.h"

class Trial;

class Judge : public Lawyer, public CourtWorker, public IVisitable
{
private:
    MyList<Trial*> trials;

    Judge(const Judge& other);
	const Judge& operator=(const Judge& other);

public:
    Judge(const string& name, int id, //Person
          const string& academicInstitution, int graduatedYear, //Lawyer
          int startingYear, int salary) throw(const char*); //CourtWorker

    inline int getNumOfTrials() const;

    const Trial* getTrialById(int id) const;
    void addTrial(Trial& trial) throw(const char*); //throws exception if the judge isBusy(tm,tm)
	void removeTrial(int trialId);
    bool isBusy(const tm& startTime, const tm& endTime) const;

	virtual void accept(IVisitor* visitor)	{visitor->visit(this);}

    void operator += (Trial& trial) throw(const char*);
    void toOs(ostream &os) const override;
};

#endif
