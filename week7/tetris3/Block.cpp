#include "Block.hpp"


int Draw_count = 0;

//Blocks[block identification][with][height], four different shapes
Coordination block_pattern[7][4][4] =
{
    { // block I
		{ Coordination(0, 1), Coordination(0, 0), Coordination(0, -1), Coordination(0, -2) }, 
	    { Coordination(-2, 0), Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0) },
        { Coordination(0, 1), Coordination(0, 0), Coordination(0, -1), Coordination(0, -2) }, 
	    { Coordination(-2, 0), Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0) } 
	},  

    { // block L
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0), Coordination(-1, 1) }, 
	    { Coordination(0, 1), Coordination(0, 0), Coordination(1, 1), Coordination(0, -1) },
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0), Coordination(1, -1) },
	    { Coordination(0, 1), Coordination(0, 0), Coordination(0, -1), Coordination(-1, -1) }
	},  

    { // block J
		{ Coordination(1, 1), Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0)},
	    { Coordination(0, 1), Coordination(0, 0), Coordination(0, -1), Coordination(1, -1) },
		{  Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0), Coordination(-1, -1)}, 
	    { Coordination(-1, 1), Coordination(0, 1), Coordination(0, 0), Coordination(0, -1)  }

	}, 

    { // block O
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(-1, -1), Coordination(0, -1) }, 
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(-1, -1), Coordination(0, -1) },
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(-1, -1), Coordination(0, -1) }, 
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(-1, -1), Coordination(0, -1) } 
	},  

    { // block S
		{ Coordination(0, 1), Coordination(0, 0), Coordination(1, 0), Coordination(1, -1) },
		{ Coordination(0, 0), Coordination(1, 0), Coordination(-1, -1), Coordination(0, -1) },
		{ Coordination(0, 1), Coordination(0, 0), Coordination(1, 0), Coordination(1, -1) }, 
		{ Coordination(0, 0), Coordination(1, 0), Coordination(-1, -1), Coordination(0, -1) } 
	},  

	{// block z
		{ Coordination(1, 1), Coordination(0, 0), Coordination(1, 0), Coordination(0, -1) }, 
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(0, -1), Coordination(1, -1) },
		  { Coordination(1, 1), Coordination(0, 0), Coordination(1, 0), Coordination(0, -1) },
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(0, -1), Coordination(1, -1) }
	},  

	{  // block T
		{ Coordination(0, 1), Coordination(-1, 0), Coordination(0, 0), Coordination(0, -1) }, 
		{ Coordination(0, 1), Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0) },
		{ Coordination(0, 1), Coordination(0, 0), Coordination(1, 0), Coordination(0, -1) },
		{ Coordination(-1, 0), Coordination(0, 0), Coordination(1, 0), Coordination(0, -1) } 
	} 

};

//constructor
Block::Block(Board *board, BLOCK_TYPE type) : tboard(board), btype(type)
{
	rotation = 0;
}


void Block::SetBlockPos(Coordination pos)
{
    blockPos = pos;
}

//decide the postion of block on screen
void Block::SetScreenPos()
{
	displayPos = Coordination::GetScreenpos(blockPos);
}

void Block::MoveUp(Coordination posCheck)	//roate the block
{
	if (rotation != 3)
		rotation++;
	else
		rotation = 0;	//back to first position

	if (ValidatePos())
	{
		if (rotation == 0)
			rotation = 3;
		else
			rotation--;	//get current block post
		DelBlock(posCheck); //delete the block
		if (rotation != 3)
			rotation++;	//get next shape of block
		else
			rotation = 0;
		InitBlock(posCheck);	//display rotated shape
	}

	else
	{
		if (rotation == 0)
			rotation = 3;
		else
			rotation--;
	}
}

//move a block 
bool Block::MoveDown(Coordination posCheck)
{
	blockPos.SetY(blockPos.GetY() - 1);	//block one line below

	if (ValidatePos())					//check if block can go down
	{
		blockPos.SetY(blockPos.GetY() + 1);	//get the postion of the block
		DelBlock(posCheck);					//delete the block
		blockPos.SetY(blockPos.GetY() - 1); //andn set the block postion 1 line below
		InitBlock(posCheck);				//init the block on new position
	}
	else									//can't move 
	{
		blockPos.SetY(blockPos.GetY() + 1);
		return false;
	}
}

void Block::MoveRight(Coordination posCheck)	//same implementation with move down, just move it to right
{
    blockPos.SetX(blockPos.GetX() + 1);

    if (ValidatePos())
    {
        blockPos.SetX(blockPos.GetX() - 1);
		DelBlock(posCheck);
        blockPos.SetX(blockPos.GetX() + 1);
		InitBlock(posCheck);
    }
    else
    {
        blockPos.SetX(blockPos.GetX() - 1);
    }
}

void Block::MoveLeft(Coordination posCheck)
{
	blockPos.SetX(blockPos.GetX() - 1);

	if (ValidatePos())
	{
		blockPos.SetX(blockPos.GetX() + 1);
		DelBlock(posCheck);
		blockPos.SetX(blockPos.GetX() - 1);
		InitBlock(posCheck);
	}
	else
	{
		blockPos.SetX(blockPos.GetX() + 1);
	}
}

void Block::DropBlock(Coordination posCheck)
{
    while (MoveDown(posCheck))
    {
        Sleep(0.1);
    }
}



void Block::InitBlock(Coordination posCheck)		//create block
{
	int i;
	for (i = 0; i < 4; i++)
	{
		posCheck.SetX(blockPos.GetX() + block_pattern[btype][rotation][i].GetX());	//position of block on board based on its shape
		posCheck.SetY(blockPos.GetY() + block_pattern[btype][rotation][i].GetY());
		posCheck = Coordination::GetScreenpos(posCheck);						//get the postion of block for screen prompt
		Coordination::GotoXY(posCheck.GetX(), posCheck.GetY());
		if (btype >= 0 || btype <=6) 
		{
			std::cout << "□";		//dispy block on prompt
		}						
	}
}

void Block::DelBlock(Coordination posCheck)		//delete block (same implementation with Initblock
{
	int i;
	for (i = 0; i < 4; i++)
	{
		posCheck.SetX(blockPos.GetX() + block_pattern[btype][rotation][i].GetX());
		posCheck.SetY(blockPos.GetY() + block_pattern[btype][rotation][i].GetY());
		posCheck = Coordination::GetScreenpos(posCheck);
		Coordination::GotoXY(posCheck.GetX(), posCheck.GetY());
		std::cout << "  ";	//display empty 
		Coordination::GotoXY(posCheck.GetX(), 21);
	}
}


void Block::CheckBlockPos(Coordination posCheck)	//check the board and settle the block on position
{
	int i;
	for (i = 0; i < 4; i++)	
	{
		posCheck.SetX(blockPos.GetX() + block_pattern[btype][rotation][i].GetX());
		posCheck.SetY(blockPos.GetY() + block_pattern[btype][rotation][i].GetY());
		tboard->SetState(posCheck, 1);	//pass one, so it means there are block on the board
	}
}

bool Block::CheckPlay()
{
	if (tboard->GetState(cur_block_init_pos) != EMPTY)	// if top is not empty, very top block hit the ceiling point
		return true;									//then game over
	else
		return false;
}

bool Block::ValidatePos()
{
	for (int i = 0; i < 4; i++)		//if return flase, it is an error
	{
		Coordination cur_pos(blockPos.GetX() + block_pattern[btype][rotation][i].GetX(), blockPos.GetY() + block_pattern[btype][rotation][i].GetY());

		if (cur_pos.GetX() < 0 || cur_pos.GetX() > 9)
			return false;
		if (cur_pos.GetY() < 0)
			return false;
		if (cur_pos.GetY() <= 19 && tboard->GetState(cur_pos) != EMPTY)
			return false;
	}
	return true;	//no issue found
}