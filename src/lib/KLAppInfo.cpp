/*
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#include "KLAppInfo.h"

int KLAppInfo::nextAppID = 0;

KLAppInfo::KLAppInfo(string app, string prefix)
{
	appName = app;
	prefixName = prefix;
	appID = ++nextAppID;
}

KLAppInfo::~KLAppInfo(void)
{	
}
