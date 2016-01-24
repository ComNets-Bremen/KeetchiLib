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

int KLCommMgr::determineChangeSignificance(list<KLNodeInfo*>& newNeighbourNodeList, double cTime)
{
	int commonNodeCount;
	int newlyAppearedNodeCount;
	double changeRatio;
	int changeSignificance;
			
	// find number of common nodes
	commonNodeCount = 0;
	list<KLNodeInfo*>::iterator iteratorNewListNodeInfo = newNeighbourNodeList.begin();
	while (iteratorNewListNodeInfo != newNeighbourNodeList.end()) {
		KLNodeInfo *newListNodeInfo = *iteratorNewListNodeInfo;
		
		list<KLNodeInfo*>::iterator iteratorOldListNodeInfo = neighbourNodeInfoList.begin();
		while (iteratorOldListNodeInfo != neighbourNodeInfoList.end()) {
			KLNodeInfo *oldListNodeInfo = *iteratorOldListNodeInfo;

			if (newListNodeInfo->getNodeAddress() == oldListNodeInfo->getNodeAddress()) {
				commonNodeCount++;
				break;
			}
			iteratorOldListNodeInfo++;
		}
		iteratorNewListNodeInfo++;
		
	}
		
	// how many new nodes have appeared?
	newlyAppearedNodeCount = (newNeighbourNodeList.size() > commonNodeCount ? newNeighbourNodeList.size() - commonNodeCount : 0);
	
	if (newlyAppearedNodeCount == 0) {
		
		// if no newly appeared nodes exist, then still the same neighbourhood (minus
		// the left nodes)
		changeSignificance = KLKEETCHI_NO_CHANGE;
		
	} else if (newlyAppearedNodeCount > 0 && neighbourNodeInfoList.size() == 0) {
		
		// if there are a newly appeared nodes and there were no nodes before, 
		// that means a completely new neighbourhood
		changeSignificance = KLKEETCHI_SIGNIFICANT_CHANGE;
		
	} else {
		
		// control comes here is there is a partil change
		// so, find the ratio of partial change
		changeRatio = ((double) newlyAppearedNodeCount) / neighbourNodeInfoList.size();
		
		if (changeRatio > 0.25) {
			
			// if partial change is greater than 25%, then change is very 
			// significant
			changeSignificance = KLKEETCHI_SIGNIFICANT_CHANGE;
			
		} else {
			
			// else, insignificant change
			changeSignificance = KLKEETCHI_NO_CHANGE;
			
		}
	}
	
	return changeSignificance;
}

int KLCommMgr::updateNeighbours(list<KLNodeInfo*>& newNeighbourNodeList, double cTime)
{
	// remove old nodes
	while (!neighbourNodeInfoList.empty()) {
      KLNodeInfo *nodeInfo = neighbourNodeInfoList.front();
      neighbourNodeInfoList.pop_front();
	  delete nodeInfo;
    }

	// add new nodes
	list<KLNodeInfo*>::iterator iteratorNewListNodeInfo = newNeighbourNodeList.begin();
	while (iteratorNewListNodeInfo != newNeighbourNodeList.end()) {
		KLNodeInfo *newListNodeInfo = (*iteratorNewListNodeInfo);
		KLNodeInfo *nodeInfo = new KLNodeInfo(newListNodeInfo->getNodeAddress());
		neighbourNodeInfoList.push_back(nodeInfo);
		iteratorNewListNodeInfo++;
	}
	
	return 0;
}

