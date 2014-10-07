#ifndef MOTEXLOCK_H_
#define MOTEXLOCK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include "NonCopyable.h"

class MutexLock : NonCopyable
{
public:
    MutexLock() ;
    ~MutexLock() ;
 
    void lock() ;
    void unlock() ;
   
    pthread_mutex_t* getMutexPtr() { return &mutex_;  }     
    bool isLocked() const { return isLocked_;  }
private:


    pthread_mutex_t mutex_ ;
    bool isLocked_ ; 
} ;

class MutexLockGuard: NonCopyable
{
    public:
        MutexLockGuard(MutexLock &mutex)
            :mutex_(mutex) 
        {
            mutex_.lock() ;
        }
        ~MutexLockGuard()
        {
            mutex_.unlock() ;
        }

    private:
        MutexLock &mutex_ ;
} ;

#endif  /*MOTEXLOCK_H_*/
