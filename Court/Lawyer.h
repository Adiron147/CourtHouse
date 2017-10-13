#ifndef __LAWYER_H
#define __LAWYER_H

#include "Person.h"

class Lawyer : virtual public Person
{

private:
    char* academicInstitution;
    int graduatedYear;

    
	const Lawyer& operator=(const Lawyer& other);
	Lawyer(const Lawyer& other);
public:
    Lawyer(const char* name, int id, const char* academicInstitution, int graduatedYear)throw(const char*);
    ~Lawyer();

    inline const char* getAcademicInstitution() const;

    inline int getGraduatedYear() const;

    
    virtual void toOs(ostream& os) const override;

};

#endif 
