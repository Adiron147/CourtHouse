#include "Person.h"

Person::Person(const char* name, int id) throw(char*) : name(nullptr)
{
	setName(name);
	setId(id);
}

// Virtual
Person::~Person()
{
	delete []this->name;
}

void Person::setName(const char* name)
{
	delete []this->name;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

void Person::setId(int id) throw(char*)
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

inline const char* Person::getName() const
{
	return name;
}

inline int Person::getId() const
{
	return id;
}

bool Person::operator==(const Person& other) const
{
	return strcmp(other.name,this->name) && (other.id == this->id);
}

ostream& operator<<(ostream& os, const Person& person)
{
	cout << "In operator<<(Base&)\n";
	os << "Id: " << person.id << " Name: " << person.name;
	person.toOs(os);
	return os;
}

// Virtual
void Person::toOs(ostream& os) const {}