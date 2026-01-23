#include "boat2.h"
#include "boat.h"
#include "module.h"
#include "boat5.h"
#include "boat3.h"
#include "boat4.h"
#include "gra.h"





int main(){
string wynik="Wygrywa gracz 1";
string wynik2="Wygrywa gracz 2";
wsp w1;
boat2 bw;
int k=0;
int num;
gra g1, g2;
boat5 b151, b251;
boat4 b141, b241;
boat3 b131, b132, b231, b232;
boat2 b121,b122,b123, b221,b222,b223;
g1.start();
//Rozstawienie statków na planszy przez obu graczy
cout<<"Gracz 1"<<endl;
while (k==0){
    g1.wypisz_tabown();
    cout<<"Statek #####"<<endl;
    w1=bw.pocz(g1.tabown);
    b151.ustaw_wsp(w1.xw,w1.yw);
    b151.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ####"<<endl;
    w1=bw.pocz(g1.tabown);
    b141.ustaw_wsp(w1.xw,w1.yw);
    b141.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ###"<<endl;
    w1=bw.pocz(g1.tabown);
    b131.ustaw_wsp(w1.xw,w1.yw);
    b131.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ###"<<endl;
    w1=bw.pocz(g1.tabown);
    b132.ustaw_wsp(w1.xw,w1.yw);
    b132.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g1.tabown);
    b121.ustaw_wsp(w1.xw,w1.yw);
    b121.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g1.tabown);
    b122.ustaw_wsp(w1.xw,w1.yw);
    b122.cord(g1.tabown);
    g1.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g1.tabown);
    b123.ustaw_wsp(w1.xw,w1.yw);
    b123.cord(g1.tabown);
    g1.wypisz_tabown();;
    cout<<"Czy ustawienie jest właściwy?"<<endl;
    cout<<"1 -Ok"<<endl;
    cout<<"2 -Reset"<<endl;
    cout<<"Wybierz numer"<<endl;
    int e=0;
    while(e==0){
        cin>>num;
        switch(num){
            case 1:
                k=1;
                e=1;
                break;
            case 2:
                k=0;
                e=1;
                g1.reset();
                break;
            default:
                cout<<"Błąd, podaj właściwy numer"<<endl;
                break;
        }
    }
}
b151.Set_mod();
b141.Set_mod();
b131.Set_mod();
b132.Set_mod();
b121.Set_mod();
b122.Set_mod();
b123.Set_mod();
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"Gracz 2"<<endl;
k=0;
while (k==0){
    g2.wypisz_tabown();
    cout<<"Statek #####"<<endl;
    w1=bw.pocz(g2.tabown);
    b251.ustaw_wsp(w1.xw,w1.yw);
    b251.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ####"<<endl;
    w1=bw.pocz(g2.tabown);
    b241.ustaw_wsp(w1.xw,w1.yw);
    b241.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ###"<<endl;
    w1=bw.pocz(g2.tabown);
    b231.ustaw_wsp(w1.xw,w1.yw);
    b231.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ###"<<endl;
    w1=bw.pocz(g2.tabown);
    b232.ustaw_wsp(w1.xw,w1.yw);
    b232.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g2.tabown);
    b221.ustaw_wsp(w1.xw,w1.yw);
    b221.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g2.tabown);
    b222.ustaw_wsp(w1.xw,w1.yw);
    b222.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Statek ##"<<endl;
    w1=bw.pocz(g2.tabown);
    b223.ustaw_wsp(w1.xw,w1.yw);
    b223.cord(g2.tabown);
    g2.wypisz_tabown();
    cout<<"Czy ustawienie jest właściwy?"<<endl;
    cout<<"1 -Ok"<<endl;
    cout<<"2 -Reset"<<endl;
    cout<<"Wybierz numer"<<endl;
    int e=0;
    while(e==0){
        cin>>num;
        switch(num){
            case 1:
                k=1;
                e=1;
                break;
            case 2:
                k=0;
                e=1;
                g2.reset();
                break;
            default:
                cout<<"Błąd, podaj właściwy numer"<<endl;
                break;
        }
    }
}
b251.Set_mod();
b241.Set_mod();
b231.Set_mod();
b232.Set_mod();
b221.Set_mod();
b222.Set_mod();
b223.Set_mod();
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
g1.przygotowanie();
g2.przygotowanie();
int e=0;
//Początek gry
while(2>1){
    e=0;
    while(e==0){
        cout<<"Strzela Gracz 1"<<endl;
        g1.wypisz_tabop();
        w1=g1.shot(g2);
        b251.check(w1, g2);
        b241.check(w1,g2);
        b231.check(w1,g2);
        b232.check(w1,g2);
        b221.check(w1,g2);
        b222.check(w1,g2);
        b223.check(w1,g2);
        if(g2.get_n_boats()==0){
            cout<<"Koniec gry"<<endl;
            cout<<"Wygrywa Gracz 1"<<endl;
            g1.wyniki(wynik);
            return 0;
        }
        if(g1.tabop[w1.xw][w1.yw]!="[X]"){
            e=1;
        }
    }
    e=0;
    while(e==0){
        cout<<"Strzela Gracz 2"<<endl;
        g2.wypisz_tabop();
        w1=g2.shot(g1);
        b151.check(w1, g1);
        b141.check(w1,g1);
        b131.check(w1,g1);
        b132.check(w1,g1);
        b121.check(w1,g1);
        b122.check(w1,g1);
        b123.check(w1,g1);
        if(g1.get_n_boats()==0){
            cout<<"Koniec gry"<<endl;
            cout<<"Wygrywa Gracz 2"<<endl;
            g1.wyniki(wynik2);
            return 0;
        }
        if(g2.tabop[w1.xw][w1.yw]!="[X]"){
            e=1;
        }
    }
}



}