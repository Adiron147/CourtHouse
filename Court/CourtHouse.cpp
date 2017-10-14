#include "CourtHouse.h"
#include "Judge.h"
#include "CourtRoom.h"

CourtHouse CourtHouse::theCourtHouse;

CourtHouse* CourtHouse::getInstance()
{
	return &theCourtHouse;
}

CourtHouse::CourtHouse() throw(const char*) : allCourtRooms(nullptr), numOfCourtRooms(0){}

CourtHouse::~CourtHouse()
{
	vector<Judge*>::iterator  itr    = this->allJudges.begin();
	vector<Judge*>::iterator  itrEnd = this->allJudges.end();

	for ( ; itr != itrEnd; ++itr)
	{
		delete (*itr);
	}
	
	delete []allCourtRooms;
}

void CourtHouse::setNumberOfCourtRooms(int numOfCourtRooms) throw (const char*)
{
	if(numOfCourtRooms < 0)
	{
		throw("Number of court rooms must be a positive number");
	}
	else
	{
		// Checking if this method was already called
		if(this->allCourtRooms == nullptr)
		{
			this->numOfCourtRooms = numOfCourtRooms;
			this->allCourtRooms = new CourtRoom[numOfCourtRooms];
		}
		else
		{
			throw("CourtHouse setNumberOfCourtRooms was called more than once!");
		}
	}
}

const Judge* CourtHouse::getJudgeByName(const string& name) const
{
	const Judge* foundJudge = nullptr;

	vector<Judge*>::const_iterator  itr    = this->allJudges.begin();
	vector<Judge*>::const_iterator  itrEnd = this->allJudges.end();

	for ( ; itr != itrEnd; ++itr)
	{
		if((*itr)->getName().compare(name) == 0)
		{
			foundJudge = *itr;
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
		this->allJudges.push_back(judge);
	}
}

inline int CourtHouse::getNumOfJudges() const
{
	return this->allJudges.size();
}

ostream& operator<<(ostream& os, const CourtHouse& court)
{
	os << "CourtHouse " << ", Rooms In CourtHouse:  " << court.getNumOfCourtRooms()
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
	if(court.getNumOfJudges()  == 0)
	{
		os << "none yet" << endl;
	}
	else
	{
		vector<Judge*>::const_iterator  itr    = court.allJudges.begin();
		vector<Judge*>::const_iterator  itrEnd = court.allJudges.end();

		for ( ; itr != itrEnd; ++itr)
		{
			os << *(*itr);
		}
	}
	return os;
}

Judge* CourtHouse::getJudgeByName(const string& name)
{
	Judge* foundJudge = nullptr;

	vector<Judge*>::iterator  itr    = this->allJudges.begin();
	vector<Judge*>::iterator  itrEnd = this->allJudges.end();

	for ( ; itr != itrEnd; ++itr)
	{
		if((*itr)->getName().compare(name) == 0)
		{
			foundJudge = *itr;
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

