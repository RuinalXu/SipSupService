#ifndef _EMBEDDED_CONTROLLER_THREAD_H_
#define _EMBEDDED_CONTROLLER_THREAD_H_ 

#include <pthread.h>
#include <string>
#include <sys/prctl.h>

namespace embedded_controller {
class EmbeddedControllerThread {
private:
    EmbeddedControllerThread(){}
    ~EmbeddedControllerThread(){}
public:
    static int createThread();
    static int detachSelf();
    static void exitSelf();
    static int waitThread(const pthread_t& id);
    static int terminateThread(const pthread_t& id);
};

}
#endif