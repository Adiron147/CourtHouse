#include "CourtHouse.h"
#include "Judge.h"
#include "CourtRoom.h"

CourtHouse::CourtHouse(const char* state, const char* city, const char* name, int maxNumOfCourtRooms) throw(const char*) : 
name(nullptr), city(nullptr), state(nullptr), allJudges(nullptr)
{
	setState(state);
	setCity(city);
	setName(name);
	this->numOfJudges = 0;

	// TODO:
	this->maxNumOfCourtRooms = maxNumOfCourtRooms;
	this->allCourtRooms = new CourtRoom*[maxNumOfCourtRooms];
}

void CourtHouse::setName(const char* name) throw(const char*)
{
	delete []name;

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

// TODO:
//void CourtHouse::setMaxNumOfCourtRooms(int num)
//{
//	this->maxNumOfCourtRooms = num;
//}

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

	for(size_t i = 0; i < numOfCourtRooms; i ++)
	{
		delete allCourtRooms[i];
	}

	delete []allCourtRooms;

	// TODO: delete court rooms?
}

void CourtHouse::setState(const char* state) throw(const char*)
{
	delete []state;

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
	delete []city;

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

inline int CourtHouse::getNumOfCourtRooms() const
{
	return this->numOfCourtRooms;
}

// TODO: delete? not safe...
Judge** CourtHouse::getAllJudges()
{
	return this->allJudges;
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

// TODO: 
void CourtHouse::addCourtRoom(CourtRoom& room) throw(const char*) //throws a message if the addition is inccorrect (when trying to add while the numOfCourtRooms already exceeded)
{
	if (this->numOfCourtRooms + 1 > this->maxNumOfCourtRooms)
	{
		throw "Maximum number of court rooms has already been added to the court house";
	}
	else
	{
		this->allCourtRooms[this->numOfCourtRooms] = &room;
		++this->numOfCourtRooms;
	}
}

bool CourtHouse::removeCourtRoom(int roomNumber)
{
	bool isFound;
	for (int i = 0; i < numOfCourtRooms; i++)
	{
		if(allCourtRooms[i]->getRoomNumber() == roomNumber)
		{
			isFound = true;
			for(int j = i; j < numOfCourtRooms - 1; j++)
			{
				allCourtRooms[i] = allCourtRooms[i+1];
			}
			--numOfCourtRooms;
			break;
		}
	}

	return isFound;
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
		for (int i = 0; i < court.numOfCourtRooms; i++)
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
CourtRoom& CourtHouse::operator[](int index) throw(const char*)
{
	if (index >= 0 && (size_t)index < this->numOfCourtRooms)
	{
		return *(this->allCourtRooms[index]);
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
		return *(this->allCourtRooms[index]);
	}
	else
	{
		throw("Wrong court room index (in CourtHouse operator[])");
	}
}

