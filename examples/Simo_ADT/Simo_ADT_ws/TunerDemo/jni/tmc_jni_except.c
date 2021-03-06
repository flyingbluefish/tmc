// Platform-specific implementation of exception handling and other utilities /////////////////
// For Android

#include <string.h>
#include <jni.h>
#include <stdlib.h>
#include <stdio.h>

#include <signal.h>

#include "tmc.h"

// Exported function called by tmcruntime:
void javatmcSignalError(char *ExceptMessageBuf);
// Utilities:
void javaDispString(char *bufferWaitBar);

static void javaRaiseExcept(char *bufferWaitBar);


// Should access these variables as extern.
jobject g_obj;
JNIEnv* g_env;
JavaVM* g_JavaVM;

// using sigaction() to setup a signal handler with 3 arguments
// including siginfo_t.
//
static char buf2[4096];
static struct sigaction old_sa[NSIG];
static long *ptrDummy;
static long dummyZero;



#define CATCHSIG(X) sigaction(X, &act, &old_sa[X])
static void tmcappExcptHandler(int sig, siginfo_t *siginfo, void *context)
{
	FILE *fp;
	//sprintf(buf2,"tmc/unhandledException PID: %ld, UID: %ld\n",
	//	(long)siginfo->si_pid, (long)siginfo->si_uid);
	// SignalError(0, buf2,"tmc/unhandledException");
	//javaDispString(buf2);


	fp = fopen("/mnt/sdcard/download/ServoToolErr.txt", "a");
	fprintf(fp, "tmc/Exception %s :\n",buf2);
	fclose(fp);
	ptrDummy = &dummyZero;
//	old_sa[sig].sa_handler(sig);
	javaRaiseExcept(&buf2[0]);

}
short InstallExcptHandler()
{
	struct sigaction act;
	FILE* fp;

	memset(&act, '\0', sizeof(act));

	// Use the sa_sigaction field because the handles has two additional parameters
	act.sa_sigaction = &tmcappExcptHandler;
	// The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler.
	act.sa_flags = SA_RESETHAND;// SA_SIGINFO;

	CATCHSIG(SIGILL);
	CATCHSIG(SIGABRT);
	CATCHSIG(SIGBUS);
	CATCHSIG(SIGFPE);
	CATCHSIG(SIGSEGV);
	//CATCHSIG(SIGSTKFLT);
	CATCHSIG(SIGPIPE);
	CATCHSIG(SIGCONT);

	fp = fopen("/mnt/sdcard/download/ServoToolErr.txt", "w");
	fprintf(fp, "STARTED:\n");
	fclose(fp);
	ptrDummy = 0;

	buf2[0] = '?';
	buf2[1] = 0;
}

//JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
//{
////	InstallExcptHandler();
//}

void javatmcSignalError(char *ExceptMessageBuf)
{
	//SignalError(0, "tmc/errorException", "tmc/errorException");
	//javaDispString(ExceptMessageBuf);
	strcpy(buf2, ExceptMessageBuf);
	//javaRaiseExcept(ExceptMessageBuf);
	ptrDummy[0] = 0x0;
}
/*
public void renderStuff() {
if((this instanceof com.path.to.the.MyClass) == false)
throw new RuntimeException("Unexpected class expected: com.path.to.the.MyClass");
renderStuff_internal();
}
private native void renderStuff_internal();
*/

void javaDispString(char *bufferWaitBar)
{
	//JNIEnv *env;
	//(*g_JavaVM)->GetEnv(g_JavaVM, (void**)&env, JNI_VERSION_1_6);

	jstring jstr1 = (*g_env)->NewStringUTF(g_env,bufferWaitBar);
	if (!jstr1) return;  // whoops method does not exist

	jclass clazz = (*g_env)->GetObjectClass(g_env, g_obj);
	jmethodID mid = (*g_env)->GetMethodID(g_env, clazz, "showprogress", "(Ljava/lang/String;)V");

	if (!mid) return;  // whoops method does not exist

	(*g_env)->CallVoidMethod(g_env, g_obj, mid, jstr1);

}
void javaRaiseExcept(char *bufferWaitBar)
{
	//JNIEnv *env;
	//(*g_JavaVM)->GetEnv(g_JavaVM, (void**)&env, JNI_VERSION_1_6);

	jstring jstr1 = (*g_env)->NewStringUTF(g_env, bufferWaitBar);
	if (!jstr1) return;  // whoops method does not exist

	jclass clazz = (*g_env)->GetObjectClass(g_env, g_obj);
	jmethodID mid = (*g_env)->GetMethodID(g_env, clazz, "stopme", "(Ljava/lang/String;)V");

	if (!mid) return;  // whoops method does not exist

	(*g_env)->CallVoidMethod(g_env, g_obj, mid, jstr1);

}
///////////////////////////////////////////////////////////////////////////
/// This function is platform-specific
char bufferWaitBar[2048];
//void javaDispString(char *bufferWaitBar);
void tmcwaitbar(long nout, long ninput, tmsMatrix *hand, tmsMatrix *frac, tmsMatrix *title, tmsMatrix *pt1, tmsMatrix *pv1, tmsMatrix *pt2, tmsMatrix *pv2)
{
	//	extern __int64 g_MemCnt;
	//	extern __int64 g_MemN;
	//	extern __int64 g_MemUsed;

	if (nout>0)
		_tmcCreateMatrix(hand, 1, 1, 0);

	if (ninput>1)
		//sfprintf(bufferWaitBar, "waitbar: %f, Mem=%I64d,N=%I64d,MU=%I64d \n", frac->m_rData[0], g_MemCnt, g_MemN, g_MemUsed);
		sprintf(bufferWaitBar, "PLEASE WAIT,progress: %f \n", frac->m_rData[0]);
	javaDispString(bufferWaitBar);
}

