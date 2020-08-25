#include "value.hpp"

#ifndef COORDINATION_HPP
#define COORDINATION_HPP

class Coordination 
{
private:
	int xpos;	//x coordnation
	int ypos;	//y coordination

public :
	Coordination(int x = -1, int y = -1) : xpos(x), ypos(y) {} //defalt constructor
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	static void GotoXY(int x, int y);
	static void GotoXY(Coordination pos);
	static Coordination GetScreenpos(const Coordination&pos);
	Coordination operator-(const Coordination& pt);	//remove if error
	Coordination operator+(const Coordination& pt);

};

#endif