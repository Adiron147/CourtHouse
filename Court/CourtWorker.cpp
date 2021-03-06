#include "CourtWorker.h"

CourtWorker::CourtWorker(const string& name, int id, int startingYear, int salary) throw(char*)
	: Person(name, id)
{
	setSalary(salary);
	
	setStartingYear(startingYear);
}//throwing for wrong id/startingYear/salary

void CourtWorker::setStartingYear(int startingYear) throw(char*)
{
	if(startingYear >= MIN_STARTING_YEAR && startingYear <= MAX_STARTING_YEAR )
	{
		this->startingYear = startingYear;
	}
	else
	{
		throw("Invalid starting year for court worker");
	}
}

inline int CourtWorker::getStartingYear() const
{
	return startingYear;
}

void CourtWorker::setSalary(int salary) throw(char*)
{
	if(salary > 0 )
	{
		this->salary = salary;
	}
	else
	{
		throw("Invalid salary for court worker");
	}
}

void CourtWorker::toOs(ostream &os) const
{
	os << "Starting year: " << this->startingYear << 
		" salary: " << this->salary;
}