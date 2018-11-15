#include "clsSalida.h"

int clsSalida::init(clsScreen *s, clsMusic *m, clsEvent* e, clsTimer *t)
{
    error.set(0);

    screen = s;
    music = m;
    event = e;
    timer = t;

    error.set(texto.init());
    if(error.get()) return error.get();
    error.set(texto.loadFont("FONTS/FreeMono.ttf",30));
    if(error.get()) return error.get();
    texto.setFontColor(WHITE);

    setItems(12);
    char ruta[]= "IMAGES/MAGOSALIDA/00.jpg";
    for(int d=0; d<2; d++)
    {
        ruta[18] = d + 48;
        for(int u=0; u<10; u++)
        {
            ruta[19] = u + 48;
            setI(d*10+u);

            error.set(load(ruta));
            if(error.get()) return error.get();

            if(d*10+u == 11)
                break;
        }
    }
    setI(0);

    return error.get();
}

void clsSalida::animar()
{
    paste(screen->getWidth()/2 - getWidth()/2,
          screen->getHeight()/2 - getHeight()/2,
           screen->getPtr());
    if(getI() == 11)
        setI(0);
    else
        setI(getI() + 1);
}

int clsSalida::run()
{
    error.set(0);

//    music->loadMusic("");
//    music->playMusic(-1);

    texto.write("Gracias por jugar!", 0, 0, screen->getPtr());

    while(true)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT || event->getKey() == KEY_ESCAPE)
            {
                music->closeMusic();
                return -1;
            }
            if(event->getKey() == KEY_ENTER)
            {
                music->closeMusic();
                return 0;
            }
        }
        timer->wait(150);
        screen->clean(BLACK);
        animar();
        texto.write("Gracias por jugar!",
                    screen->getWidth()/2 - texto.getWidth()/2,
                    screen->getHeight()-50,
                    screen->getPtr());
        screen->refresh();
    }

    return error.get();
}
