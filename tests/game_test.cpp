#include <iostream>
#include "../include/guard.hpp"
#include "../include/level_1.hpp"
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
 
bool Level1_create();

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

    //bool kamehameha = Level1_create();
}

bool Level1_create()
{
    /*Level_1 creating*/
    bool passed = true;
    Level_1 level = Level_1("levels/level1.txt");
  //  passed = passed && (level.get_objective() == false);
  //  passed = passed && (level._tile_matrix[0][0]->get_path() == "wall");
  //  passed = passed && (level._tile_matrix[1][1]->get_path() == "background");
  //  passed = passed && (level._tile_matrix[33][44]->get_path() == "objective");
  //  passed = passed && (level._tile_matrix[2][9]->get_path() == "grave");
  //  passed = passed && (level._tile_matrix[2][13]->get_path() == "tree/bush");
    return passed;

}