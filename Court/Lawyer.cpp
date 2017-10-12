#include "Lawyer.h"

Lawyer::Lawyer(const char* name, int id, const char* academicInstitution, int graduatedYear)throw(const char*) : Person(name,id), academicInstitution(nullptr)
{
	if(academicInstitution != nullptr)
	{
		this->academicInstitution = new char[strlen(academicInstitution) + 1];
 		strcpy(this->academicInstitution, academicInstitution);
	}
	else
	{
		throw("academicInstitution must have a value! (while initiating Lawyer)");
	}

	this->graduatedYear = graduatedYear;
}

Lawyer::~Lawyer()
{
	delete []this->academicInstitution;
}

inline const char* Lawyer::getAcademicInstitution() const
{
	return this->academicInstitution;
}

inline int Lawyer::getGraduatedYear() const
{
	return this->graduatedYear;
}

void Lawyer::toOs(ostream& os) const
{
	os << " Academic Institution: " << this->getAcademicInstitution() << ", Graduated Year: " << this->getGraduatedYear();
 }