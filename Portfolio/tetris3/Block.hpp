#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Coordination.hpp"
#include "Board.hpp"
#include "Points.hpp"
#include "value.hpp"

const Coordination next_block_init_pos(14, 17);
const Coordination cur_block_init_pos(4, 18);

class Block 
{
protected:
    int rotation;
    Board* tboard;
    BLOCK_TYPE btype;           //types of block
    Coordination blockPos;
    Coordination displayPos;
    Coordination tscore;
    virtual bool ValidatePos(); //Check the block so It can't be displayed unwanted position

public : 
    Block();
    Block(Board *board, BLOCK_TYPE type);

    void MoveUp(Coordination posCheck); //It will rotate the block
    bool MoveDown(Coordination posCheck);
    void MoveRight(Coordination posCheck);	        
    void MoveLeft(Coordination posCheck);		             
    void DropBlock(Coordination posCheck);		 
    void SetBlockPos(Coordination pos);		//set the position of block	   
	void SetScreenPos();                 // 
    virtual void InitBlock(Coordination posCheck);     //init block
    virtual void DelBlock(Coordination posCheck);      //delete block
    virtual void CheckBlockPos(Coordination posCheck);
    bool CheckPlay();                                   //check whether the player can continue the game or game over



};

#endif