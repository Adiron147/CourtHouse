#ifndef __JURY_H
#define __JURY_H

#include <iostream>
using namespace std;

class JuryMember;

class Jury
{

static const int DEFAULT_MAX_NUM_OF_JURY_MEMBERS = 12;

private:
    JuryMember** allJuryMembers;
    int numOfMembers;            //logical size
    int maxNumOfMembers;        //physical size
    Jury(const Jury& otherJury);
	const Jury& operator=(const Jury& jury);
    void setNumOfMembers(int numOfMembers);

public:
    Jury(JuryMember** allJuryMembers, int numOfMembers, int maxNumOfMembers = DEFAULT_MAX_NUM_OF_JURY_MEMBERS) throw(int,const char*);// maxNumOfMembers must be a non-zero positive, "allJuryMembers" cannot be a nullptr
    ~Jury();

    void setJuryMembers(JuryMember** allJuryMembers, int numOfMembers) throw(const char*);

    inline int getNumOfJuryMembers() const;

    void addJuryMember(JuryMember* juryMember) throw(const char*); //throws a message if "juryMember" is a nullptr or maxNumOfMembers already exceeded
    bool removeJuryMember(int id) throw(const char*);

    const JuryMember& operator[](int index) const throw(const char*);
    JuryMember& operator[](int index) throw(const char*);

	bool operator==(const Jury& other) const;
    friend ostream& operator<<(ostream& os, const Jury& jury);
};
#endif