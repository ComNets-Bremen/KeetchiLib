#
# Makefile to build the KeetchiLib
#
# @author : Asanga Udugama (adu@comnets.uni-bremen.de)
# @date   : 18-June-2015
#
COMPILE 	= gcc -c
ARCHIEVE	= ar -vrc
INDEX		= ranlib

all: libkeetchi.a

libkeetchi.a: KLKeetchi.o KLAction.o KLFeedbackMsg.o KLDataMsg.o \
			  KLNodeInfo.o KLCacheEntry.o KLAppInfo.o KLDataMgr.o \
			  KLCommMgr.o KLResourceMgr.o
	$(ARCHIEVE) libkeetchi.a KLKeetchi.o KLAction.o KLFeedbackMsg.o \
				KLDataMsg.o KLNodeInfo.o KLCacheEntry.o KLAppInfo.o \
				KLDataMgr.o KLCommMgr.o KLResourceMgr.o
	$(INDEX) libkeetchi.a

KLKeetchi.o : KLKeetchi.cpp KLKeetchi.h KLTypes.h
	$(COMPILE) KLKeetchi.cpp

KLAction.o : KLAction.cpp KLAction.h KLTypes.h
	$(COMPILE) KLAction.cpp

KLFeedbackMsg.o : KLFeedbackMsg.cpp KLFeedbackMsg.h KLTypes.h
	$(COMPILE) KLFeedbackMsg.cpp

KLDataMsg.o : KLDataMsg.cpp KLDataMsg.h KLTypes.h
	$(COMPILE) KLDataMsg.cpp

KLNodeInfo.o : KLNodeInfo.cpp KLNodeInfo.h KLTypes.h
	$(COMPILE) KLNodeInfo.cpp

KLCacheEntry.o : KLCacheEntry.cpp KLCacheEntry.h KLTypes.h
	$(COMPILE) KLCacheEntry.cpp

KLAppInfo.o : KLAppInfo.cpp KLAppInfo.h KLTypes.h
	$(COMPILE) KLAppInfo.cpp

KLDataMgr.o : KLDataMgr.cpp KLDataMgr.h KLTypes.h
	$(COMPILE) KLDataMgr.cpp
	
KLCommMgr.o : KLCommMgr.cpp KLCommMgr.h KLTypes.h
	$(COMPILE) KLCommMgr.cpp
	
KLResourceMgr.o : KLResourceMgr.cpp KLResourceMgr.h KLTypes.h
	$(COMPILE) KLResourceMgr.cpp
	
clean:
	rm -f *.o libkeetchi.a
