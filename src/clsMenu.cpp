
#include "clsMenu.h"

int clsMenu::init(clsScreen *s, clsMusic *m, clsEvent *e)
{
    screen = s;
    musicMenu = m;
    event = e;

    error.set(texto.init());
    if(error.get()) return error.get();
    error.set(texto.loadFont("FONTS/FreeMono.ttf", 30));
    if(error.get()) return error.get();

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

    return error.get();
}

int clsMenu::run()
{
    error.set(0);

    error.set(musicMenu->loadMusic("MUSIC/MENU.mp3"));
    if(error.get()) return error.get();

    musicMenu->playMusic(-1);
    setI(0);
    salir = false;

    while(!salir)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT)
            {
                musicMenu->closeMusic();
                return -1;
            }
            if(event->getEventType() == KEY_PRESSED)
            {
                switch(event->getKey())
                {
                    case KEY_ESCAPE:
                    {
                        musicMenu->closeMusic();
                        return -1;
                    }break;
                    case KEY_ENTER:
                    {
                        salir = true;
                    }break;
                    case KEY_UP:
                    {
                        if(getI() == 0)
                            setI(2);
                        else
                            setI(getI()-1);
                    }break;
                    case KEY_DOWN:
                    {
                        if(getI() == 2)
                            setI(0);
                        else
                            setI(getI()+1);
                    }break;
                }//Fin switch
            }//Fin if KEY_PRESSED
        }//Fin if wasEvent()
        paste(screen->getPtr());
        screen->refresh();
    }//Fin while

    musicMenu->closeMusic();
    if(getI() == 2)
        return -1;

    else if(getI() == 1)
    {
        char aux[5];
        int cant;
        if(puntajes.cantPuntajes()<10) cant = puntajes.cantPuntajes();
        else cant = 10;
        puntajes.cargarYordenar();
        screen->clean(YELLOW);
        for(int x=0; x<cant; x++)
        {
            puntajes.setI(x);

            texto.write(puntajes.getPuntaje().getNombre(), 50, x*50+20, screen->getPtr());

            itoa(puntajes.getPuntaje().getPuntos(), aux, 10);
            texto.write(aux, screen->getWidth()-50, x*50+20, screen->getPtr());
        }
        screen->refresh();

        event->wasEvent();
        while(event->getEventType() != KEY_PRESSED || event->getKey() != KEY_ESCAPE)
        {
            event->wasEvent();
            if(event->getEventType() == SDL_QUIT) return -1;
        }
        error.set(run());
        if(error.get()) return error.get();
    }

    return 0;
}













