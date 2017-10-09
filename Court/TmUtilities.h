#ifndef __TM_UTILITIES_H
#define __TM_UTILITIES_H

#include <ctime>
#include <iostream>
using namespace std;

class TmUtilities
{
public:
	static bool doesColide(const tm& firstStart, const tm& firstEnd, const tm& secondStart, const tm& secondEnd);
	static bool isEquals(const tm& first, const tm& second);
	static void tmToOs(ostream& os, const tm&);
private:
	TmUtilities() {};
	static tm* TmUtilities::cloneTm(const tm& toClone);
};

#endif __TM_UTILITIES_H