#include "clsMenu.h"

int clsMenu::init(clsScreen *s, clsMusic *m, clsEvent *e, clsTimer *t)
{
    screen = s;
    music = m;
    event = e;
    timer = t;

    error.set(music->loadMusic("MUSIC/MENU.mp3"));
    if(error.get()) return error.get();

    error.set(texto.init());
    if(error.get()) return error.get();

    error.set(texto.loadFont("FONTS/FreeMono.ttf",30));
    if(error.get()) return error.get();

    texto.setFontColor(WHITE);

    setItems(3);
    char ruta[]= "IMAGES/MENUINTRO/00.jpg";
    for(int d=0; d<2; d++)
    {
        ruta[17] = d + 48;
        for(int u=0; u<10; u++)
        {
            ruta[18] = u + 48;
            setI(d*10+u);

            error.set(load(ruta));
            if(error.get())
                return error.get();

            if(d*10+u == 13)
                break;
        }
    }
    setI(0);

    return error.get();
}

void clsMenu::opciones()
{
    paste(screen->getPtr());
    if(getI() == 13)
        setI(0);
    else
        setI(getI() + 1);
}

int clsMenu::run()
{
    error.set(0);

    music->playMusic(-1);

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
        opciones();
        screen->refresh();
    }

    return 0;
}











