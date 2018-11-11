#include "clsMotor.h"

int clsMotor::init()
{
    error.set(0);

    error.set(mode.init(DEFAULT));
    if(error.get()) return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get()) return error.get();

    error.set(audio.init());
    if(error.get()) return error.get();

    error.set(texto.init());
    if(error.get()) return error.get();

    error.set(intro.init(&screen, &music, &event, &timer));
    if(error.get()) return error.get();

    error.set(menu.init(&screen, &music, &event));
    if(error.get()) return error.get();

    error.set(juego.init(&screen, &event, &music));
    if(error.get()) return error.get();

//    error.set(salida.init(&screen, &music, &event, &timer));
//    if(error.get()) return error.get();

    return error.get();
}

int clsMotor::run()
{
    error.set(intro.run());
    if(error.get() > 0) return error.get();
    if(error.get() < 0) return 0;

    error.set(menu.run());
    if(error.get() > 0) return error.get();
    if(error.get() < 0) return 0;

//    error.set(salida.run());
//    if(error.get() > 0) return error.get();
//    if(error.get() < 0) return 0;

    return error.get();
}

