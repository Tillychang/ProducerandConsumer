#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_ 

class NonCopyable
{
public: 
    NonCopyable() { } ;
    ~NonCopyable() { };
private:
    NonCopyable &operator=(const NonCopyable &) ;
    NonCopyable(const NonCopyable &) ;
} ;

#endif  /*NONCOPYABLE_H_*/
