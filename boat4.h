#ifndef BOAT4_H
#define BOAT4_H

#include "module.h"
#include "boat2.h"

class module;
class gra;
class boat4: public boat2{
public:
boat4();
boat4(int x1, int y1);
void cord(string plansza[11][11]);
void Set_mod();
void wypiszloc();
~boat4();
void test();
};


#endif