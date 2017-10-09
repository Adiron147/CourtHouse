#ifndef __JURY_H
#define __JURY_H

#include "JuryMember.h"
#include <iostream>
using namespace std;

class Jury
{

static const int DEFAULT_MAX_NUM_OF_JURY_MEMBERS = 12;

private:
    JuryMember** allJuryMembers;
    int numOfMembers;            //logical size
    int maxNumOfMembers;        //physical size
    Jury(const Jury& otherJury);
    void setNumOfMembers(int numOfMembers);

public:
    Jury(JuryMember** allJuryMembers, int maxNumOfMembers = DEFAULT_MAX_NUM_OF_JURY_MEMBERS) throw(int,const char*);// maxNumOfMembers must be a non-zero positive, "allJuryMembers" cannot be a nullptr
    ~Jury();

    void setJuryMembers(JuryMember** allJuryMembers);
    inline const JuryMember** getAllJuryMembers() const;

    inline int getNumOfJuryMembers() const;

    void addJuryMember(const JuryMember* juryMember) throw(const char*); //throws a message if "juryMember" is a nullptr or maxNumOfMembers already exceeded
    bool removeJuryMember(int id) throw(int);

    const Jury& operator=(const Jury& jury);
    const Jury& operator+=(const JuryMember& juryMember) throw(const char*);
    const Jury& operator-=(const JuryMember& juryMember) throw(int);
    const JuryMember& operator[](int index) const throw(int);
    JuryMember& operator[](int index) throw(int);

    virtual void toOs(ostream& os) const ;
};
const int Jury::DEFAULT_MAX_NUM_OF_JURY_MEMBERS;
#endif