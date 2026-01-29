#include "gra.h"

//Metoda wyświetlająca opcje start/instrukcja na początku programu.
int start(){
    int num;
    int e=0;
    string p;
    while(e==0){
        cout<<"Wybierz numer"<<endl<<"1 -Start"<<endl<<"2 -Instrukcja"<<endl<<"3 -Test programu"<<endl;
        if (!(cin>>num)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Błąd, podaj numer"<<endl;
            continue;
        }
            switch(num){
                case 1:
                    e=1;
                    return 0;
                    break;
                case 2:
                    cout<<"Program to gra w statki PvP. Na początku gry każdy z graczy ustawia po kolei swoje statki, najpierw wpisując współrzędne początku statku, a następnie wybierając z opcji"<<endl<<"wyświetlonych na terminalu współrzędne końca statku. Po ustawieniu wszystkich statków możliwy jest reset planszy i ponowne rozstawienie. Kiedy obaj gracze rozstawią swoje statki rozpoczyna się"<<endl<<"gra. Gracze strzelają na zmianę wpisując współrzędne strzału. Jeżeli gracz trafił statek przeciwnika, strzela dalej, aż spudłuje. Gra toczy się do momentu aż któremuś z graczy nie zostanie już"<<endl<<"żaden niezatopiony statek. Wynik gry zapisywany jest do pliku wyniki.txt"<<endl<<"Wpisz dowolny znak aby kontynuować"<<endl;
                    cin>>p;
                    e=1;
                    return 0;
                    break;
                case 3:
                    e=1;
                    return 2;
                    break;
                default:
                    cout<<"Zły numer"<<endl;
                    e=0;
                    break;

            }
    }
    return 0;
}
//Klasa sterująca oddawaniem strzałów oraz przechowująca i wyświetlająca plansze obu graczy.
gra::gra():
    tabown{{"[X]","[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]","[10]"},
    {"[A]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[B]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[C]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[D]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[E]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[F]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[G]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[H]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[I]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[J]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"}},
    tabop{{"[X]","[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]","[10]"},
    {"[A]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[B]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[C]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[D]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[E]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[F]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[G]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[H]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[I]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"},
    {"[J]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]","[~]"}}
{
    n_boats=7;
}

//Metoda odpowiedzialna za strzał oraz sprawdzenie jego celności. Zwraca współrzędne strzału.
wsp gra::shot(gra &g){
    wsp w;
    string s;
    cout<<"Podaj współrzędne strzału"<<endl;
    while(2>1){
        cout<<"Wybierz rząd, wpisz literę"<<endl;
        w.xw=slownik();
        cout<<"Wybierz kolumnę, wpisz cyfrę"<<endl;
        cin>>w.yw;
        if((w.xw>0)&&(w.yw>0)&& (w.xw<11)&&(w.yw<11)){
            if(tabop[w.xw][w.yw]=="[~]"){
                if(g.tabown[w.xw][w.yw]=="[~]"){
                    tabop[w.xw][w.yw]="[*]";
                    cout<<"Nie trafiony"<<endl;
                    return w;
                }
                if(g.tabown[w.xw][w.yw]=="[#]"){
                    tabop[w.xw][w.yw]="[X]";
                    cout<<"Trafiony"<<endl;
                    return w;
                }
                else{
                    cout<<"Złe współrzędne, podaj inne"<<endl;
                }
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

//Metody wypisujące plansze odpowiednio swoją i przeciwnika.
void gra::wypisz_tabop(){ 
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            cout<<tabop[i][j];
        }
        cout<<endl;
        }
}

void gra::wypisz_tabown(){ 
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
        cout<<tabown[i][j];
        }
    cout<<endl;
    }
}

void gra::zatopiony(){
    n_boats--;
}

int gra::get_n_boats(){
    return n_boats;
}

//Metoda resetująca planszę po wybraniu takiej opcji przez gracza podczas rozstawiania statków.
void gra::reset(){
    for (int i=0; i<11;i++){
        for(int j=0;j<11;j++){
            tabown[i][j]="[~]";
        }
    }
    tabown[0][0]="[X]";
    tabown[0][1]="[1]";
    tabown[0][2]="[2]";
    tabown[0][3]="[3]";
    tabown[0][4]="[4]";
    tabown[0][5]="[5]";
    tabown[0][6]="[6]";
    tabown[0][7]="[7]";
    tabown[0][8]="[8]";
    tabown[0][9]="[9]";
    tabown[0][10]="[10]";
    tabown[1][0]="[A]";
    tabown[2][0]="[B]";
    tabown[3][0]="[C]";
    tabown[4][0]="[D]";
    tabown[5][0]="[E]";
    tabown[6][0]="[F]";
    tabown[7][0]="[G]";
    tabown[8][0]="[H]";
    tabown[9][0]="[I]";
    tabown[10][0]="[J]";
    
}

//Metoda przygotowująca planszę do właściwej rozgrywki.
void gra::przygotowanie(){
    for(int i=0; i<11;i++){
        for(int j=0; j<11; j++){
            if(tabown[i][j]=="[+]"){
                tabown[i][j]="[~]";
            }
        }
    }
}

//Metoda zapisująca wynik gry do pliku wyniki.txt.
void gra::wyniki(string wynik){
    ofstream ofile;
    ofile.open("wyniki.txt", ios::app);
    if(!ofile.is_open()){//sprawdzenie czy udało się poprawnie otworzyć plik
    cout<<"Nie udało się otworzyć pliku"<<endl;}
    ofile<<wynik<<endl;
    ofile.close();
}



//Metoda tłumacząca litery na liczby odpowiadające rzędom.
int gra::slownik(){
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

void gra::test(){
    tabown[2][2]="[#]",tabown[3][2]="[#]",tabown[4][2]="[#]",tabown[5][2]="[#]",tabown[6][2]="[#]",tabown[2][5]="[#]",tabown[2][6]="[#]",tabown[2][7]="[#]",tabown[2][8]="[#]",tabown[5][4]="[#]",tabown[6][4]="[#]",tabown[7][4]="[#]",tabown[8][7]="[#]",tabown[8][8]="[#]",tabown[8][9]="[#]",tabown[9][2]="[#]",tabown[9][3]="[#]",tabown[9][5]="[#]",tabown[10][5]="[#]",tabown[5][8]="[#]",tabown[6][8]="[#]";
}