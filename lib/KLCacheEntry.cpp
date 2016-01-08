/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#include "KLCacheEntry.h"

KLCacheEntry::KLCacheEntry(string dName, char *dPayload, int dPayloadSize, int gValue, double cTime)
{
	dataName = dName;
	dataPayload = (char *) malloc(dPayloadSize);
	memcpy(dataPayload, dPayload, dPayloadSize);
	dataPayloadSize = dPayloadSize;
	goodnessValue = gValue;
	
	createdTime = cTime;
	updatedTime = cTime;
	lastAccessedTime = cTime;
	
}

KLCacheEntry::~KLCacheEntry(void)
{
	free(dataPayload);
}

KLCacheEntry* KLCacheEntry::makeCopy(void)
{
	KLCacheEntry* copiedCacheEntry;
	
	copiedCacheEntry = new KLCacheEntry(dataName, dataPayload, dataPayloadSize, goodnessValue, createdTime);
	copiedCacheEntry->setCreatedTime(createdTime);
	copiedCacheEntry->setUpdatedTime(updatedTime);
	copiedCacheEntry->setLastAccessedTime(lastAccessedTime);
	
	
	return copiedCacheEntry;
}
