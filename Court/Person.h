
#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;

class Person
{

private:
    char* name;
    int id;

	Person(const Person& other);
	void setName(const char* name);
    void setId(int id) throw(char*);
	
	virtual const Person& operator=(const Person& other);

public:
    Person(const char* name, int id) throw(char*);
    virtual ~Person();

	inline const char* getName() const;

	inline int getId() const;

	bool operator==(const Person& other) const;
	friend ostream& operator<<(ostream& os, const Person& person);
	virtual void toOs(ostream& os) const;

};
#endif
