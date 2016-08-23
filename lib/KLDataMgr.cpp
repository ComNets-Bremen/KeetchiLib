/******************************************************************************
 * Keetchi - A library for opportunistic communications.
 *
 * Copyright (C) 2016, Communication Networks, University of Bremen, Germany
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 * This file is part of the Keetchi library
 *
 ******************************************************************************/

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
	
	srand(128);
	
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
											foundCacheEntry->getGoodnessValue(), 
											foundCacheEntry->getDataType(), foundCacheEntry->getValidUntilTime(), 
											cTime);
		foundCacheEntry->setLastAccessedTime(cTime);	
	}
	
	return copiedCacheEntry;
}

int KLDataMgr::updateCacheEntry(string dName, char *dPayload, int dPayloadSize, int gValue, int dType, double vuTime, double cTime)
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
										gValue, dType, vuTime, 
										cTime);
	
	// if the cache had a previous entry, remove the existing entry and set old time stamps
	if (found) {
		cacheEntryList.remove(foundCacheEntry);
		updatedCacheEntry->setCreatedTime(foundCacheEntry->getCreatedTime());
		updatedCacheEntry->setLastAccessedTime(foundCacheEntry->getLastAccessedTime());
		
		delete foundCacheEntry;
	}
	
	// search the cache to find where to insert the entry
	// i.e., ordered by goodness value
	KLCacheEntry *nextCacheEntry;
	iteratorCacheEntry = cacheEntryList.begin();
	while (iteratorCacheEntry != cacheEntryList.end()) {
		nextCacheEntry = *iteratorCacheEntry;
		if (updatedCacheEntry->getGoodnessValue() < nextCacheEntry->getGoodnessValue()) {
			break;
		}
		iteratorCacheEntry++;

	}

	// position found, so insert the entry at the position before 
	cacheEntryList.insert(iteratorCacheEntry, updatedCacheEntry);
	
	return 0;
}

int KLDataMgr::recomputeGoodnessValue(int curValue, int rcvdValue, double cTime)
{
	int newValue;
	
	// get simple average
	newValue = (curValue + rcvdValue) / 2;
	
	return newValue;
}

list<KLCacheEntry*> KLDataMgr::getCacheEntriesToSend(int changeSignificance, int resourceLimit, double cTime)
{
	list<KLCacheEntry*> returnCacheEntryList;
	int lowerHalfCount, upperHalfCount;
	int cacheEntryIndex;
	KLCacheEntry *selecedCacheEntry, *copiedCacheEntry;
	
	
	// cache is empty
	if (cacheEntryList.size() == 0) {
		cout << "entries: " << returnCacheEntryList.size() << " \n";
		return returnCacheEntryList;
	} 
	

	// TODO: consider resource limitations also
	
	// Here's how the entries are found
	// 1. cache is split into 2 halves in the middle
	//    a. upper half with higher goodness values
	//    b. lower half with lower goodness values
	// 2. if significant change, then pick one from upper half
	// 3. if non-significant change, then pick one from lower half 
	
	// split cache into 2
	lowerHalfCount = cacheEntryList.size() / 2;
	upperHalfCount = cacheEntryList.size() - lowerHalfCount;
	
	// select cache entries to send
	if (changeSignificance == KLKEETCHI_SIGNIFICANT_CHANGE && upperHalfCount > 0) {
		// select cached data entry randomly from upper half
		// only one entry is selected
		cacheEntryIndex = rand() % upperHalfCount;
		list<KLCacheEntry*>::iterator iteratorCacheEntry = cacheEntryList.begin();
		advance(iteratorCacheEntry, cacheEntryIndex);
		selecedCacheEntry = *iteratorCacheEntry;
		copiedCacheEntry = selecedCacheEntry->makeCopy();
		returnCacheEntryList.push_back(copiedCacheEntry);
		
	} else if (changeSignificance == KLKEETCHI_NO_CHANGE && lowerHalfCount > 0) {
		// select cached data entry randomly from lower half
		// only one entry is selected
		cacheEntryIndex = (rand() % lowerHalfCount) + upperHalfCount;
		list<KLCacheEntry*>::iterator iteratorCacheEntry = cacheEntryList.begin();
		advance(iteratorCacheEntry, cacheEntryIndex);
		selecedCacheEntry = *iteratorCacheEntry;
		copiedCacheEntry = selecedCacheEntry->makeCopy();
		returnCacheEntryList.push_back(copiedCacheEntry);
		
	}
	
	// cout << "-----" << "\n";
	// cout << "change: " << (changeSignificance == KLKEETCHI_NO_CHANGE ? "no change" : "sig change") << " \n";
	// cout << "send entries: " << returnCacheEntryList.size() << " \n";
	// cout << "cache entries: " << cacheEntryList.size() << " \n";
	// cout << "=====" << "\n";
	
	return returnCacheEntryList;
}
