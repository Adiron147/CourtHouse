#ifndef __COURT_WORKER_H
#define __COURT_WORKER_H

#include "Person.h"

class CourtWorker : virtual public Person 
{

private:
	static const int MAX_STARTING_YEAR = 2004;
	static const int MIN_STARTING_YEAR = 1920;

    int startingYear;
    int salary;

	CourtWorker(const CourtWorker& other);
    void setStartingYear(int startingYear) throw(const char*);

public:

    CourtWorker(const string& name, int id, int startingYear, int salary) throw(const char*); //throwing for wrong id/startingYear/salary

    inline int getStartingYear() const;

    void setSalary(int salary) throw(char*);
	inline int getSalary() const {return salary;}

    void toOs(ostream &os) const override;
};

#endif


