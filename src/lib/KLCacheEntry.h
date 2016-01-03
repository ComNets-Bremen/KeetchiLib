/**
* Holds a single cache entry. A cache entry contains the content of a 
* single Data message.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLCacheEntry_H
#define KLCacheEntry_H

#include <string>
#include <cstdlib>

#include "KLTypes.h"

using namespace std;

class KLCacheEntry
{
	public:
		KLCacheEntry(string dName, char *dPayload, int dPayloadSize, int gValue, double cTime);
		~KLCacheEntry(void);
	
		// getters
		string getDataName() {return dataName; }
		char *getDataPayload() {return dataPayload; }
		int getDataPayloadSize() {return dataPayloadSize; }
		int getGoodnessValue() {return goodnessValue; }
		double getCreatedTime() {return createdTime; }
		double getUpdatedTime() {return updatedTime; }
		double getLastAccessedTime() {return lastAccessedTime; }
	
		// setters
		void setDataName(string s) {dataName = s; }
		void setDataPayload(char *d, int ds) {dataPayload = (char *)malloc(ds); 
														memcpy(dataPayload, d, ds);
														dataPayloadSize = ds; }
		void setGoodnessValue(int gv) {goodnessValue = gv; }
		void setCreatedTime(double ct) {createdTime = ct; }
		void setUpdatedTime(double ut) {updatedTime = ut; }
		void setLastAccessedTime(double lat) {lastAccessedTime = lat; }

	private:
		string dataName;
		char *dataPayload;
		int dataPayloadSize;
		int goodnessValue;
		
		double createdTime;
		double updatedTime;
		double lastAccessedTime;

	};

#endif
