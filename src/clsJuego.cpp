#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;

    error.set(fondo.init());
    if(error.get()) return error.get();

    error.set(paredes.init(screen));
    if(error.get()) return error.get();

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    while(true)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == SDL_QUIT) return -1;
            if(event->getEventType() == KEY_PRESSED)
            {
                switch(event->getKey())
                {
                case KEY_ESCAPE:
                    {
                        return 0;
                    }break;
//                case KEY_RIGHT:
//                    {
//                        paredes.mover(20);
//                    }break;
                case KEY_LEFT:
                    {
                        paredes.mover(-20);
                    }break;
                }//Fin switch
            }//Fin if KEY_PRESSED
        }//Fin if wasEvent()

        while(event->getEventType() == KEY_PRESSED && event->getKey() == KEY_RIGHT)
        {
            if(fondo.getX()<-1000)
            {
                fondo.setX(-150);
            }
            else
            {
                fondo.setX(fondo.getX()-20);
            }
            fondo.paste(screen->getPtr());

            paredes.mover(20);
            paredes.mostrar();

            screen->refresh();

            event->wasEvent();
        }

        while(event->getEventType() == KEY_PRESSED && event->getKey() == KEY_LEFT)
        {
            fondo.setX(fondo.getX()+20);
            fondo.paste(screen->getPtr());

            paredes.mover(-20);
            paredes.mostrar();

            screen->refresh();

            event->wasEvent();
        }
        fondo.paste(screen->getPtr());

        paredes.mostrar();

        screen->refresh();
    }//Fin while

    return error.get();
}
