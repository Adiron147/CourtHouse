#include "CourtHouse.h"
#include "Judge.h"




CourtHouse::CourtHouse(const char* state, const char* city, const char* name, int numOfCourtRooms = 1) throw(int)
{
	setState(state);
	setCity(city);
	setName(name);
	this->numOfCourtRooms = numOfCourtRooms;
	this->numOfJudges = 0;
	CourtRoom* allCourtRooms =  new CourtRoom[this->numOfCourtRooms];
	Judge** allJudges = new Judge*[this->numOfJudges];
}


void CourtHouse::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void CourtHouse::setNumOfCourtRooms(int num)
{
	this->numOfCourtRooms = num;
}

void CourtHouse::setNumOfJudges(int numOfJudges)
{
	this->numOfJudges = numOfJudges;
}



CourtHouse::CourtHouse(const CourtHouse& otherCourtHouse)
{
	this->state = new char[strlen(otherCourtHouse.getState()) + 1];
	this->city = new char[strlen(otherCourtHouse.getCity()) + 1];
	this->name = new char[strlen(otherCourtHouse.getName()) + 1];

	strcpy(this->state, otherCourtHouse.getState());
	strcpy(this->city, otherCourtHouse.getCity());
	strcpy(this->name, otherCourtHouse.getName());

	CourtRoom* allCourtRooms = new CourtRoom[otherCourtHouse.getNumOfCourtRooms()];
	Judge** allJudges = new Judge*[otherCourtHouse.getNumOfJudges()];
	for (int i = 0; i < otherCourtHouse.getNumOfCourtRooms(); i++)
	{
		this->allCourtRooms[i] = otherCourtHouse.getAllCourtRooms()[i];
	}
	for (int i = 0; i < otherCourtHouse.getNumOfJudges(); i++)
	{
		this->allJudges[i]= otherCourtHouse.getAllJudges[i];
	}


}

CourtHouse::~CourtHouse()
{
	delete[] this->state;
	delete[] this->city;
	delete[] this->name;
}

void CourtHouse::setState(const char* state)
{
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, state);
}


inline char* CourtHouse::getState() const
{
	return this->state;
}

void CourtHouse::setCity(const char* city)
{
	this->state = new char[strlen(city) + 1];
	strcpy(this->state, city);
}


inline char* CourtHouse::getCity() const
{
	return this->city;
}

inline char* CourtHouse::getName() const
{
	return this->name;
}


void CourtHouse::addJudge(Judge* judge) throw(const char*) //throws a message if "judge" is a nullptr or already in the court house system
{
	
	if (judge == nullptr)
	{
		throw "Judge can't be null";
	}
	else if (getJudgeByName(*(judge).getName()))
	{
		"Judge already exists in this courthouse!";
	}
	else {

		Judge** tempJudges = new Judge*[this->numOfJudges + 1];
		for (int i = 0; i < this->numOfJudges; i++)
		{
			tempJudges[i] = this->allJudges[i];
		}
		this->numOfJudges++;
		tempJudges[this->numOfJudges] = judge;

		this->allJudges = new Judge*[this->numOfJudges];
		for (int i = 0; i < this->numOfJudges; i++)
		{
			this->allJudges = &tempJudges[i];
		}
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

Judge** CourtHouse::getAllJudges()
{
	return this->allJudges;
}

const Judge** CourtHouse::getAllJudges() const
{
	return this->allJudges;
}
const Judge* CourtHouse::getJudgeByName(const char* name) const
{
	for (int i = 0; i < sizeof(this->getAllJudges) / sizeof(*this->.getAllJudges()[0]); i++)
	{
		if (strcmp(this->getAllJudges()[i].getName(), name) == 0)
		{
			return this->getAllJudges()[i];
		}
	}
}
Judge* CourtHouse::getJudgeByName(const char* name)
{
	for (int i = 0; i < sizeof(this->getAllJudges) / sizeof(*this->.getAllJudges()[0]); i++)
	{
		if (strcmp(this->getAllJudges()[i].getName(),name) == 0)
		{
			return this->getAllJudges()[i];
		}
	}
}

inline const CourtRoom* CourtHouse::getAllCourtRooms() const
{
	return this->allCourtRooms;
}
void CourtHouse::addCourtRoom(const CourtRoom& room) throw(const char*) //throws a message if the addition is inccorrect (when trying to add while the numOfCourtRooms already exceeded)
{
	if (sizeof(this->allCourtRooms) == this->numOfCourtRooms)
	{
		throw "Judge can't be null";
	}
	else
	{
		CourtRoom tempCourtRooms= new CourtRoom[this->numOfCourtRooms + 1];
		for (int i = 0; i < this->numOfCourtRooms; i++)
		{
			tempCourtRooms[i] = this->allCourtRooms[i];
		}
		this->numOfCourtRooms++;
		tempCourtRooms[this->numOfCourtRooms] = room;

		this->allCourtRooms = new Judge*[this->numOfCourtRooms];
		for (int i = 0; i < this->numOfCourtRooms; i++)
		{
			this->allCourtRooms = tempCourtRooms[i];
		}
	}
}
const CourtHouse& CourtHouse::operator=(const CourtHouse& otherCourtHouse)
{
	state = new char[strlen(otherCourtHouse.getState()) + 1];
	city = new char[strlen(otherCourtHouse.getCity()) + 1];
	name = new char[strlen(otherCourtHouse.getName()) + 1];

	strcpy(state, otherCourtHouse.getState());
	strcpy(city, otherCourtHouse.getCity());
	strcpy(name, otherCourtHouse.getName());


	CourtRoom* allCourtRooms = new CourtRoom[otherCourtHouse.getNumOfCourtRooms()];
	Judge** allJudges = new Judge*[otherCourtHouse.getNumOfJudges()];
	for (int i = 0; i < otherCourtHouse.getNumOfCourtRooms(); i++)
	{
		this->allCourtRooms[i] = otherCourtHouse.getAllCourtRooms()[i];
	}
	for (int i = 0; i < otherCourtHouse.getNumOfJudges(); i++)
	{
		this->allJudges[i] = otherCourtHouse.getAllJudges[i];
	}
}
ostream& operator<<(ostream& os, const CourtHouse& court)
{
	os << "CourtHouse Name: " << court.getName() << ", CourtHouse State: " << court.getState() << ", CourtHouse City: " << court.getCity() << ", Rooms In CourtHouse:  " << court.getNumOfCourtRooms()
		<< ", Judges In CourtHouse:  " << court.getNumOfJudges() << "CourtHouse Rooms: ";
	for (int i = 0; i < sizeof(court.getAllCourtRooms())/sizeof(*court.getAllCourtRooms()[0]); i++)
	{
		os += court.getAllCourtRooms()[i].toOs();
	}

	os << "CourtHouse Judges: ";
	for (int i = 0; i < sizeof(court.getAllJudges) / sizeof(*court.getAllJudges()[0]); i++)
	{
		os += court.getAllJudges()[i].toOs();
	}

}
CourtRoom& CourtHouse::operator[](int index) throw(int)
{
	if (index >= 0 && index < this->numOfCourtRooms)
	{
		return &(this->allCourtRooms[index]);
	}
	else
	{
		throw("Wrong court room index (in CourtHouse operator[])");
	}
}
const CourtRoom& CourtHouse::operator[](int index) const throw(int)
{
	if (index >= 0 && index < this->numOfCourtRooms)
	{
		return &(this->allCourtRooms[index]);
	}
	else
	{
		throw("Wrongcourt room index (in CourtHouse operator[])");
	}
}

