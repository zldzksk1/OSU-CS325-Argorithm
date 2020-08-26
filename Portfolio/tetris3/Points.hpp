	#ifndef POINTS_HPP
	#define POINTS_HPP

	#include "value.hpp"
	#include "Coordination.hpp"

	class Points 
	{
	public :
		Points();
		int gameLevel();
		void UpdateScore(Coordination posCheck, int lineBreak);   
		void Display(Coordination posCheck);

	private :
		int points;	//store points
		int level;  //game level
		bool marks;
		Coordination pointsPos;
		Coordination levelPos;
		Coordination totalPos;
	};

	#endif