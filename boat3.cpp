#include "boat3.h"

boat3::boat3(){
    HP=3;
    len=3;
    loc=new int[6];
    tabmod=new module[len];
    
}

boat3::boat3(int x1, int y1){
    HP=3;
    len=3;
    loc=new int[6];
    loc[0]=x1;
    loc[1]=y1;
    tabmod=new module[len];

}

boat3::~boat3(){
    delete [] tabmod;
    delete [] loc;
}

void boat3::wypiszloc(){
    cout<<loc[0]<<" "<<loc[1]<<" "<<loc[2]<<" "<<loc[3]<<" "<<loc[4]<<" "<<loc[5]<<endl;
}



void boat3::cord(string plansza[11][11]){
    int x1=loc[0];
    int y1=loc[1];
    int x2;
    int y2;
    int x3;
    int y3;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int a1;
    int a2;
    int b1;
    int b2;
    int c1;
    int c2;
    int d1;
    int d2;
    int e=0;
    while(e==0){
        
        x1=loc[0];
        y1=loc[1];
        //prawo

        if (x1+1<11){
            a1=x1+2;
            a2=y1;
        }
        else{
            a1=11;
        }
        //góra

        if(y1-1>0){
            b1=x1;
            b2=y1-2;
        }
        else{
            b1=11;
        }
        //lewo

        if(x1-1>0){
            c1=x1-2;
            c2=y1;
        }
        else{
            c1=11;
        }
        //dół

        if(y1+1<11){
            d1=x1;
            d2=y1+2;
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
        cin>>num;
        switch(num){
            case 1:
                if(a==1){
                    x3=a1;
                    y3=a2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 2:
                if(b==1){
                    x3=b1;
                    y3=b2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 3:
                if(c==1){
                    x3=c1;
                    y3=c2;
                    e=1;
                    break;
                }
                else{
                    cout<<"Zły numer"<<endl;
                    break;
                }
            case 4:
                if(d==1){
                    x3=d1;
                    y3=d2;
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
    loc[4]=x3;
    loc[5]=y3;
    int difx=x3-x1;
    int dify=y3-y1;
    if(difx==0){
        x2=x1;
    }
    if(difx<0){
        x2=x1-1;
    }
    if(difx>0){
        x2=x1+1;
    }
    if(dify==0){
        y2=y1;
    }
    if(dify<0){
        y2=y1-1;
    }
    if(dify>0){
        y2=y1+1;
    }
    loc[2]=x2;
    loc[3]=y2;

    pusto(x1,y1,plansza);
    pusto(x2,y2,plansza);
    pusto(x3,y3,plansza);

    plansza[x1][y1]="[#]";
    plansza[x2][y2]="[#]";
    plansza[x3][y3]="[#]";

}

void boat3::Set_mod(){
    module mod1(loc[0],loc[1]);
    module mod2(loc[2],loc[3]);
    module mod3(loc[4],loc[5]);
    tabmod[0]=mod1;
    tabmod[1]=mod2;
    tabmod[2]=mod3;
}