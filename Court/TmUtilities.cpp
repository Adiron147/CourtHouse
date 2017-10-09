#include "TmUtilities.h"
#include <stdlib.h>
#include <string.h>

bool TmUtilities::doesColide(const tm& firstStart, const tm& firstEnd, const tm& secondStart, const tm& secondEnd)
{
	// Assuming not coliding
	bool result = false;

	tm *firstStartCloned = cloneTm(firstStart);
	tm *secondStartCloned = cloneTm(secondStart);
	tm *firstEndCloned = cloneTm(firstEnd);
	tm *secondEndCloned = cloneTm(secondEnd);

	time_t firstStartTime = mktime(firstStartCloned);
	time_t secondStartTime = mktime(secondStartCloned);
	time_t firstEndTime = mktime(firstEndCloned);
	time_t secondEndTime = mktime(secondEndCloned);

	if(difftime(secondStartTime, firstStartTime) >= 0)
	{
		if(difftime(secondStartTime, firstEndTime) < 0)
		{
			result = true;
		}
	}
	else
	{
		if(difftime(firstStartTime, secondEndTime) < 0)
		{
			result = true;
		}
	}

	free(firstStartCloned );
	free(secondStartCloned);
	free(firstEndCloned);
	free(secondEndCloned);

	return result;
}

bool TmUtilities::isEquals(const tm& first, const tm& second)
{
	return memcmp(&first, &second, sizeof(tm)) == 0;
}

void TmUtilities::tmToOs(ostream& os, const tm& time)
{
	char *tmAsStr = asctime(&time);
	os << tmAsStr;

	delete []tmAsStr;
}

tm* TmUtilities::cloneTm(const tm& toClone)
{
	tm *cloned = (tm*)malloc(sizeof(tm));

	memcpy(cloned,&toClone,sizeof(tm));

	return cloned;
}