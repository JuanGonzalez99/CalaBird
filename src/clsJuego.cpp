#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;

    error.set(pajaro.init());
    if(error.get()) return error.get();

    return error.get();
}

int clsJuego::run()
{
    error.set(0);



    return error.get();
}
