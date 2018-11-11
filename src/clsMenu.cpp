#include "clsMenu.h"

int clsMenu::init(clsScreen *s, clsMusic *m, clsEvent *e)
{
    screen = s;
    musicMenu = m;
    event = e;

    setItems(3);
    char ruta[]= "IMAGES/MENUINTRO/00.png";
    for(int d=0; d<1; d++)
    {
        ruta[17] = d + 48;
        for(int u=0; u<10; u++)
        {
            ruta[18] = u + 48;
            setI(d*10+u);

            error.set(load(ruta));
            if(error.get())
                return error.get();

            if(d*10+u == 2)
                break;
        }
    }
    setI(0);

    return error.get();
}

void clsMenu::opciones()
{
    paste(screen->getPtr());
    if(getI() == 3)
        setI(0);
    else
        setI(getI() + 1);
}

int clsMenu::run()
{
    error.set(0);

  error.set(musicMenu->loadMusic("MUSIC/MENU.mp3"));
  if(error.get()) return error.get();

    musicMenu->playMusic(-1);

    while(true)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT || event->getKey() == KEY_ESCAPE)
            {
                musicMenu->closeMusic();
                return -1;
            }
            if(event->getKey() == KEY_ENTER)
            {
                musicMenu->closeMusic();
                return 0;
            }
        }
        opciones();
        screen->refresh();
    }

    return 0;
}











