//
// Created by Roie Danino on 18/08/2017.
//

#ifndef __JUDGE_H
#define __JUDGE_H

#include "CourtWorker.h"
#include "Lawyer.h"
#include <ctime>

class Trial;

class Judge : public Lawyer, public CourtWorker
{
private:
    Trial **trials;
    int numOfTrials; //should be initialized with 0 in the constructor implementation

    Judge(const Judge& other);
	const Judge& operator=(const Judge& other);

public:
    Judge(const char* name, int id, //Person
          const char* academicInstitution, int graduatedYear, //Lawyer
          int startingYear, int salary) throw(int); //CourtWorker
    ~Judge();

    inline int getNumOfTrials() const;

    const Trial* getTrialById(int id) const;
    void addTrial(Trial& trial) throw(const char*); //throws exception if the judge isBusy(tm,tm)
    bool isBusy(const tm& startTime, const tm& endTime) const;

    void operator += (Trial& trial) throw(const char*);
    void toOs(ostream &os) const override;
};

#endif
