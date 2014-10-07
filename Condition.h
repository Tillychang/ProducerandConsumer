#ifndef CONDITION_H_
#define CONDITION_H_ 

#include "NonCopyable.h"
#include <pthread.h>
#include "MutexLock.h"



class MutexLock ;//定义一个




class Condition : NonCopyable
{
public:
    Condition(MutexLock &mutex) ;
    ~Condition() ;


    void wait() ;
    void notify() ;
    void notifyAll() ;


private:
    pthread_cond_t cond_ ;   //一个条件变量
    MutexLock &mutex_ ;   //一个互斥锁的引用 (一个对象的引用) ; 避开了复制的问题
} ;

#endif  /*CONDITION_H_*/
