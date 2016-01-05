/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#include "KLDataMsg.h"

KLDataMsg::KLDataMsg(void)
{
}

KLDataMsg::~KLDataMsg(void)
{
	free(dataPayload);
}
