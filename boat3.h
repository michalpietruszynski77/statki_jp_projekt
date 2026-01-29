#ifndef BOAT3_H
#define BOAT3_H

#include "module.h"
#include "boat2.h"

class module;
class gra;
class boat3: public boat2{
public:
boat3();
boat3(int x1, int y1);
void cord(string plansza[11][11]);
void Set_mod();
void wypiszloc();
void test(int t);
};


#endif
