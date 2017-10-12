#include "TmUtilities.h"

bool TmUtilities::doesColide(const tm& firstStart, const tm& firstEnd, const tm& secondStart, const tm& secondEnd)
{
	// Assuming not coliding
	bool result = false;

	if(compareTimes(secondStart, firstStart) == TmUtilities::FIRST_LARGER || 
		compareTimes(secondStart, firstStart) == TmUtilities::EQUALS)
	{
		if(compareTimes(secondStart, firstEnd) == TmUtilities::SECOND_LARGER)
		{
			result = true;
		}
	}
	else
	{
		if(compareTimes(firstStart, secondEnd) == TmUtilities::SECOND_LARGER)
		{
			result = true;
		}
	}

	return result;
}

bool TmUtilities::isEquals(const tm& first, const tm& second)
{
	return compareTimes(first,second) == TmUtilities::EQUALS;
}

void TmUtilities::tmToOs(ostream& os, const tm& time)
{
	os << time.tm_mday << "." << time.tm_mon << "." << time.tm_year << "  ";
	if(time.tm_hour < 10)
	{
		os << "0";
	}

	os << time.tm_hour << ":" << "00";
}

// Comparing the two given times:
// 1. If the first time is later than the second, FIRST_LARGER will be returned.
// 2. If the second time is later than the first, SECOND_LARGER will be returned.
// 3. if both times are equal, EQUALS will be returned.
int TmUtilities::compareTimes(const tm& firstTm, const tm& secondTm)
{
	int firstDiffProperty, secondDiffProperty;
	// Assuming first larger
	int result = TmUtilities::FIRST_LARGER;

	// Checking if the two given times 
	// share the same year, month, day, hour
	// (if not filling firstNotEqualProperty, secondNotEqualProperty 
	// with the first not equal property):

	if(firstTm.tm_year == secondTm.tm_year)
	{
		if(firstTm.tm_mon == secondTm.tm_mon)
		{
			if(firstTm.tm_mday == secondTm.tm_mday)
			{
				if(firstTm.tm_hour == secondTm.tm_hour)
				{
					// All parameters are the same
					result = TmUtilities::EQUALS;
				}
				else
				{
					firstDiffProperty = firstTm.tm_hour;
					secondDiffProperty = secondTm.tm_hour;
				}
			}
			else
			{
				firstDiffProperty = firstTm.tm_mday;
				secondDiffProperty = secondTm.tm_mday;
			}
		}
		else
		{
			firstDiffProperty = firstTm.tm_mon;
			secondDiffProperty = secondTm.tm_mon;
		}
	}
	else
	{
		firstDiffProperty = firstTm.tm_year;
		secondDiffProperty = secondTm.tm_year;
	}

	// If the two times are not the same
	if(result != TmUtilities::EQUALS)
	{
		if(firstDiffProperty > secondDiffProperty)
		{
			result = TmUtilities::FIRST_LARGER;
		}
		else
		{
			result = TmUtilities::SECOND_LARGER;
		}
	}

	return result;
}