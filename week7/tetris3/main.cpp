//Sangyun Lee
//CS325
//I referred and adopted the code from below
//https://www.youtube.com/watch?v=hozswFmo_iI (youtube video lecture from Assort Rock Game Academy), 
//https://www.youtube.com/watch?v=8OK8_tHeCIA
//https://github.com/Limjingyu/Tetris
//https://m.blog.naver.com/PostView.nhn?blogId=azure0777&logNo=220331180138&proxyReferer=https:%2F%2Fwww.google.com%2F
//https://seokjin2.tistory.com/35
//


#include "Tetris.hpp"
#include "value.hpp"


int main()
{
	srand(time(NULL));		// generate random number
	int input;

	std::cout << "---------- Testris ---------- " << std::endl;
	std::cout << " 1. start" << std::endl;
	std::cout << " 2. quit" << std::endl;
	std::cin >> input;

	system("cls");

	if (input == 1)         // start game
    {			
		Tetris tetris(Coordination(0, 0));
		tetris.Run();
	}
	else                    // quit
    {		
		return 0;
	}

    return 0;
}
