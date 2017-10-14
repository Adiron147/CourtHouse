#ifndef __LAWYER_H
#define __LAWYER_H

#include "Person.h"

class Lawyer : virtual public Person
{

private:
    string academicInstitution;
    int graduatedYear;

    
	const Lawyer& operator=(const Lawyer& other);
	Lawyer(const Lawyer& other);
public:
    Lawyer(const string& name, int id, const string& academicInstitution, int graduatedYear)throw(const char*);

    inline const string& getAcademicInstitution() const;

    inline int getGraduatedYear() const;

    
    virtual void toOs(ostream& os) const override;

};

#endif 
