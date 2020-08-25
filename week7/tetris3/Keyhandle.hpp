#ifndef KEYHANDLE_HPP
#define KEYHANDLE_HPP

#include "value.hpp"


class Keyhandle 
{

private:
    int k_up;       //variable represent the direction buttons on the keyboard
    int k_down;
    int k_right;         
    int k_left;          
    int k_space;			
    int k_quite;

public :        //get key
    int Getkey_up();
    int Getkey_down();
    int Getkey_right(); 
    int Getkey_left(); 
    int Getkey_space(); 
    int Getkey_esc();

    void SetKeyboard(int up, int down, int right, int left, int space, int esc);
    static int GetKey();    
};

#endif