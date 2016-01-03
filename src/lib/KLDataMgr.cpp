/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 12-Sept-2015
*
*/
#include "KLDataMgr.h"

KLDataMgr::KLDataMgr(int cachePolicy, int cacheSize)
{
	cacheReplacementPolicy = cachePolicy;
	maxCacheSize = cacheSize;
	currentCacheSize = 0;
	
}

KLDataMgr::~KLDataMgr(void)
{
	KLCacheEntry *foundCacheEntry;

	// remove all cache entries
	list<KLCacheEntry*>::iterator iteratorCacheEntry = cacheEntryList.begin();
	while (iteratorCacheEntry != cacheEntryList.end()) {
		foundCacheEntry = *iteratorCacheEntry;
		delete foundCacheEntry;
		iteratorCacheEntry++;
	}
	
	cacheEntryList.clear();
	
}

KLCacheEntry* KLDataMgr::getCacheEntry(string dName, double cTime)
{
	KLCacheEntry *foundCacheEntry = NULL, *copiedCacheEntry = NULL;
	
	// look for entry
	int found = FALSE;
	list<KLCacheEntry*>::iterator iteratorCacheEntry = cacheEntryList.begin();
	while (iteratorCacheEntry != cacheEntryList.end()) {
		if ((*iteratorCacheEntry)->getDataName() == dName) {
			foundCacheEntry = *iteratorCacheEntry;
			found = TRUE;
			break;
		}
		iteratorCacheEntry++;
	}
	
	// make a copy, if found, to return and update access time
	if (found) {
		copiedCacheEntry = new KLCacheEntry(foundCacheEntry->getDataName(), foundCacheEntry->getDataPayload(), 
											foundCacheEntry->getDataPayloadSize(), 
											foundCacheEntry->getGoodnessValue(), cTime);
		foundCacheEntry->setLastAccessedTime(cTime);	
	}
	
	return copiedCacheEntry;
}

int KLDataMgr::updateCacheEntry(string dName, char *dPayload, int dPayloadSize, int gValue, double cTime)
{
	KLCacheEntry *foundCacheEntry = NULL, *updatedCacheEntry = NULL;
	
	// look for entry
	int found = FALSE;
	list<KLCacheEntry*>::iterator iteratorCacheEntry = cacheEntryList.begin();
	while (iteratorCacheEntry != cacheEntryList.end()) {
		if ((*iteratorCacheEntry)->getDataName() == dName) {
			foundCacheEntry = *iteratorCacheEntry;
			found = TRUE;
			break;
		}
		iteratorCacheEntry++;
	}
	
	// create a cache entry with the new values
	updatedCacheEntry = new KLCacheEntry(dName, dPayload, 
										dPayloadSize, 
										gValue, cTime);
	
	// if the cache had a previous entry, remove the existing entry and set old time stamps
	if (found) {
		cacheEntryList.remove(foundCacheEntry);
		updatedCacheEntry->setCreatedTime(foundCacheEntry->getCreatedTime());
		updatedCacheEntry->setLastAccessedTime(foundCacheEntry->getLastAccessedTime());
		
		delete foundCacheEntry;
	}
	
	// add updated/created cache entry
	cacheEntryList.push_front(updatedCacheEntry);
	
	return 0;
}

int KLDataMgr::recomputeGoodnessValue(int curValue, int rcvdValue, double cTime)
{
	int newValue;
	
	newValue = (curValue + rcvdValue) / 2;
	
	return newValue;
}

list<KLCacheEntry*> KLDataMgr::getCacheEntriesToSend(int changeSignificance, int resourceLimit, double cTime)
{
	list<KLCacheEntry*> returnCacheEntryList;
	
	return returnCacheEntryList;
}
