/**
* Manages the operations related to managing data including 
* the cache.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 12-Sept-2015
*
*/

#ifndef KLDataMgr_H
#define KLDataMgr_H

#include <string>
#include <list>

#include "KLTypes.h"
#include "KLCacheEntry.h"

using namespace std;

class KLDataMgr
{
	public:
		KLDataMgr(int cachePolicy, int cacheSize);
		~KLDataMgr(void);
		
		// getters
		int getCurrentCacheSize() {return currentCacheSize; }
		
		// operations
		KLCacheEntry* getCacheEntry(string dName, double cTime);
		int updateCacheEntry(string dName, char *dPayload, int dPayloadSize, int gValue, double cTime);
		int recomputeGoodnessValue(int curValue, int rcvdValue, double cTime);
		list<KLCacheEntry*> getCacheEntriesToSend(int changeSignificance, int resourceLimit, double cTime);

	private:
		list<KLCacheEntry*> cacheEntryList;
		int cacheReplacementPolicy;
		int maxCacheSize;
		
		int currentCacheSize;
		
	};

#endif
