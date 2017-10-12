#ifndef __TM_UTILITIES_H
#define __TM_UTILITIES_H

#include <ctime>
#include <iostream>
using namespace std;

// This class handles tm struct filled with only year, month, day, hour
class TmUtilities
{
public:
	static const int FIRST_LARGER = 1;
	static const int SECOND_LARGER = -1;
	static const int EQUALS = 0;

	static bool doesColide(const tm& firstStart, const tm& firstEnd, const tm& secondStart, const tm& secondEnd);
	static bool isEquals(const tm& first, const tm& second);
	static void tmToOs(ostream& os, const tm&);
	
	// Comparing the two given times:
	// 1. If the first time is later than the second, FIRST_LARGER will be returned.
	// 2. If the second time is later than the first, SECOND_LARGER will be returned.
	// 3. if both times are equal, EQUALS will be returned.
	static int TmUtilities::compareTimes(const tm& firstTm, const tm& secondTm);
private:
	TmUtilities() {};
};

#endif __TM_UTILITIES_H