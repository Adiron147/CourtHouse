#pragma warning( disable : 4290 )
#ifndef __COURT_HOUSE_H
#define __COURT_HOUSE_H

#include <ostream>
using namespace std;
#include <vector>

class CourtRoom;
class Judge;

class CourtHouse
{
	
private:
	static CourtHouse theCourtHouse;

	size_t numOfCourtRooms; //positive integers
	CourtRoom* allCourtRooms;
	vector<Judge*> allJudges;

	CourtHouse();

	CourtHouse(const CourtHouse& otherCourtHouse);
	void setName(const char* name) throw(const char*);
	const CourtHouse& operator=(const CourtHouse& otherCourtHouse);

public:
	static CourtHouse* getInstance();

    //throws the number of court rooms if it is negative
	~CourtHouse();

    void addJudge(Judge* judge) throw(const char*); //throws a message if "judge" is a nullptr or already in the court house system
	const vector<Judge*> getAllJudges() const { return allJudges;}
	const Judge* getJudgeByName(const string& name) const ;
    Judge* getJudgeByName(const string& name);
    inline int getNumOfJudges() const;
	// Should be called only once, Exception otherwise
	void setNumberOfCourtRooms(int numOfCourtRooms) throw (const char*);

	inline int getNumOfCourtRooms() const {return numOfCourtRooms;}

	friend ostream& operator<<(ostream& os, const CourtHouse& court);
	CourtRoom& operator[](int index) throw(const char*);
	const CourtRoom& operator[](int index) const throw(const char*);
};
#endif