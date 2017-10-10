#include "Party.h"

void Party::setName(char *name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Party::setSide(Party::ePartySide side)
{
	this->side = side;
}
void Party::setType(Party::ePartyType type)
{
	this->type = type;
}

Party::Party(const char* name, Party::ePartySide side, Party::ePartyType type, const Lawyer& lawyer)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->side = side;
	this->type = type;
	this->lawyer = lawyer;
}

Party::Party(const Party& other)
{
	this->name = new char[strlen(other.getName()) + 1];
	strcpy(this->name, other.getName());
	this->side = other.getSide();
	this->type = other.getType();
	this->lawyer = other.getLawyer();
}


Party::~Party()
{
	delete[] name;
	delete[] &lawyer;
}

inline const char*  Party::getName() const
{
	return this->name;
}

inline  Party::ePartySide  Party::getSide() const
{
	return this->side;
}

inline  Party::ePartyType  Party::getType() const
{
	return this->type;
}

void  Party::setLawyer(const Lawyer& lawyer)
{
	this->lawyer = lawyer;
}
inline const Lawyer& Party::getLawyer() const
{
	return this->lawyer;
}


const Party& Party::operator=(const Party& other)
{
	this->name = new char[strlen(other.getName()) + 1];
	strcpy(this->name, other.getName());
	this->side = other.getSide();
	this->type = other.getType();
	this->lawyer = other.getLawyer();
}
bool Party::operator==(const Party& other) const
{
	return (strcmp(this->name, other.getName()) && this->side == other.getType() && this->type == other.getType() && this->lawyer == other.getLawyer());

}
 ostream& operator<<(ostream& os, const Party& party)
{
	 os << "Party Name: " << party.getName() << ", Side: " << party.getSide() << ", Type: " << party.getType() << ", Lawyer Name: " << party.getLawyer().getName;
}
