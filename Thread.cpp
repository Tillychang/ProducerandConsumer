#include "Thread.h" 
#include <assert.h>
#include <unistd.h>
void Thread::run()
{
    cout << "foo bar" << endl;
}

void* Thread::runInThread(void *arg) 
{
    Thread *pt = static_cast<Thread*>(arg) ;
    pt->run() ;
    return NULL ;
}

void Thread::join()
{
   assert(isRunning_) ;
   pthread_join(threadID_, NULL) ;
   isRunning_ = false ;
}

Thread::Thread()
   :threadID_(0),
    tid_(0),
    isRunning_(false)
{

}
Thread::~Thread()
{
    if(isRunning_)
    {
        pthread_detach(threadID_) ;
    }
}

void Thread::start()
{
    pthread_create(&threadID_, NULL, Thread:: runInThread, this) ; //runInThread是static函数， 数据所有该类对象共有， 所以必须把隐式指针传禁区
    isRunning_ = true ;
}

