#include "Jury.h"
#include "JuryMember.h"

Jury::Jury(JuryMember** allJuryMembers, int numOfMembers, int maxNumOfMembers) throw(const char*)
{
	if(maxNumOfMembers > 0)
	{
		this->maxNumOfMembers = maxNumOfMembers;
		
		setJuryMembers(allJuryMembers, numOfMembers);
	}
	else
	{
		throw("The number of maximum jury members has to be larger than 0!");
	}
}// maxNumOfMembers must be a non-zero positive, "allJuryMembers" cannot be a nullptr

Jury::~Jury()
{
	deleteMembers();
}

void Jury::deleteMembers()
{
	vector<JuryMember*>::iterator  itr    = allJuryMembers.begin();
	vector<JuryMember*>::iterator  itrEnd = allJuryMembers.end();
	
	for ( ; itr != itrEnd; ++itr)
	{
	    delete *itr;
	}
}

JuryMember* Jury::getMemberByIndex(int index)
{
	vector<JuryMember*>::iterator  itr    = this->allJuryMembers.begin();
	vector<JuryMember*>::iterator  itrEnd = this->allJuryMembers.end();

	for(int i = 0; itr != itrEnd && i < index; ++i, ++itr );

	return *itr;
}

void Jury::setJuryMembers(JuryMember** allJuryMembers, int numOfMembers) throw(const char*)
{
	if(allJuryMembers != nullptr)
	{
		if(numOfMembers > 0 )
		{
			if(numOfMembers <= this->maxNumOfMembers)
			{
				deleteMembers();

				this->allJuryMembers.clear();
				for(int i = 0; i < numOfMembers; i++)
				{
					this->allJuryMembers.push_back(allJuryMembers[i]);
				}
			}
			else
			{
				throw("The number of jury members has exceed the maximum allowed!");
			}
		}
		else
		{
			throw("The number of members in the jury must be positive!");
		}
	}
	else
	{
		throw("Jury members array must not be null!");
	}
}

inline int Jury::getNumOfJuryMembers() const
{
	return allJuryMembers.size();
}

void Jury::addJuryMember(JuryMember* juryMember) throw(const char*)
{
	if(juryMember == nullptr)
	{
		throw("Adding null juryMember not allowed (in Jury)");
	}
	else
	{
		if(this->getNumOfJuryMembers() + 1 <= maxNumOfMembers)
		{
			this->allJuryMembers.push_back(juryMember);
		}
		else
		{
			throw("Adding juryMember not allowed (maxNumOfMembers exceeded, in Jury)");
		}
	}
}//throws a message if "juryMember" is a nullptr or maxNumOfMembers already exceeded

bool Jury::removeJuryMember(int id) throw(const char*)
{
	bool isRemoved = false;

	vector<JuryMember*>::iterator  itr    = allJuryMembers.begin();
	vector<JuryMember*>::iterator  itrEnd = allJuryMembers.end();
	
	for ( ; itr != itrEnd; ++itr)
	{
		if((*itr)->getId() == id)
		{
			delete *itr;
			allJuryMembers.erase(itr);
			isRemoved = true;
		}
	}

	// Checking if the trial is in the court
	if(!isRemoved)
	{
		throw("Jury does not conatin JuryMember (while removing jury)");
	}
	
	return isRemoved;
}

const JuryMember& Jury::operator[](int index) const throw(const char*)
{
	if(index >=0 && index < getNumOfJuryMembers())
	{
		return *getMemberByIndex(index);
	}
	else
	{
		throw("Array index out of range (inside jury, operator [])");
	}
}

JuryMember& Jury::operator[](int index) throw(const char*)
{
	if(index >=0 && index < getNumOfJuryMembers())
	{
		return *getMemberByIndex(index);
	}
	else
	{
		throw("Array index out of range (inside jury, operator [])");
	}
}

bool Jury::operator==(const Jury& other) const
{
	bool isEqual = true;

	if(this->maxNumOfMembers == other.maxNumOfMembers &&
		this->getNumOfJuryMembers() == getNumOfJuryMembers() &&
		this->allJuryMembers == other.allJuryMembers)
	{
		isEqual = false;
	}
	else
	{
		isEqual = false;
	}

	return isEqual;
}

const JuryMember* Jury::getMemberByIndex(int index) const
{
	vector<JuryMember*>::const_iterator  itr    = this->allJuryMembers.begin();
	vector<JuryMember*>::const_iterator  itrEnd = this->allJuryMembers.end();

	for(int i = 0; itr != itrEnd && i < index; ++i, ++itr );

	return *itr;
}

ostream& operator<<(ostream& os, const Jury& jury)
{
	os << "Jury: ";
	
	if(jury.getNumOfJuryMembers() == 0)
	{
		os << "No members";
	}
	else
	{
		os << endl;
		vector<JuryMember*>::const_iterator  itr    = jury.allJuryMembers.begin();
		vector<JuryMember*>::const_iterator  itrEnd = jury.allJuryMembers.end();
	
		for ( ; itr != itrEnd; ++itr)
		{
			os << *(*itr) << endl;
		}
	}

	return os;
}