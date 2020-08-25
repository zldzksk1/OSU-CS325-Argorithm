#include "Points.hpp"


Points::Points()
{
    points = 0;
	level = 1;
	marks = false;
	pointsPos = Coordination(28, 9);
	levelPos = Coordination(26, 10);
}


int Points::gameLevel()	//return game level
{
	return level;
}

void Points::Display(Coordination posCheck)
{
	if (points >= 500)
	{
		points = 0;
		level ++;
	}
	if (marks == false)								//Display point position
	{
		Coordination::GotoXY(posCheck + levelPos);
		Coordination::GotoXY(posCheck + pointsPos);
		std::cout << "Lv " << level;
		std::cout << std::setw(5) << points;
		marks = true;
	}
	else if (marks == true)							//updates points on screen
	{
		Coordination::GotoXY(posCheck - 2 + levelPos - 1);
		Coordination::GotoXY(posCheck + pointsPos - 1);
		std::cout << " ";
		std::cout << "Lv " << level;
		std::cout << std::setw(5) << points;
	}

}

void Points::UpdateScore(Coordination posCheck, int lineBreak)	//updates points you earn
{
	if (lineBreak == 1)		//based on the number of lines you break, points are different
	{
		points += 50;
	}
	else if (lineBreak == 2)
	{
		points += 100;
	}
	else if (lineBreak == 3)
	{
		points += 200;
	}
	else if (lineBreak == 4)
	{
		points += 400;
	}
		
	Display(lineBreak);
}

