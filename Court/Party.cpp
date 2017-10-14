#include "Party.h"

const string Party::strPartySide[] = {"Defense", "Prosecution"};
const string Party::strPartyType[] = {"Single Person", "Organization", "State"};

void Party::setName(const string& name) throw(const char*)
{
	this->name = name;
}
void Party::setSide(Party::ePartySide side)
{
	this->side = side;
}
void Party::setType(Party::ePartyType type)
{
	this->type = type;
}

Party::Party(const string& name, ePartySide side, ePartyType type, const string& lawyerName, 
	int lawyerId, int lawyerInstitutionId, int lawyerGradYear)throw(const char*): 
lawyer(lawyerName,lawyerId,lawyerGradYear, lawyerInstitutionId)
{
	setName(name);
	setSide(side);
	setType(type);
}

inline const string&  Party::getName() const
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

inline const LawyerAcademyCode& Party::getLawyer() const
{
	return this->lawyer;
}

bool Party::operator==(const Party& other) const
{
	return ((other.name.compare(this->name)==0) && this->side == other.getType() && this->type == other.getType() && this->lawyer == other.getLawyer());
}

bool Party::operator!=(const Party& other) const
{
	return !(*this == other);
}

 ostream& operator<<(ostream& os, const Party& party)
{
	os << "Party Name: " << party.name.c_str() << ", Side: " << Party::strPartySide[party.side].c_str() << 
		", Type: " << Party::strPartyType[party.type].c_str() << ", Lawyer: " << party.lawyer;
	 return os;
}