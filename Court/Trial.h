#ifndef __TRIAL_H
#define __TRIAL_H

#include <ctime>
#include <iostream>
using namespace std;

class Party;
class Jury;
class CourtRoom;
class Judge;

class Trial
{
public:
	static const int NUM_OF_TYPES = 8;
	enum eTrialSubject{CRIMINAL, YOUTH, CIVIL, PROPERTY, FAMILY, CLASS_ACTION, TRANSPORTATION, CONTRACTS};
	static const string strTrialSubject[];

private:
	static int ID;
	int trialId;
	tm startTime;
	tm endTime;
	eTrialSubject subject;
    Party* defense;
	Party* prosecution;
    CourtRoom* trialRoom;
    Judge* judge;
	Jury* jury;

	Trial(const Trial& other);
	void setSubject(eTrialSubject subject);
	void setDefense(Party& defense)  throw(const char*);
	void setProsecution(Party& prosecution)  throw(const char*);
	const Trial& operator=(Trial& other);

public:
    //judge shouldn't be busy, room shouldn't be taken and defense != prosecution
	Trial(eTrialSubject subject, Judge& judge, Party& defense, Party& prosecution,
		  CourtRoom& trialRoom, const tm& startTime, const tm& endTime) throw(const char*);
	~Trial();

	inline int getTrialId() const {return trialId;}

	void setStartTime(const tm& startTime) throw(const char*);
	inline const tm& getStartTime() const {return startTime;}

	void setEndTime(const tm& endTime) throw(const char*);
	inline const tm& getEndTime() const {return endTime;}

	eTrialSubject getSubject() const;

	inline const Party& getDefense() const;  

	const Party& getProsecution() const; 

	void setJury(Jury* jury); //jury == nullptr means no jury in trial
	inline const Jury* getJury() const;

	void setJudge(Judge* judge) throw(const char*);
	inline const Judge& getJudge() const;

	void setTrialRoom(CourtRoom& trialRoom) throw(const char*);
	inline const CourtRoom& getTrialRoom() const;

    inline bool hasJury() const;

	bool operator==(const Trial& other) const;
	bool operator!=(const Trial& other) const;
	friend ostream& operator<<(ostream& os, const Trial& trial);
};

#endif