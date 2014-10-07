#ifndef THREAD_H_
#define THREAD_H_ 
#include "NonCopyable.h" 
#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std;
class Thread : private NonCopyable
{
    public:
        Thread() ;
        ~Thread() ;
        

        void start() ;
        void join() ;

        virtual  void run() ;


    protected:
        static void * runInThread(void *arg)  ;

        pthread_t threadID_ ;
        pid_t tid_ ;
        bool isRunning_ ;
} ;


#endif /* Thread.h */
