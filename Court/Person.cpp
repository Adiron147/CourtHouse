#include "Person.h"
 
Person::Person(const string& name, int id) throw(const char*)
{
	setId(id);
	setName(name);
}
 
void Person::setName(const string& name)
{
	this->name = name;
}
 
void Person::setId(int id) throw(const char*)
{
	if(id >= 0)
	{
 		this->id = id;
	}
	else
	{
 		throw("Invalid person id, must be positive (while initilizing Person)");
	}
}
 
bool Person::operator==(const Person& other) const
{
	return (other.name.compare(this->name)==0) && (other.id == this->id);
}
 
ostream& operator<<(ostream& os, const Person& person)
{
	os << "Id: " << person.id << " Name: " << person.name.c_str();
	person.toOs(os);
	return os;
}
 
 // Virtual
void Person::toOs(ostream& os) const {} 
