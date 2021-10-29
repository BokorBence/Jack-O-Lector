#include <iostream>
#include "../include/guard.hpp"
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
 
int main()
{
    assert(2+2==4); //initial test

    /*Guard constructor test*/
    Guard agent_k = Guard(0, 0, 0, true, 2);
    assert(agent_k.get_x() == 0);
    assert(agent_k.get_y() == 0);
    assert(agent_k.get_d() == 0);
    assert(agent_k.get_search_time() == 5);

    /*Guard moving 4 directions test*/

    agent_k.moveDown();
    assert(agent_k.get_y() == 1);
    assert(agent_k.get_d() == 0);
    agent_k.moveUp();
    assert(agent_k.get_y() == 0);
    assert(agent_k.get_d() == 2);
    agent_k.moveRight();
    assert(agent_k.get_x() == 1);
    assert(agent_k.get_d() == 1);
    agent_k.moveLeft();
    assert(agent_k.get_x() == 0);
    assert(agent_k.get_d() == 3);
    
    /*Guard Move Method*/
    agent_k.Move();
    assert(agent_k.get_x() == 1);
    assert(agent_k.get_d() == 1);
    agent_k.Move();
    assert(agent_k.get_x() == 2);
    assert(agent_k.get_d() == 1);

    Guard agent_s = Guard(4, 4, 0, false, 2);
    assert(agent_s.get_x() == 4);
    assert(agent_s.get_y() == 4);
    agent_s.Move();
    assert(agent_s.get_x() == 4);
    assert(agent_s.get_y() == 5);
    assert(agent_s.get_d() == 0);
    agent_s.Move();
    assert(agent_s.get_x() == 4);
    assert(agent_s.get_y() == 6);
    assert(agent_s.get_d() == 0);

    /*WalkingEntity turn methods */

    agent_s.turnClockwise();
    assert(agent_s.get_d() == 3);
    agent_s.turnClockwise();
    assert(agent_s.get_d() == 2);
    agent_s.turnAntiClockwise();
    assert(agent_s.get_d() == 3);

    /*Entity set methods*/

    agent_k.set_d(3);
    assert(agent_k.get_d() == 3);
    agent_k.set_x(3);
    assert(agent_k.get_x() == 3);
    agent_k.set_y(3);
    assert(agent_k.get_y() == 3);
}