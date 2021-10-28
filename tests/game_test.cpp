#include <iostream>
#include "../include/guard.hpp"
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
 
int main()
{
    assert(2+2==4);
    Guard g = Guard(0, 0, 0, true, 1);
    assert(g.get_x() == 0);
    assert(g.get_y() == 0);
    assert(g.get_d() == 0);
    g.moveDown();
    assert(g.get_y() == 1);
    g.moveUp();
    assert(g.get_y() == 0);
    g.moveRight();
    assert(g.get_x() == 1);
    g.moveLeft();
    assert(g.get_x() == 0);
}