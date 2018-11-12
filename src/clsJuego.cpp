#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;
    FRAMES_POR_SEGUNDO = 20;

    error.set(pajaro.init(screen));
    if(error.get()) return error.get();

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
        fps.start();
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
                case KEY_SPACE:
                    {

                    }break;
                case KEY_UP:
                    {
                        if(pajaro.getY()-50 >= 0)
                        {
                            pajaro.setY(pajaro.getY()-50);
                        }
                    }break;
                }//Fin switch
            }//Fin if KEY_PRESSED
//            pajaro.manejoEventos(event);
        }//Fin if wasEvent()

        if(fondo.getX()<-1000)
            fondo.setX(-150);
        else
            fondo.setX(fondo.getX()-15);
        fondo.paste(screen->getPtr());
        paredes.mover(15);
        paredes.mostrar();

        if(pajaro.getY()+pajaro.getHeight()+10 <= screen->getHeight())
            pajaro.setY(pajaro.getY()+10);
        if(paredes.seTocan(&pajaro))
            pajaro.setI(1);
        pajaro.paste(screen->getPtr());

        screen->refresh();


        if(fps.getState() < 1000/FRAMES_POR_SEGUNDO)
            SDL_Delay((1000/FRAMES_POR_SEGUNDO) - fps.getState());

    }//Fin while

    return error.get();
}
