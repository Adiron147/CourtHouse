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
	void setName(const char* name);
	void setNumOfCourtRooms(int num);
	void setNumOfJudges(int numOfJudges);

public:
    //throws the number of court rooms if it is negative
	CourtHouse(const char* state, const char* city, const char* name, int numOfCourtRooms = 1) throw(int);
	~CourtHouse();

	void setState(const char* state);
	inline char* getState() const;

	void setCity(const char* city);
	inline char* getCity() const;

	inline char* getName() const;

    void addJudge(Judge* judge) throw(const char*); //throws a message if "judge" is a nullptr or already in the court house system
    Judge** getAllJudges();
	const Judge** getAllJudges() const ;
	const Judge* getJudgeByName(const char* name) const ;
    Judge* getJudgeByName(const char* name);
    inline int getNumOfJudges() const;

    inline int getNumOfCourtRooms() const;
	inline const CourtRoom* getAllCourtRooms() const;
    void addCourtRoom(const CourtRoom& room) throw(const char*); //throws a message if the addition is inccorrect (when trying to add while the numOfCourtRooms already exceeded)

	const CourtHouse& operator=(const CourtHouse& otherCourtHouse);
	friend ostream& operator<<(ostream& os, const CourtHouse& court);
	CourtRoom& operator[](int index) throw(int);
	const CourtRoom& operator[](int index) const throw(int);

};
#endif