#include "Thread.h"


class Buffer ;

class Producer :public  Thread
{
public:
    Producer(Buffer &buffer) ;
    void run()  ;

private:
    Buffer &buffer_ ;   // 生产者包含一个 buffer区的引用，是关联关系
};
