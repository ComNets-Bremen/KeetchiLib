/**
* Data message contents
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLDataMsg_H
#define KLDataMsg_H

#include <string>
#include <cstdlib>

#include "KLTypes.h"

using namespace std;

class KLDataMsg
{
	public:
		KLDataMsg(void);
		~KLDataMsg(void);

		// getters
		int getMsgDirection() {return msgDirection; }
		int getFromWhere() {return fromWhere; }
		int getToWhere() {return toWhere; }
		string getSourceAddress() {return sourceAddress; }
		string getDestinationAddress() {return destinationAddress; }
		string getDataName() {return dataName; }
		char *getDataPayload() {return dataPayload; }
		int getDataPayloadSize() {return dataPayloadSize; }
		int getGoodnessValue() {return goodnessValue; }
	
		// setters
		void setMsgDirection(int md) {msgDirection = md; }
		void setFromWhere(int fw) {fromWhere = fw; }
		void setToWhere(int tw) {toWhere = tw; }
		void setSourceAddress(string s) {sourceAddress = s; }
		void setDestinationAddress(string s) {destinationAddress = s; }
		void setDataName(string s) {dataName = s; }
		void setDataPayload(char *d, int ds) {if (d == NULL || ds == 0) {
												dataPayload = NULL;
												dataPayloadSize = 0;
											  } else {
												dataPayload = (char *)malloc(ds); 
												memcpy(dataPayload, d, ds);
												dataPayloadSize = ds;
											  }
											}
		void setGoodnessValue(int gv) {goodnessValue = gv; }
		
		
	private:
		// check KLTypes to get values for the variables below
		int msgDirection;
		int fromWhere;
		int toWhere;
		string sourceAddress;
		string destinationAddress;
		
		string dataName;
		char *dataPayload;
		int dataPayloadSize;
		
		int goodnessValue;

};


#endif

