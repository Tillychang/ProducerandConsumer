#include <iostream>
#include <string>
#include <vector>
#include "buffer1.h"
#include "Thread.h"
#include "MutexLock.h"
#include "Condition.h"
#include <time.h> 
using namespace std;

Buffer buf(20) ;

class Producer: public Thread
{
    public:
        void run()
        {
            while(1)
            {
                buf.lock() ;
                while(buf.full())
                    buf.wait_pro() ;

                int ret = buf.push() ;
                cout << "生产一个单位" << ret <<endl;
                buf.signal_pro() ;
                buf.unlock() ;
                sleep(1) ;
            }
        }
} ;


class Consumer: public Thread
{
    public:
        void run() 
        {
            while(1)
            {
                buf.lock() ;
                while(buf.empty())
                    buf.wait_con();
                int ret = buf.pop() ;
                cout << "消费一个单位" << ret << endl;
                buf.signal_con() ;
                buf.unlock() ;
                sleep(1) ;
            }
        }
} ;










int main(int argc, const char *argv[])
{
    srand(time(NULL)) ;
    Producer pro[3] ;
    Consumer con[5] ;
    
    for (int i = 0; i < 3; ++i) {
        pro[i].start() ;
    }
    sleep(3) ;

    for (int i = 0; i < 5; i++) {
       con[i].start() ; 
    }
    
    for (int i = 0; i < 3; i++) {
        con[i].join() ;
    }
    for (int i = 0; i < 5; ++i) {
        pro[i].join() ;
    }
    return 0;
}

