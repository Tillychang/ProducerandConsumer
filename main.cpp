#include "buffer1.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, const char *argv[])
{
    Buffer buffer(5) ;

    Producer p1(buffer) ;

    Consumer c1(buffer) ;

    p1.start() ;

    c1.start() ;

    p1.join() ;

    c1.join()  ;
    return 0;
}

