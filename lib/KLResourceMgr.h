/**
* Manages the operations related to resources.
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 22-Sept-2015
*
*/

#ifndef KLResourceMgr_H
#define KLResourceMgr_H

#include <list>
#include <string>

#include "KLTypes.h"

using namespace std;

class KLResourceMgr
{
	public:
		KLResourceMgr(void);
		~KLResourceMgr(void);

		// operations
		int determineResourceLimitationStatus(double cTime);

	private:
		int batteryLevel;

};

#endif
