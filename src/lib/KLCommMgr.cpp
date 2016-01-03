/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 16-Sept-2015
*
*/
#include "KLCommMgr.h"

KLCommMgr::KLCommMgr(void)
{

}

KLCommMgr::~KLCommMgr(void)
{
	
}

int KLCommMgr::determineChangeSignificance(const list<KLNodeInfo*>& newNeighbourNodeList, double cTime)
{
	int commonNodeCount;
	double dissapeardNodePercentage;
	double newNodePercentage;
	int changeSignificance;
	
	
	// find number of common nodes
	commonNodeCount = 0;
	list<KLNodeInfo*>::const_iterator iteratorNewListNodeInfo = newNeighbourNodeList.begin();
	while (iteratorNewListNodeInfo != newNeighbourNodeList.end()) {
		KLNodeInfo *newListNodeInfo = (*iteratorNewListNodeInfo);
		
		list<KLNodeInfo*>::const_iterator iteratorOldListNodeInfo = neighbourNodeInfoList.begin();
		while (iteratorOldListNodeInfo != newNeighbourNodeList.end()) {
			KLNodeInfo *oldListNodeInfo = (*iteratorOldListNodeInfo);
			
			if (newListNodeInfo->getNodeAddress() == oldListNodeInfo->getNodeAddress()) {
				commonNodeCount++;
				break;
			}
			iteratorOldListNodeInfo++;
		}
		iteratorNewListNodeInfo++;
		
	}

	// percentage of old nodes dissapeared
	dissapeardNodePercentage = (neighbourNodeInfoList.size() - commonNodeCount) / neighbourNodeInfoList.size() * 100;

	// percentage of new nodes that appeared
	newNodePercentage = (newNeighbourNodeList.size() - commonNodeCount) / newNeighbourNodeList.size() * 100;
	
	// determine the change level
	if (newNodePercentage > 25.0) {
		changeSignificance = KLKEETCHI_SIGNIFICANT_CHANGE;
	} else {
		changeSignificance = KLKEETCHI_NO_CHANGE;
	}

	return changeSignificance;
}

int KLCommMgr::updateNeighbours(const list<KLNodeInfo*>& newNeighbourNodeList, double cTime)
{
	// remove old nodes
	while (!neighbourNodeInfoList.empty()) {
      KLNodeInfo *nodeInfo = neighbourNodeInfoList.front();
      neighbourNodeInfoList.pop_front();
	  delete nodeInfo;
    }

	// add new nodes
	list<KLNodeInfo*>::const_iterator iteratorNewListNodeInfo = newNeighbourNodeList.begin();
	while (iteratorNewListNodeInfo != newNeighbourNodeList.end()) {
		KLNodeInfo *newListNodeInfo = (*iteratorNewListNodeInfo);
		KLNodeInfo *nodeInfo = new KLNodeInfo(newListNodeInfo->getNodeAddress());
		neighbourNodeInfoList.push_back(nodeInfo);	
	}
	
	return 0;
}

