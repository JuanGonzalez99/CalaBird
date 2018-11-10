#include "clsParedes.h"

int clsParedes::init(clsScreen *scr)
{
    screen = scr;
    cantParedes = 100;
    distHorizontal = 300;
    distVertical = 128;

    random.init();

    inferiores = new clsPared[cantParedes];
    if(inferiores == NULL) return 2;

    superiores = new clsPared[cantParedes];
    if(superiores == NULL) return 2;

    for(int x=0; x<cantParedes; x++)
    {
        error.set(superiores[x].init());
        if(error.get()) return error.get();

        error.set(inferiores[x].init());
        if(error.get()) return error.get();

        superiores[x].setY(random.getNumber(screen->getHeight()-distVertical*2)+distVertical-screen->getHeight());
        superiores[x].setX(distHorizontal*x);

        inferiores[x].setY(superiores[x].getY()+screen->getHeight()+distVertical);
        inferiores[x].setX(distHorizontal*x);
    }

    return 0;
}

void clsParedes::mostrar()
{
    for(int x=0; x<cantParedes; x++)
    {
        superiores[x].paste(screen->getPtr());
        inferiores[x].paste(screen->getPtr());
    }
}

void clsParedes::mover(int dist)
{
    for(int x=0; x<cantParedes; x++)
    {
        superiores[x].setX(superiores[x].getX()-dist);
        inferiores[x].setX(inferiores[x].getX()-dist);
    }
}

clsParedes::~clsParedes()
{
//    delete inferiores;
//    delete superiores;
}
