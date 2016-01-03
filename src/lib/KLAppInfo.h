/**
* Holds information about a reistered application
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/

#ifndef KLAppInfo_H
#define KLAppInfo_H

#include <string>
#include "KLTypes.h"

using namespace std;

class KLAppInfo
{
	public:
		KLAppInfo(string app, string prefix);
		~KLAppInfo(void);
		
		// getters
		int getAppID() {return appID; }
		string getAppName() {return appName; }
		string getPrefixName() {return prefixName; }
		
		
	private:
		static int nextAppID;
		int appID;
		string appName;
		string prefixName;

};


#endif
