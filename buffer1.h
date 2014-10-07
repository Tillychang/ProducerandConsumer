#ifndef BUFFER1_H_
#define BUFFER1_H_ 
#include <queue>
#include <iostream>
#include "MutexLock.h"
#include "Condition.h"
using namespace std; 
class Buffer 
{
public:
    Buffer(size_t size) ;
    void push(int val) ; 
    int pop() ;
    bool empty() const ;
    size_t size() const ;
private:
    size_t maxSize_;
    mutable MutexLock mutex_ ; //在const程序中可悲改变
    Condition pro_ ;
    Condition cond_ ;
    std::queue<int> q_ ;
} ;


#endif  /*BUFFER_H_*/
