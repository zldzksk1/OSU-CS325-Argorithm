
#include "Board.hpp"

Board::Board()		//initialize board
{
	int i, j;

	for (i = 0; i < B_WIDTH; i++)
    {
		for (j = 0; j < B_HEIGHT; j++)
			gboard[i][j] = EMPTY;
	}
}


void Board::SetState(Coordination pos, int state)
{
	gboard[pos.GetX()][pos.GetY()] = state;	//set the board with new state value
}

int Board::GetState(Coordination pos)
{ 
	return gboard[pos.GetX()][pos.GetY()];	//reutn the board value, in order to check the change on the board status
}


int Board::LineCheck(Coordination posCheck)
{
	int count = 0, check = 0;

	for (int val = 0; val < B_HEIGHT - 1; val++)
	{
		for (int y = 0; y < B_HEIGHT; y++)  // 
		{
			for (int x = 0; x < B_WIDTH; x++)  //
			{
				if (gboard[x][y] == EMPTY)   //Check the line, if there is empty part, then do nothing
				{
					check++;
					break;
				}
			}
			if (check == 0)  //row is full with blocks
			{
				count++;
				for (int j = y + 1; j < B_HEIGHT - 1; j++)
				{
					for (int i = 0; i < B_WIDTH; i++)
					{
						Coordination::GotoXY(2 * (i + posCheck.GetX()) + 2, -j + 21);
						std::cout << "  "; //remove line
						gboard[i][j - 1] = EMPTY;	//update the board
					}
					for (int i = 0; i < 10; i++)	//bring upper line to below
						gboard[i][j - 1] = gboard[i][j];
				}

				for (int i = 0; i < B_WIDTH; i++)
					gboard[i][19] = EMPTY;

				for (int j = 0; j < B_HEIGHT; j++)	//redraw the board with updated board status data
				{
					for (int i = 0; i < B_WIDTH; i++)
					{
						if (gboard[i][j] != EMPTY)
						{
							Coordination::GotoXY(2 * (i + posCheck.GetX()) + 2, -j + B_HEIGHT);	//if the postion is not empty, then fill the block
							std::cout << "■";
						}
						else																	//elese empty
						{
							Coordination::GotoXY(2 * (i + posCheck.GetX()) + 2, -j + B_HEIGHT);
							std::cout << "  ";
						}
					}
				}
			}
			check = 0;
		}
	}
	return count;
}










