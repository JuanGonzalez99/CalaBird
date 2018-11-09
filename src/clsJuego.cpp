#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;

    return error.get();
}

int clsJuego::run()
{
    error.set(0);



    return error.get();
}
