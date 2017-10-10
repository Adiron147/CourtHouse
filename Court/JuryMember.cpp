#include "JuryMember.h"


JuryMember::JuryMember(const JuryMember& otherJuryMember) : Person(otherJuryMember.getName(), otherJuryMember.getId()){}

JuryMember::JuryMember(const char* name, int id) throw(int) : Person(name, id) //id must be a positive integer;
{}

void JuryMember::toOs(ostream& os) const
{
	os << "Jury Memeber Name: " << this->getName() << "Jury Memeber Id: " << this->getId();
}