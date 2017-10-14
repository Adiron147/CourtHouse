#ifndef __PARTY_H
#define __PARTY_H

#include <iostream>
#include "Lawyer.h"
using namespace std;

class Party
{
public:
	static const int NUM_OF_PARTY_SIDES = 2;
	static const int NUM_OF_PARTY_TYPES = 3;
    enum ePartySide {DEFENSE, PROSECUTION};
    enum ePartyType {SINGLE_PERSON, ORGANIZATION, STATE};

    static const char* strPartySide[];
    static const char* strPartyType[];

private:
    char* name;
    ePartySide side;
    ePartyType type;
    Lawyer lawyer;

    Party(const Party& other);
    void setName(const char *name) throw(const char*);
    void setSide(ePartySide side);
    void setType(ePartyType type);
	const Party& operator=(const Party& other);
public:
    Party(const char* name, ePartySide side, ePartyType type, const char* lawyerName, 
		int lawyerId, const char* lawyerInstitution, int lawyerGradYear) throw(const char*);
    ~Party();

    inline const char* getName() const;

    inline ePartySide getSide() const;

    inline ePartyType getType() const;

    inline const Lawyer& getLawyer() const;


    
    bool operator==(const Party& other) const;
	bool operator!=(const Party& other) const;
    friend ostream& operator<<(ostream& os, const Party& party);
};
//

#endif
