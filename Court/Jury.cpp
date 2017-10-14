#include "Jury.h"
#include "JuryMember.h"

Jury::Jury(JuryMember** allJuryMembers, int numOfMembers, int maxNumOfMembers) throw(const char*) :
allJuryMembers(nullptr)
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
	for(int i = 0; i < numOfMembers; i++)
	{
		delete allJuryMembers[i];
	}

	delete []allJuryMembers;
}

void Jury::deleteMembers()
{
	for(int i = 0; i < numOfMembers; i++)
	{
		delete allJuryMembers[i];
	}

	delete []allJuryMembers;
}

void Jury::setJuryMembers(JuryMember** allJuryMembers, int numOfMembers) throw(const char*)
{
	if(allJuryMembers != nullptr)
	{
		if(numOfMembers > 0 )
		{
			if(numOfMembers <= this->maxNumOfMembers)
			{
				if(this->allJuryMembers != nullptr)
				{
					for(int i = 0; i < this->numOfMembers; i++)
					{
						delete allJuryMembers[i];
					}
				}

				delete []this->allJuryMembers;

				this->allJuryMembers = allJuryMembers;
				this->numOfMembers = numOfMembers;
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
	return numOfMembers;
}

void Jury::addJuryMember(JuryMember* juryMember) throw(const char*)
{
	if(juryMember == nullptr)
	{
		throw("Adding null juryMember not allowed (in Jury)");
	}
	else
	{
		if(this->numOfMembers + 1 <= maxNumOfMembers)
		{
			this->allJuryMembers[this->numOfMembers] = juryMember;
			++this->numOfMembers;
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

	for(int i = 0; i < numOfMembers; i++)
	{
		if( allJuryMembers[i]->getId() == id)
		{
			delete allJuryMembers[i];
			
			// Shifting all members one place left
			for(int j = i; j < numOfMembers - 1; j ++)
			{
				allJuryMembers[i] = allJuryMembers[i + 1];
			}
			
			--numOfMembers;

			isRemoved = true;
		}
	}

	if(!isRemoved)
	{
		throw("Jury does not contain JuryMember (while removing jury)");
	}

	return isRemoved;
}

const JuryMember& Jury::operator[](int index) const throw(const char*)
{
	if(index >=0 && index < numOfMembers)
	{
		return *allJuryMembers[index];
	}
	else
	{
		throw("Array index out of range (inside jury, operator [])");
	}
}

JuryMember& Jury::operator[](int index) throw(const char*)
{
	if(index >=0 && index < numOfMembers)
	{
		return *allJuryMembers[index];
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
		this->numOfMembers == numOfMembers)
	{
		for(int i = 0; i < numOfMembers; i++)
		{
			if( allJuryMembers[i] != other.allJuryMembers[i])
			{
				isEqual = false;
			}
		}
	}
	else
	{
		isEqual = false;
	}

	return isEqual;
}

ostream& operator<<(ostream& os, const Jury& jury)
{
	os << "Jury: ";
	
	if(jury.numOfMembers == 0)
	{
		os << "No members";
	}
	else
	{
		os << endl;
		for(int i = 0; i < jury.numOfMembers; i++)
		{
			os << *jury.allJuryMembers[i] << endl;
		}
	}

	return os;
}