#include "boat2.h"
#include "gra.h"

//Podstawowa klasa definiująca statki. Pozostałe klasy definiujące statki innej długości są po niej dziedziczone. Odpowiada za ustawienie statków na planszy oraz
// sprawdzenie czy trafienie zatopiło statek.

void boat2::wypiszloc(){
    cout<<loc[0]<<" "<<loc[1]<<" "<<loc[2]<<" "<<loc[3]<<" "<<endl;
}

boat2::~boat2(){
    delete [] tabmod;
    delete [] loc;
}

boat2::boat2(){
    HP=2;
    loc=new int[4];
    len=2;
    tabmod=new module[len];
    
}
boat2::boat2(int x1, int y1){
    HP=2;
    loc=new int[4];
    len=2;
    tabmod=new module[len];
    loc[0]=x1;
    loc[1]=y1;
}

//Metoda zajmująca pola wokół ustawionego statku, uniemożliwiająca ustawienie statków obok siebie.
void boat2::pusto(int xp, int yp,string plansza[11][11]){
    for(int i=-1;i<2;i++){
    for(int j=-1; j<2; j++){
        if(xp+i>0){
            if(xp+i<11){
                if(yp+j>0){
                    if(yp+j<11){
                        plansza[xp+i][yp+j]="[+]";
                    }
                }
            }
        }
    }
    }
}


//Główna funkcja odpowiedzialna za ustawienie statków na planszy i znalezienie dla nich "legalnych" współrzędnych.
void boat2::cord(string plansza[11][11]){
    int e=0;
    int x1;
    int y1;
    int x2;
    int y2;
    int a1;
    int a2;
    int b1;
    int b2;
    int c1;
    int c2;
    int d1;
    int d2;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    while(e==0){
        
        x1=loc[0];
        y1=loc[1];
        //Wyliczenie proponowanych współrzędnych końca statku oraz sprawdzenie ich "legalności".
        //prawo

        if (x1+1<11){
            a1=x1+1;
            a2=y1;
        }
        else{
            a1=11;
        }
        //góra

        if(y1-1>0){
            b1=x1;
            b2=y1-1;
        }
        else{
            b1=11;
        }
        //lewo

        if(x1-1>0){
            c1=x1-1;
            c2=y1;
        }
        else{
            c1=11;
        }
        //dół

        if(y1+1<11){
            d1=x1;
            d2=y1+1;
        }
        else{
            d1=11;
        }
        cout<<"Wybierz numer"<<endl;
        
        //Sprawdzenie czy współrzędne są odpowiednie
        if(a1!=11){
            if(plansza[a1][a2]=="[~]"){
            cout<<"1 x= "<<slownik2(a1)<<", y= "<<a2<<endl;
            a=1;
        }}
        
        if(b1!=11){
            if(plansza[b1][b2]=="[~]"){
            cout<<"2 x= "<<slownik2(b1)<<", y= "<<b2<<endl;
            b=1;
        }}
        
        if(c1!=11){
            if(plansza[c1][c2]=="[~]"){
            cout<<"3 x= "<<slownik2(c1)<<", y= "<<c2<<endl;
            c=1;
        }}
        
        if(d1!=11){
            if(plansza[d1][d2]=="[~]"){
            cout<<"4 x= "<<slownik2(d1)<<", y= "<<d2<<endl;
            d=1;
        }}
    //Sprawdzenie czy dla tego ustawienia początku statku istnieje możliwe ustawienie końca.
        if(a+b+c+d==0){
            cout<<"Złe współrzędne początkowe"<<endl;
            wsp w=pocz(plansza);
            loc[0]=w.xw;
            loc[1]=w.yw;
            e=0;
        }
        else{
            e=1;
        }
    }
    //Wybór współrzędnych końca statku z dostępnych opcji.
    int num;
    e=0;
    while(e==0){
        cin>>num;
        switch(num){
            case 1:
                if(a==1){
                    x2=a1;
                    y2=a2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 2:
                if(b==1){
                    x2=b1;
                    y2=b2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 3:
                if(c==1){
                    x2=c1;
                    y2=c2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 4:
                if(d==1){
                    x2=d1;
                    y2=d2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            default:
                cout<<"Zły numer"<<endl;
                break;
    }
        
    }
    loc[2]=x2;
    loc[3]=y2;
    pusto(x1,y1,plansza);
    pusto(x2,y2,plansza);
    plansza[x1][y1]="[#]";
    plansza[x2][y2]="[#]";
}

//Metoda ustawiająca współrzędne modułom
void boat2::Set_mod(){
    module mod1(loc[0],loc[1]);
    module mod2(loc[2],loc[3]);
    tabmod[0]=mod1;
    tabmod[1]=mod2;
}



//Metoda odpowiedzialna za pobranie od gracza współrzędnych początku statku
wsp boat2::pocz(string plansza[11][11]){
    wsp w;
    cout<<"Podaj współrzędne początku"<<endl;
    while(2>1){
        cout<<"Wybierz rząd, wpisz literę"<<endl;
        w.xw=slownik();//Zamiana litery na liczbę
        cout<<"Wybierz kolumnę, wpisz cyfrę"<<endl;
        cin>>w.yw;
        if((w.xw>0)&&(w.yw>0)&& (w.xw<11)&&(w.yw<11)){
            if(plansza[w.xw][w.yw]=="[~]"){//sprawdzenie czy wybrane współrzędne mieszczą się na planszy i czy nie znajdują się na zajętym polu
                return w;
                break;
            }
            else{
                cout<<"Złe współrzędne, podaj inne"<<endl;
            }
        }
        else{
            cout<<"Złe współrzędne, podaj inne"<<endl;
        }
    }

}

module boat2::get_mod(int k){
    return tabmod[k];
}

//Metoda sprawdzająca, czy strzał trafił oraz czy zatopił statek.
void boat2::check(wsp w, gra &g){
    for(int i=0;i<len;i++){

        if(tabmod[i].xm==w.xw){
            if(tabmod[i].ym==w.yw){
                tabmod[i].cm=0;
                HP--;
                if(HP==0){//sprawdzenie czy statek został zatopiony
                    cout<<"Zatopiony"<<endl;
                    g.zatopiony();
                }
                break;
            }
        }
    }
    
}

void boat2::ustaw_wsp(int x, int y){
    loc[0]=x;
    loc[1]=y;
}

//Metoda tłumacząca litery na liczby odpowiadające rzędom.
int boat2::slownik(){
    string l;

    while(2>1){
        cin>>l;
            if(l=="A"||l=="a"){
            return 1;}
            if(l=="B"||l=="b"){
            return 2;}
            if(l=="C"||l=="c"){
            return 3;}
            if(l=="D"||l=="d"){
            return 4;}
            if(l=="E"||l=="e"){
            return 5;}
            if(l=="F"||l=="f"){
            return 6;}
            if(l=="G"||l=="g"){
            return 7;}
            if(l=="H"||l=="h"){
            return 8;}
            if(l=="I"||l=="i"){
            return 9;}
            if(l=="J"||l=="j"){
            return 10;}
            else{
            cout<<"Błąd, podaj właściwą literę"<<endl;
            }

    }
}

//Metoda tłumacząca liczby na litery odpowiadające rzędom.
string boat2::slownik2(int l){
    switch(l){
        case 1:
        return "A";   
        case 2:
        return "B";
        case 3:
        return "C";
        case 4:
        return "D";
        case 5:
        return "E";
        case 6:
        return "F";
        case 7:
        return "G";
        case 8:
        return "H";
        case 9:
        return "I";
        case 10:
        return "J";
    }
    return 0;
}