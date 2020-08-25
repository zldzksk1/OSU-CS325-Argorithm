//all the library included here

#ifndef	VALUE_HPP
#define VALUE_HPP

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

#define KEY_ESC 27
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)
#define KEY_SPACE ' '
#define EMPTY -1

#define B_WIDTH 10
#define B_HEIGHT 20


#define TETROMINO_TYPE_COUNT 7
#define ROTATE_COUNT 4

#define bblock 'U+23F9'

enum BLOCK_TYPE { BLOCK_I, BLOCK_J, BLOCK_L, BLOCK_O, BLOCK_S, BLOCK_T, BLOCK_Z };

#endif