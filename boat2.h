#ifndef BOAT2_H
#define BOAT2_H
#include <iostream>
#include "module.h"
using namespace std;
class module;
class gra;

//Struktura zawierająca współrzędne x, y
struct wsp{
    int xw=0;
    int yw=0;
};

class boat2{
protected:
int len;//Długość statku
int HP;//Ilość nieuszkodzonych modułów
int *loc;//Tabela zawierająca współrzędne modułów
module *tabmod;//Tabela zawierająca moduły statku
public:
boat2();
boat2(int x1, int y1);
void cord(string plansza[11][11]);
void Set_mod();
virtual ~boat2();
void pusto(int xp, int yp,string plansza[11][11]);
void wypiszloc();
wsp pocz(string plansza[11][11]);
module get_mod(int k);
void check(wsp w, gra &g);
void ustaw_wsp(int x, int y);
int slownik();
string slownik2(int l);
};



#endif