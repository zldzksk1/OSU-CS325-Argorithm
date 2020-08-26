#include "Keyhandle.hpp"

//return key info
int Keyhandle::Getkey_up()
{
	return k_up;
}

int Keyhandle::Getkey_down()
{
	return k_down;
}

int Keyhandle::Getkey_right()
{
	return k_right;
}

int Keyhandle::Getkey_left()
{
	return k_left;
}


int Keyhandle::Getkey_space()
{
	return k_space;
}

int Keyhandle::Getkey_esc()
{
	return k_quite;
}

void Keyhandle::SetKeyboard(int up, int down, int right, int left, int space, int esc)
{
	k_up = up;
	k_down = down;
	k_right = right;
	k_left = left;
	k_space = space;
	k_quite = esc;

}

int Keyhandle::GetKey(void)	//get user input
{
	int ch = _getch();			

	if (ch == 0 || ch == 224)	
		ch = 256 + _getch();	
								
	return ch;
}