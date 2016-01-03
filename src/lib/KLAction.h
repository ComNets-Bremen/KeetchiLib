/**
* Information returned after processing is done
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 18-June-2015
*
*/
#ifndef KLAction_H
#define KLAction_H

#include <list>
// using std::list;

#include "KLTypes.h"
#include "KLFeedbackMsg.h"
#include "KLDataMsg.h"

using namespace std;
	
class KLAction
{
	public:
		KLAction(void);
		~KLAction(void);
		
		// getters
		int getActionType() {return actionType; }
		KLDataMsg *getDataMsg() {return dataMsg; }
		KLFeedbackMsg *getFeedbackMsg() {return feedbackMsg; }
		int getProcessingStatus() {return processingStatus; }
		
		// setters
		void setActionType(int acType) {actionType = acType; }  	
		void setDataMsg(KLDataMsg *dMsg) {dataMsg = dMsg; }
		void setFeedbackMsg(KLFeedbackMsg *fMsg) {feedbackMsg = fMsg; }
		void setProcessingStatus(int pStatus) {processingStatus = pStatus; }  	
		
	private:
		int actionType; // KLACTION_ACTION_TYPE_... action with data, feedback or nothing
		KLDataMsg *dataMsg;
		KLFeedbackMsg *feedbackMsg;
		
		int processingStatus; // KLACTION_MSG_PROCESSING_...

};

#endif
