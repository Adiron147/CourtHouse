#include "Person.h"
 
Person::Person(const char* name, int id) throw(const char*) : name(nullptr)
{
	setId(id);
 	setName(name);
}

 // Virtual
Person::~Person()
{
 	delete []this->name;
}
 
void Person::setName(const char* name) throw(const char*)
{
	delete []this->name;
	if(name == nullptr)
	{
		throw("Person name can't be null");
	}
	else
	{
 		this->name = new char[strlen(name) + 1];
 		strcpy(this->name, name);
	}
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
	return strcmp(other.name,this->name) && (other.id == this->id);
}
 
ostream& operator<<(ostream& os, const Person& person)
{
 	os << "Id: " << person.id << " Name: " << person.name;
 	person.toOs(os);
 	return os;
}
 
 // Virtual
void Person::toOs(ostream& os) const {} 
