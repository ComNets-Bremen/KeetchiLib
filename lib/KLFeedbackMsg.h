/**
* Feedback message data
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLFeedbackMsg_H
#define KLFeedbackMsg_H

#include <string>
#include "KLTypes.h"

using namespace std;

class KLFeedbackMsg
{
	public:
		KLFeedbackMsg(void);
		~KLFeedbackMsg(void);
		
		// getters & setters
		int getMsgDirection() {return msgDirection; }
		int getFromWhere() {return fromWhere; }
		int getToWhere() {return toWhere; }
		string getSourceAddress() {return sourceAddress; }
		string getDestinationAddress() {return destinationAddress; }
		string getDataName() {return dataName; }
		int getGoodnessValue() {return goodnessValue; }
		
		void setMsgDirection(int md) {msgDirection = md; }
		void setFromWhere(int fw) {fromWhere = fw; }
		void setToWhere(int tw) {toWhere = tw; }
		void setSourceAddress(string s) {sourceAddress = s; }
		void setDestinationAddress(string s) {destinationAddress = s; }
		void setDataName(string s) {dataName = s; }
		void setGoodnessValue(int gv) {goodnessValue = gv; }

	private:
		int msgDirection;
		int fromWhere;
		int toWhere;
		string sourceAddress;
		string destinationAddress;
		
		string dataName;
		int goodnessValue;

};

#endif

