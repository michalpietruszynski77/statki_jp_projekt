#include "module.h"
//Klasa zawierająca współrzędne modułu oraz jego stan(trafiony/nietrafiony)
module::module(){
    xm=0;
    ym=0;
    cm=1;

}
module::module(int xmm, int ymm){
    xm=xmm;
    ym=ymm;
    cm=1;
}

void module::wypiszmod(){
    cout<<xm<<" "<<ym<<" "<<cm<<endl;
}