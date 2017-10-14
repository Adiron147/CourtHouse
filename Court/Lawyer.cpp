#include "Lawyer.h"

Lawyer::Lawyer(const string& name, int id, const string& academicInstitution, int graduatedYear)throw(const char*) : Person(name,id)
{
	if(academicInstitution.empty())
	{
		throw("Invalid lawyer academic institution");
	}
	else
	{
		this->academicInstitution = academicInstitution;
	}

	this->graduatedYear = graduatedYear;
}

inline const string& Lawyer::getAcademicInstitution() const
{
	return this->academicInstitution;
}

inline int Lawyer::getGraduatedYear() const
{
	return this->graduatedYear;
}

void Lawyer::toOs(ostream& os) const
{
	os << " Academic Institution: " << this->getAcademicInstitution().c_str() << ", Graduated Year: " << this->getGraduatedYear();
}