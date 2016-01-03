/**
* Manages the operations related to communications.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 16-Sept-2015
*
*/

#ifndef KLCommMgr_H
#define KLCommMgr_H

#include <list>
#include <string>

#include "KLTypes.h"
#include "KLNodeInfo.h"

using namespace std;

class KLCommMgr
{
	public:
		KLCommMgr(void);
		~KLCommMgr(void);
				
		// operations
		int determineChangeSignificance(const list<KLNodeInfo*>& newNeighbouNodeList, double cTime);
		int updateNeighbours(const list<KLNodeInfo*>& newNeighbouNodeList, double cTime);

	private:
		list<KLNodeInfo*> neighbourNodeInfoList;

};

#endif
