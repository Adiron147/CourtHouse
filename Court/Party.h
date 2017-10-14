#ifndef __PARTY_H
#define __PARTY_H

#include <iostream>
#include "LawyerAcademyCode.h"
using namespace std;

class Party
{
public:
	static const int NUM_OF_PARTY_SIDES = 2;
	static const int NUM_OF_PARTY_TYPES = 3;
    enum ePartySide {DEFENSE, PROSECUTION};
    enum ePartyType {SINGLE_PERSON, ORGANIZATION, STATE};

    static const string strPartySide[];
    static const string strPartyType[];

private:
    string name;
    ePartySide side;
    ePartyType type;
    LawyerAcademyCode lawyer;

    Party(const Party& other);
    void setName(const string& name) throw(const char*);
    void setSide(ePartySide side);
    void setType(ePartyType type);
	const Party& operator=(const Party& other);
public:
    Party(const string& name, ePartySide side, ePartyType type, const string& lawyerName, 
		int lawyerId, int lawyerInstitutionId, int lawyerGradYear) throw(const char*);

    inline const string& getName() const;

    inline ePartySide getSide() const;

    inline ePartyType getType() const;

    inline const LawyerAcademyCode& getLawyer() const;
    
    bool operator==(const Party& other) const;
	bool operator!=(const Party& other) const;
    friend ostream& operator<<(ostream& os, const Party& party);
};

#endif
