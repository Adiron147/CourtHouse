#include "Person.h"


Person::Person(const char* name, int id) throw(int)
{
	this->name = new char[];
	strcpy(this->name, name);

	if(id < 0)
	{
		throw id;
	}
	else
	{
		this->id = id;
	}
}

Person::Person(const Person& other) 
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(other.getName()) + 1];
	strcpy(this->name, other.getName());
	id = other.getId();
}

void Person::setName(const char* name)
{
	if (this->name != nullptr) 
	{
		delete[] this->name;
	}

	this->name = new char[];
	strcpy(this->name, name);
}

void Person::setId(int id)
{
	if (id >= 0)
	{
		this->id = id;
	}
}

const char* Person::getName() const 
{
	return this->name; 
}

inline int Person::getId() const
{
	return this->id;
}

Person::~Person()
{
	delete[] this->name;
}

const Person& Person::operator=(const Person& other)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(other.getName()) + 1];
	strcpy(this->name, other.getName());
	id = other.getId();
}

bool Person::operator==(const Person& other) const
{
	if (strcmp(this->name, other.getName()) == 0 && this->id == other.getId())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const Person& person)
{
	os << "Name: " << person.getName() << ", Id: " << person.getId();
}

void Person::toOs(ostream& os) const
{
	os << "Name: " << this->name << ", Id: " << this->id;
}