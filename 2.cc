#include <iostream>
#include <string>
#include <vector>
#include "producer.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Producer pro;
    pro.start() ;
     
    pro.join() ;
    return 0;
}
