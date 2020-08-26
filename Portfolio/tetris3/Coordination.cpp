#include "Coordination.hpp"
using namespace std;

int Coordination::GetX() const		//return x coordination
{
	return xpos;
}

int Coordination::GetY() const		//return y coordination
{
	return ypos;
}

void Coordination::SetX(int x)		//set x and y coordination
{
	xpos = x;
}

void Coordination::SetY(int y)
{
	ypos = y;
}

Coordination Coordination::operator+(const Coordination&pt)		// class opperator
{
	return Coordination(xpos + pt.xpos, ypos + pt.ypos);
}

Coordination Coordination::operator-(const Coordination& pt)	
{
	return Coordination(xpos - pt.xpos, ypos - pt.ypos);
}

void Coordination::GotoXY(int x, int y)		
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//control cursor
}

void Coordination::GotoXY(Coordination pos)
{
	GotoXY(pos.GetX(), pos.GetY());
}

Coordination Coordination::GetScreenpos(const Coordination &pos)	//Change the array position to Screen Coordination
{
	return Coordination(2 * pos.xpos + 2, (-1) * pos.ypos + 20);	//Since the block size two bytes and the other char is 1bytes, for time 2 on X
}																	//if (-1) times to the block can be down from top