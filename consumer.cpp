#include "consumer.h"
#include "buffer1.h"
#include <iostream>

Consumer::Consumer(Buffer &buffer)
    :buffer_(buffer)
{

} 

void Consumer::run()
{
    while(1)
    {
        int num = buffer_.pop() ;
        std:: cout << "pop a num: " << num << endl;

        sleep(2) ;
    }
}
