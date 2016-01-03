/**
* Main class that is instantiated by the Keetchi layer of every node to perform
* all Keetchi related activities. There should only be one instance of these 
* objects per node.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLKeetchi_H
#define KLKeetchi_H

#include <list>
#include <string>

#include "KLTypes.h"
#include "KLAction.h"
#include "KLNodeInfo.h"
#include "KLFeedbackMsg.h"
#include "KLDataMsg.h"
#include "KLDataMgr.h"
#include "KLCacheEntry.h"
#include "KLAppInfo.h"
#include "KLCommMgr.h"
#include "KLResourceMgr.h"

using namespace std;

class KLKeetchi
{
	public:
		KLKeetchi(int cachePolicy, int cacheSize, string ownAddr);
		~KLKeetchi(void);
		
		int registerApplication(string appName, string prefixName, double currentTime);
		int deregisterApplication(string appName, double currentTime);
		KLAction* processFeedbackMsg(int fromWhere, KLFeedbackMsg *feedbackMsg, double currentTime);
		KLAction* processDataMsg(int fromWhere, KLDataMsg *dataMsg, double currentTime);
		list<KLAction*> processNewNeighbourList(list<KLNodeInfo*> nodeInfoList, double currentTime);
		int ageData(double currentTime);
		
	private:
		int maxCacheSize;
		int cacheReplacementPolicy;
		string ownAddress;
		
		KLDataMgr *dataMgr;
		KLCommMgr *commMgr;
		KLResourceMgr *resourceMgr;
		list<KLAppInfo*> registeredAppInfoList;

};

#endif
