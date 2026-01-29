#ifndef BOAT5_H
#define BOAT5_H

#include "module.h"
#include "boat2.h"

class module;
class gra;
class boat5: public boat2{
public:
boat5();
boat5(int x1, int y1);
void cord(string plansza[11][11]);
void Set_mod();
void wypiszloc();
void test();
};


#endif
