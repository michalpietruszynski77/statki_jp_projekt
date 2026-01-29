#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "module.h"
#include "boat2.h"

struct wsp;
class module;
class gra{
int n_boats;//Liczba niezatopionych statków
public:
gra();
string tabown[11][11];//Plansza gracza
string tabop[11][11];//Plansza przeciwnika
wsp shot(gra &g);
void wypisz_tabop();
void wypisz_tabown();
void zatopiony();
int get_n_boats();
void reset();
void przygotowanie();
void wyniki(string wynik);
void test();
int slownik();
};
int start();


#endif