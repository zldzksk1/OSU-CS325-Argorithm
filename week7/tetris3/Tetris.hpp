#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "Block.hpp"
#include "Board.hpp"
#include "Coordination.hpp"
#include "Keyhandle.hpp"
#include "Points.hpp"
#include "value.hpp"

class Tetris 
{

private:
    bool playCheck;     //checking whether continue the game or not
    double gameSpeed;   //decide game speed
    Coordination posCheck_;
    Points tScore;      //control the score of the game
    Board tBoard;       //mange the play board
    Block* CurBlock;
    Block* NextBlock;
    Keyhandle controller_;  //user input handle
    clock_t sTime;

protected :
    void InitBoard();     
    void InitNextBlock();       //create next block
    void PrepareNext();     //ready to use the next block
    void GetNewBlock();     //next block will become new cur block
    void SetCursorInvisible();  
    double GetTimeDiff();
     
public:
    // contructor witl default value (each key is defined on Value.hpp)
    Tetris(Coordination reference_pos = Coordination(1, 1), int up = KEY_UP, int down = KEY_DOWN, int right = KEY_RIGHT, int left = KEY_LEFT, int space = KEY_SPACE, int esc = KEY_ESC);

    bool KeyHandler(int key);
    bool IsRunning();       //return playCheck value
    void Run();
    void InputCheck();      //check keyboard input                       
    void LineRemove();      //if line needs to be removed, it triggers       
};

#endif