/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#include "KLAction.h"

KLAction::KLAction(void)
{
	actionType = 0;
	dataMsg = NULL;
	feedbackMsg = NULL;	
	
	processingStatus = 0;
	
}

KLAction::~KLAction(void)
{
	
}
