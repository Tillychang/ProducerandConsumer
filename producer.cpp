#include "producer.h"
#include "buffer1.h"
#include <time.h>
#include <stdlib.h>
Producer::Producer(Buffer &buffer)
    :buffer_(buffer)
{
    ::srand(time(NULL)) ;
}


void Producer::run()
{
    while(1)
    {
        int num = rand() % 100 ;
        std::cout << "push a num: " << num << std::endl;
        buffer_.push(num) ;


        sleep(2) ;
    }
}
