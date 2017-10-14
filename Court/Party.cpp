#include "Party.h"

const char* strPartySide[] = {"Defense", "Prosecution"};
const char* strPartyType[] = {"Single Person", "Organization", "State"};

void Party::setName(const char *name) throw(const char*)
{
	delete []this->name;
	if(name == nullptr)
	{
		throw("Party name can't be null");
	}
	else
	{
 		this->name = new char[strlen(name) + 1];
 		strcpy(this->name, name);
	}
}
void Party::setSide(Party::ePartySide side)
{
	this->side = side;
}
void Party::setType(Party::ePartyType type)
{
	this->type = type;
}

Party::Party(const char* name, ePartySide side, ePartyType type, const char* lawyerName, 
	int lawyerId, const char* lawyerInstitution, int lawyerGradYear)throw(const char*): 
name(nullptr), lawyer(lawyerName,lawyerId,lawyerInstitution,lawyerGradYear)
{
	setName(name);
	setSide(side);
	setType(type);
}

Party::~Party()
{
	delete[] name;
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

inline const Lawyer& Party::getLawyer() const
{
	return this->lawyer;
}

bool Party::operator==(const Party& other) const
{
	return (strcmp(this->name, other.getName()) && this->side == other.getType() && this->type == other.getType() && this->lawyer == other.getLawyer());

}

bool Party::operator!=(const Party& other) const
{
	return !(*this == other);
}

 ostream& operator<<(ostream& os, const Party& party)
{
	os << "Party Name: " << party.name << ", Side: " << party.side << 
		", Type: " << party.type << ", Lawyer: " << party.lawyer;
	 return os;
}