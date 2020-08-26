#include "Tetris.hpp"


Tetris::Tetris(Coordination posCheck, int up, int down, int right, int left, int space, int esc) : posCheck_(posCheck)
{ 
    controller_.SetKeyboard(up, down, right, left, space, esc);    //set keyboard for the game

    playCheck = true; //if it becomes false, game stop
    gameSpeed = 0.8;    //initial game spedd
    sTime = clock();    //get current time

    SetCursorInvisible(); // 
    InitBoard();    //initiate the board
    InitNextBlock();    //generate new block
    GetNewBlock();      
    InitNextBlock();    //generate next block
    CurBlock->InitBlock(posCheck_);
    NextBlock->InitBlock(posCheck_);
    tScore.Display(posCheck_);
}


void Tetris::InputCheck()
{
    if (_kbhit())
    {
        int key = Keyhandle::GetKey();  //get input from users
        KeyHandler(key);                //call the key handler to react to the user input
    }
    else
    {
        LineRemove();
    }
}

void Tetris::Run()
{
    while (playCheck) 
    {
        InputCheck();               //call inputcheck function to get user input
    }
}


bool Tetris::IsRunning()
{
    return playCheck;
}

bool Tetris::KeyHandler(int key)         //move block based on users input
{
    if (key == controller_.Getkey_esc())            //if player hit esc, stop game
    {
        playCheck = false;
        return true;
    }

    else if (key == controller_.Getkey_up())
    {
        CurBlock->MoveUp(posCheck_);
        return true;
    }
    else if (key == controller_.Getkey_down())
    {
        CurBlock->MoveDown(posCheck_);
        return true;
    }

    else if (key == controller_.Getkey_right())    
    {
        CurBlock->MoveRight(posCheck_);
        return true;
    }
    else if (key == controller_.Getkey_left()) 
    {
        CurBlock->MoveLeft(posCheck_);
        return true;
    }

	else if (key == controller_.Getkey_space())
	{
		CurBlock->DropBlock(posCheck_);
		return true;
	}
    return false;
}

void Tetris::LineRemove()       //game level increase, then speed of game will be faster
{
	int glevel = tScore.gameLevel();

	if (glevel == 1)
		gameSpeed = 0.8;
	else if (glevel == 2)
		gameSpeed = 0.7;
	else if (glevel == 3)
		gameSpeed = 0.6;
	else if (glevel == 4)
		gameSpeed = 0.5;
	else if (glevel >= 5)
		gameSpeed = 0.3;

    if (GetTimeDiff() >= gameSpeed) // as the time goes by, block will down
    {
        if (CurBlock->MoveDown(posCheck_)) 
        {
            sTime = clock();
        }
        else 
        {	
            PrepareNext();
        }
    }
}



void Tetris::GetNewBlock() 
{
	if (CurBlock != NULL) 
		delete CurBlock;    //delete one we use already

	CurBlock = NextBlock;   //get new block
	CurBlock->SetBlockPos(cur_block_init_pos);
}

double Tetris::GetTimeDiff()
{
    clock_t CurTime;
    CurTime = clock();	//time(&CurTime);
    return ((double) (CurTime - sTime) / CLOCKS_PER_SEC);
}

void Tetris::SetCursorInvisible(void)	// disable the cursor
{
    CONSOLE_CURSOR_INFO ci = { 10, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

void Tetris::InitBoard()    //prompt the tetris board
{
    int i;

    Coordination::GotoXY(posCheck_);
    std::cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦";
    for (i = 0; i < 20; i++)
    {
        if (i == 11)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦ ↑ Rotation    ▦";
        }
        else if (i == 13)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦ ↓ move down   ▦";
        }
        else if (i == 15)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦ ← move left   ▦";
        }
        else if (i == 17)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦ → move right  ▦";
        }
        else if (i == 19)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦  SPACE drop    ▦";
        }
        else if (i == 6 || i == 10)
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦▦▦▦▦▦▦▦▦▦";
        }
        else
        {
            Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
            std::cout << "▦                    ▦                ▦";
        }
    }
    Coordination::GotoXY(posCheck_ + Coordination(0, i + 1));
    std::cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦";
}

void Tetris::InitNextBlock()
{
    BLOCK_TYPE tetromino_type = (BLOCK_TYPE)(rand() % TETROMINO_TYPE_COUNT);

    NextBlock = new Block(&tBoard, tetromino_type);
    NextBlock->SetBlockPos(next_block_init_pos);
}

void Tetris::PrepareNext()
{


    CurBlock->CheckBlockPos(posCheck_); 

    int EraseLineCount = tBoard.LineCheck(posCheck_); 
    if (EraseLineCount > 0)                 //if there is line need to be removed
        tScore.UpdateScore(posCheck_, EraseLineCount);  //update points
    if (CurBlock->CheckPlay()) //if the top block hit the very top
    {
        playCheck = false;  //game over
        Coordination::GotoXY(posCheck_ + Coordination(10, 10)); //display msg
        std::cout << " **game over***";
        _getch();
    }
    else //else keep playing
    {
        NextBlock->Block::DelBlock(posCheck_);  //delete nextblock since it will move to cur block
        GetNewBlock();  //next block becomes curblock
        CurBlock->InitBlock(posCheck_); //draw a block
        InitNextBlock();    //create new next block
        NextBlock->InitBlock(posCheck_);    //draw it
    }
    sTime = clock();
}