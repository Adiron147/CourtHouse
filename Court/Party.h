#ifndef __PARTY_H
#define __PARTY_H

#include <iostream>
#include "Lawyer.h"
using namespace std;


class Trial;

class Party
{
public:
	static const int NUM_OF_PARTY_SIDES = 2;
	static const int NUM_OF_PARTY_TYPES = 3;
    enum ePartySide {DEFENSE, PROSECUTION};
    enum ePartyType {SINGLE_PERSON, ORGANIZATION, STATE};

    static const char* strPartySide[NUM_OF_PARTY_SIDES];
    static const char* strPartyType[NUM_OF_PARTY_TYPES];

private:
    char* name;
    ePartySide side;
    ePartyType type;
    Lawyer& lawyer;

    Party(const Party& other);
    void setName(char *name);
    void setSide(ePartySide side);
    void setType(ePartyType type);

public:
    Party(const char* name, ePartySide side, ePartyType type, const Lawyer& lawyer);
    ~Party();

    inline const char* getName() const;

    inline ePartySide getSide() const;

    inline ePartyType getType() const;

    void setLawyer(const Lawyer& lawyer);
    inline const Lawyer& getLawyer() const;


    const Party& operator=(const Party& other);
    bool operator==(const Party& other) const;
    friend ostream& operator<<(ostream& os, const Party& party);
};
const int Party::NUM_OF_PARTY_SIDES;
const int Party::NUM_OF_PARTY_TYPES;
const char* Party::strPartySide[NUM_OF_PARTY_SIDES] = {"Defense", "Prosecution"};
const char* Party::strPartyType[NUM_OF_PARTY_TYPES] = {"Single Person", "Organization", "State"};

#endif
