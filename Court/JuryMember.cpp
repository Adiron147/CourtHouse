#include "JuryMember.h"

JuryMember::JuryMember(const string& name, int id) throw(const char*) : Person(name, id) //id must be a positive integer;
{}

void JuryMember::toOs(ostream& os) const{}