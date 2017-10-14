#ifndef __COURT_ROOM_H
#define __COURT_ROOM_H

#include <iostream>
using namespace std;
#include <vector>

class Trial;

class CourtRoom
{

private:
	static int SERIAL_NUMBER; // to put in roomNumber
	static const int TRIAL_NOT_IN_COURT = -1;

	int roomNumber;
	vector<Trial*> allTrials;

	CourtRoom(const CourtRoom& courtRoom);
	
	Trial* getTrialByIndex(int index);
	const Trial* getTrialByIndex(int index) const;
	
	const CourtRoom& operator=(const CourtRoom& courtRoom);
public:
	CourtRoom();
	~CourtRoom();

	inline int getRoomNumber() const {return roomNumber;}
	// not allowing setRoomNumber because using the serial number

	inline int getNumOfTrials() const;
	// not allowing setNumOfTrials because need to be updated with the addTrial method

	void addTrial(Trial& trial) throw(const char*); //throws exception if the room isTaken(tm,tm)
	void removeTrial(int trialId) throw(const char*); //throws an exception if trialId doesn't exist
	bool isTaken(const tm& startTime, const tm& endTime) const;

	bool operator==(const CourtRoom& other) const;
	Trial& operator[](int index) throw(const char*);
	const Trial& operator[](int index) const throw(const char*);
	friend ostream& operator<<(ostream& os, const CourtRoom& courtRoom);
};

#endif