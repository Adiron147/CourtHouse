#include "CourtHouse.h"
#include "Judge.h"
#include "CourtRoom.h"

CourtHouse::CourtHouse(const char* state, const char* city, const char* name, int numOfCourtRooms) throw(const char*) : 
name(nullptr), city(nullptr), state(nullptr), allJudges(nullptr), allCourtRooms(nullptr)
{
	if(numOfCourtRooms < 0)
	{
		throw("Number of court rooms must be a positive number");
	}
	else
	{
		this->numOfCourtRooms = numOfCourtRooms;
		this->allCourtRooms = new CourtRoom[numOfCourtRooms];
	}

	try
	{
		setState(state);
		setCity(city);
		setName(name);
		this->numOfJudges = 0;
	}
	catch(const char* msg)
	{
		delete []this->state;
		delete []this->city;
		delete []this->name;
		delete []this->allCourtRooms;
		
		throw(msg);
	}
}

void CourtHouse::setName(const char* name) throw(const char*)
{
	delete []this->name;

	if(name == nullptr)
	{
		throw("Court name can not be null (setName)");
	}
	else
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

CourtHouse::~CourtHouse()
{
	delete[] this->state;
	delete[] this->city;
	delete[] this->name;

	for(size_t i = 0; i < numOfJudges; i ++)
	{
		delete allJudges[i];
	}

	delete []allJudges;

	delete []allCourtRooms;
}

void CourtHouse::setState(const char* state) throw(const char*)
{
	delete []this->state;

	if(state == nullptr)
	{
		throw("Court state can not be null (setState)");
	}
	else
	{
		this->state = new char[strlen(state) + 1];
		strcpy(this->state, state);
	}
}

inline const char* CourtHouse::getState() const
{
	return this->state;
}

void CourtHouse::setCity(const char* city) throw(const char*)
{
	delete []this->city;

	if(city == nullptr)
	{
		throw("Court city can not be null (setCity)");
	}
	else
	{
		this->city = new char[strlen(city) + 1];
		strcpy(this->city, city);
	}
}

inline const char* CourtHouse::getCity() const
{
	return this->city;
}

inline const char* CourtHouse::getName() const
{
	return this->name;
}

const Judge* CourtHouse::getJudgeByName(const char* name) const
{
	const Judge* foundJudge = nullptr;

	for (size_t i = 0; i < this->numOfJudges; i++)
	{
		if (strcmp(this->allJudges[i]->getName(), name) == 0)
		{
			foundJudge = this->allJudges[i];
		}
	}
	
	return foundJudge;
}

void CourtHouse::addJudge(Judge* judge) throw(const char*) //throws a message if "judge" is a nullptr or already in the court house system
{
	if (judge == nullptr)
	{
		throw "Judge can't be null";
	}
	else if (getJudgeByName((judge)->getName()) != nullptr)
	{
		throw "Judge already exists in this courthouse!";
	}
	else
	{
		Judge** enlargedJudges = new Judge*[this->numOfJudges + 1];
		for (size_t i = 0; i < this->numOfJudges; i++)
		{
			enlargedJudges[i] = this->allJudges[i];
		}
		
		enlargedJudges[this->numOfJudges] = judge;

		delete []allJudges;
		
		this->allJudges = enlargedJudges;

		++this->numOfJudges;
	}
}

inline int CourtHouse::getNumOfJudges() const
{
	return this->numOfJudges;
}

ostream& operator<<(ostream& os, const CourtHouse& court)
{
	os << "CourtHouse Name: " << court.getName() << ", CourtHouse State: " << court.getState() << ", CourtHouse City: " << court.getCity() << ", Rooms In CourtHouse:  " << court.getNumOfCourtRooms()
		<< ", Judges In CourtHouse:  " << court.getNumOfJudges() << "CourtHouse Rooms: ";
	if(court.numOfCourtRooms == 0)
	{
		os << "none yet" << endl;
	}
	else
	{
		for (size_t i = 0; i < court.numOfCourtRooms; i++)
		{
			os << court.allCourtRooms[i] << endl;
		}
	}

	os << "CourtHouse Judges: ";
	if(court.numOfJudges == 0)
	{
		os << "none yet" << endl;
	}
	else
	{
		for (size_t i = 0; i < court.numOfJudges; i++)
		{
			os << court.allJudges[i];
		}
	}
	return os;
}

Judge* CourtHouse::getJudgeByName(const char* name)
{
	Judge* foundJudge = nullptr;

	for (size_t i = 0; i < this->numOfJudges; i++)
	{
		if (strcmp(this->allJudges[i]->getName(), name) == 0)
		{
			foundJudge = this->allJudges[i];
		}
	}
	
	return foundJudge;
}

CourtRoom& CourtHouse::operator[](int index) throw(const char*)
{
	if (index >= 0 && (size_t)index < this->numOfCourtRooms)
	{
		return (this->allCourtRooms[index]);
	}
	else
	{
		throw("Wrong court room index (in CourtHouse operator[])");
	}
}
const CourtRoom& CourtHouse::operator[](int index) const throw(const char*)
{
	if (index >= 0 && (size_t)index < this->numOfCourtRooms)
	{
		return (this->allCourtRooms[index]);
	}
	else
	{
		throw("Wrong court room index (in CourtHouse operator[])");
	}
}

