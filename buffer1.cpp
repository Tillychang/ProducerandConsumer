#include "buffer1.h"

Buffer::Buffer(size_t size)         //队列编译器中调用它的构造函数帮我们
    : pro_(mutex_), cond_(mutex_), maxSize_(size)
{
} 

void Buffer::push(int val)
{
    {
    MutexLockGuard lock(mutex_) ;
    while(q_.size() >= maxSize_)
        pro_.wait() ;
    q_.push(val) ;
    }
    cond_.notify() ;
}

int Buffer::pop()
{
    int temp = 0 ;
    {
        
        MutexLockGuard lock(mutex_) ;
        while(q_.empty())
            cond_.wait() ;
        temp = q_.front() ;
        q_.pop() ;
    }
    pro_.notify() ;

    return temp ;
}

bool Buffer::empty() const 
{
    MutexLockGuard lock(mutex_) ;
    return q_.empty() ;
}

size_t Buffer::size() const
{
    MutexLockGuard lock(mutex_) ;
    return q_.size() ;
}
