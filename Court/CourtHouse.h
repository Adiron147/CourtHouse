#pragma warning( disable : 4290 )
#ifndef __COURT_HOUSE_H
#define __COURT_HOUSE_H

#include <ostream>
using namespace std;

class CourtRoom;
class Judge;

class CourtHouse
{
	
private:
	char* state;
	char* city;
	char* name;
	size_t numOfCourtRooms; //positive integers
	size_t numOfJudges;
	CourtRoom* allCourtRooms;
	Judge** allJudges;

	CourtHouse(const CourtHouse& otherCourtHouse);
	void setName(const char* name) throw(const char*);
	const CourtHouse& operator=(const CourtHouse& otherCourtHouse);

public:
    //throws the number of court rooms if it is negative
	CourtHouse(const char* state, const char* city, const char* name, int numOfCourtRooms = 1) throw(const char*);
	~CourtHouse();

	void setState(const char* state) throw(const char*);
	inline const char* getState() const;

	void setCity(const char* city) throw(const char*);
	inline const char* getCity() const;

	inline const char* getName() const;

    void addJudge(Judge* judge) throw(const char*); //throws a message if "judge" is a nullptr or already in the court house system
    Judge** getAllJudges();
	const Judge*const* getAllJudges() const { return allJudges;}
	const Judge* getJudgeByName(const char* name) const ;
    Judge* getJudgeByName(const char* name);
    inline int getNumOfJudges() const;

	inline int getNumOfCourtRooms() const {return numOfCourtRooms;}

	friend ostream& operator<<(ostream& os, const CourtHouse& court);
	CourtRoom& operator[](int index) throw(const char*);
	const CourtRoom& operator[](int index) const throw(const char*);
};
#endif