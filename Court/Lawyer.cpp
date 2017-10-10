#include "Lawyer.h"

Lawyer::Lawyer(const char* name, int id, const char* academicInstitution, int graduatedYear)throw(int) : Person(name,id)
{
	this->academicInstitution = new char[];
	strcpy(this->academicInstitution, academicInstitution);
	this->graduatedYear = graduatedYear;
}
Lawyer::~Lawyer()
{

}

inline char* Lawyer::getAcademicInstitution() const
{
	return this->academicInstitution;
}

inline int Lawyer::getGraduatedYear() const
{
	return this->graduatedYear;
}

const Lawyer& Lawyer::operator=(const Lawyer& other): Person(other.getName(),other.getId())
{ 
	this->academicInstitution = new char[strlen(other.getName())];
	strcpy(this->academicInstitution, other.getName());
	this->getAcademicInstitution = other.getGraduatedYear();
}
void Lawyer::toOs(ostream& os) const
{
	os << "Lawyer Name: " << this->getName() << ", Lawyer Id: " << this->getId() << ", Academic Institution: " << this->getAcademicInstitution() << ", Graduated Year: " << this->getGraduatedYear();
 }

Lawyer::Lawyer(const Lawyer& other) : Person(other.getName(),other.getId())
{
	this->academicInstitution = new char[strlen(other.getName())];
	strcpy(this->academicInstitution, other.getName());
	this->getAcademicInstitution = other.getGraduatedYear();
 }