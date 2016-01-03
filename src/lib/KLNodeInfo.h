/**
* Information of each node
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#ifndef KLNodeInfo_H
#define KLNodeInfo_H

#include <string>

#include "KLTypes.h"

using namespace std;
	
class KLNodeInfo
{
	public:
		KLNodeInfo(string nAddr);
		~KLNodeInfo(void);

		string getNodeAddress() {return nodeAddress; }

	private:
		string nodeAddress;

};

#endif
