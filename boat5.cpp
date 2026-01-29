#include "boat5.h"

boat5::boat5(){
    HP=5;
    len=5;
    loc=new int[10];
    tabmod=new module[len];
}

boat5::boat5(int x1, int y1){
    HP=5;
    loc=new int[10];
    len=5;
    loc[0]=x1;
    loc[1]=y1;
    tabmod=new module[len];

}


void boat5::wypiszloc(){
    cout<<loc[0]<<" "<<loc[1]<<" "<<loc[2]<<" "<<loc[3]<<" "<<loc[4]<<" "<<loc[5]<<" "<<loc[6]<<" "<<loc[7]<<" "<<loc[8]<<" "<<loc[9]<<" "<<endl;
}

void boat5::cord(string plansza[11][11]){
    int x1=loc[0];
    int y1=loc[1];
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;
    int x5;
    int y5;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int a1;
    int a2;
    int b1;
    int b2;
    int c1;
    int c2;
    int d1;
    int d2;
    while(e==0){
        
        x1=loc[0];
        y1=loc[1];
        //prawo

        if (x1+4<11){
            a1=x1+4;
            a2=y1;
        }
        else{
            a1=11;
        }
        //góra

        if(y1-4>0){
            b1=x1;
            b2=y1-4;
        }
        else{
            b1=11;
        }
        //lewo

        if(x1-4>0){
            c1=x1-4;
            c2=y1;
        }
        else{
            c1=11;
        }
        //dół

        if(y1+4<11){
            d1=x1;
            d2=y1+4;
        }
        else{
            d1=11;
        }
        cout<<"Wybierz numer"<<endl;
        

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
    int num;
    e=0;
    while(e==0){
        if (!(cin>>num)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Błąd, podaj numer"<<endl;
            continue;
        }
        switch(num){
            case 1:
                if(a==1){
                    x5=a1;
                    y5=a2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 2:
                if(b==1){
                    x5=b1;
                    y5=b2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 3:
                if(c==1){
                    x5=c1;
                    y5=c2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 4:
                if(d==1){
                    x5=d1;
                    y5=d2;
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
    loc[8]=x5;
    loc[9]=y5;
    int difx=x5-x1;
    int dify=y5-y1;
    if(difx==0){
        x2=x1;
        x3=x1;
        x4=x1;
    }
    if(difx<0){
        x2=x1-1;
        x3=x1-2;
        x4=x1-3;
    }
    if(difx>0){
        x2=x1+1;
        x3=x1+2;
        x4=x1+3;
    }
    if(dify==0){
        y2=y1;
        y3=y1;
        y4=y1;
    }
    if(dify<0){
        y2=y1-1;
        y3=y1-2;
        y4=y1-3;
    }
    if(dify>0){
        y2=y1+1;
        y3=y1+2;
        y4=y1+3;
    }
    loc[2]=x2;
    loc[3]=y2;
    loc[4]=x3;
    loc[5]=y3;
    loc[6]=x4;
    loc[7]=y4;
    pusto(x1,y1,plansza);
    pusto(x2,y2,plansza);
    pusto(x3,y3,plansza);
    pusto(x4,y4,plansza);
    pusto(x5,y5,plansza);
    plansza[x1][y1]="[#]";
    plansza[x2][y2]="[#]";
    plansza[x3][y3]="[#]";
    plansza[x4][y4]="[#]";
    plansza[x5][y5]="[#]";
}
void boat5::Set_mod(){
    module mod1(loc[0],loc[1]);
    module mod2(loc[2],loc[3]);
    module mod3(loc[4],loc[5]);
    module mod4(loc[6],loc[7]);
    module mod5(loc[8],loc[9]);
    tabmod[0]=mod1;
    tabmod[1]=mod2;
    tabmod[2]=mod3;
    tabmod[3]=mod4;
    tabmod[4]=mod5; 
}
void boat5::test(){
    loc[0]=2;
    loc[1]=2;
    loc[2]=3;
    loc[3]=2;
    loc[4]=4;
    loc[5]=2;
    loc[6]=5;
    loc[7]=2;
    loc[8]=6;
    loc[9]=2;

}
