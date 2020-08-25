#ifndef BOARD_HPP
#define BOARD_HPP

#include"Coordination.hpp"
#include "value.hpp"


class Board 
{
private:
    int gboard[B_WIDTH][B_HEIGHT];

public :
    Board();
    void SetState(Coordination pos, int state);    // Pos 위치의 값을 State 값으로 설정함
    int GetState(Coordination pos);                // return board position
    int LineCheck(Coordination posCheck);      // check the line, if there is a fullline, then remove the line
                                            
};

#endif