#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;

class Person
{

private:
    string name;
    int id;

	Person(const Person& other) throw(const char*);
	void setName(const string& name) throw(const char*);
    void setId(int id) throw(const char*);
	
	const Person& operator=(const Person& other);

public:
    Person(const string& name, int id) throw(const char*);

	inline const string& getName() const {return name;}

	inline int getId() const {return id;}

	bool operator==(const Person& other) const;
	friend ostream& operator<<(ostream& os, const Person& person);
	virtual void toOs(ostream& os) const = 0;

};
#endif
