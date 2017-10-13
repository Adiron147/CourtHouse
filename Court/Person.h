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
	void setName(const char* name) throw(const char*);
    void setId(int id) throw(const char*);
	
	const Person& operator=(const Person& other);

public:
    Person(const char* name, int id) throw(const char*);
    virtual ~Person();

	inline const char* getName() const {return name;}

	inline int getId() const {return id;}

	bool operator==(const Person& other) const;
	friend ostream& operator<<(ostream& os, const Person& person);
	virtual void toOs(ostream& os) const = 0;

};
#endif
