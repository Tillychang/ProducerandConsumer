#include "MutexLock.h" 

MutexLock::MutexLock() 
    :isLocked_(false) 
{
    pthread_mutex_init(&mutex_, NULL) ;
}

MutexLock::~MutexLock()
{
    assert(isLocked_ == false ) ;
    pthread_mutex_destroy(&mutex_) ;
}

void MutexLock::lock()
{
    pthread_mutex_lock(&mutex_) ;
    isLocked_ = true ;
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(&mutex_) ;
    isLocked_ = false ;
}
