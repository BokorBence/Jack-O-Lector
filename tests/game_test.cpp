#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
 
int main()
{
    assert(2+2==4);
}