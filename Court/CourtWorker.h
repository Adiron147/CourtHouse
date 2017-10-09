#ifndef __COURT_WORKER_H
#define __COURT_WORKER_H

#include "Person.h"

class CourtHouse;

class CourtWorker : virtual public Person 
{

private:
	static const int MAX_STARTING_YEAR = 1999;
	static const int MIN_STARTING_YEAR = 1920;

    int startingYear;
    int salary;

	CourtWorker(const CourtWorker& other);
    void setStartingYear(int startingYear) throw(char*);

public:

    CourtWorker(const char* name, int id, int startingYear, int salary) throw(char*); //throwing for wrong id/startingYear/salary

    inline int getStartingYear() const;

    void setSalary(int salary) throw(char*);
    inline int getSalary() const;

    void toOs(ostream &os) const override;
};

#endif


