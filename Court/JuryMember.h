#ifndef __JURY_MEMBER_H
#define __JURY_MEMBER_H

#include "Person.h"


class JuryMember: public Person
{
private:
	JuryMember(const JuryMember& otherJuryMember);

public:
	JuryMember(const char* name, int id) throw(const char*); //id must be a positive integer;

	virtual void toOs(ostream& os) const override;

};
#endif