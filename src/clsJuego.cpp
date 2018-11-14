#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;
    FRAMES_POR_SEGUNDO = 20;

    error.set(puntaje.init());
    if(error.get()) return error.get();
    error.set(puntaje.loadFont("FONTS/FreeSans.ttf", 30));
    if(error.get()) return error.get();

    error.set(texto.init());
    if(error.get()) return error.get();
    error.set(texto.loadFont("FONTS/FreeSans.ttf", 60));
    if(error.get()) return error.get();

    error.set(pajaro.init());
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
            if(event->getEventType() == SDL_QUIT)
                return -1;
            if(event->getKey() == KEY_ESCAPE)
                return 0;
            pajaro.manejoEventos(event);
        }

        //Manejo de fondo y paredes
        if(fondo.getX()<-1000)
            fondo.setX(-150);
        else
            fondo.setX(fondo.getX()-15);
        fondo.paste(screen->getPtr());
        paredes.mover(15);
        paredes.mostrar();

        //Manejo de puntaje
        puntaje.mostrar(paredes.pasadas(&pajaro), screen->getWidth()-100, 75, screen->getPtr());

        //Manejo del pajaro
        if(!pajaro.getSubir() || pajaro.getI() == 1)
        {
            if(pajaro.getY()+pajaro.getHeight()+10 <= screen->getHeight())
                pajaro.setY(pajaro.getY()+10);
        }
        else
        {
            if(pajaro.getY()-10 >= 0)
                pajaro.setY(pajaro.getY()-10);
        }
        if(paredes.seTocan(&pajaro))//Verificamos si el pajaro se choco con una pared
            pajaro.setI(1);

        if(pajaro.getI() == 1)      //Si el pajaro esta "muerto", hacemos que se mueva con el fondo
            pajaro.setX(pajaro.getX()-15);

        pajaro.paste(screen->getPtr());

        if(pajaro.getX()<-300)      //Cuando hayan pasado unos segundos desde su fallecimiento, llamamos a gameOver()
        {
            gameOver();
//            return 0;
        }

        screen->refresh();

        //Regulacion de FPS
        if(fps.getState() < 1000/FRAMES_POR_SEGUNDO)
            SDL_Delay((1000/FRAMES_POR_SEGUNDO) - fps.getState());

    }//Fin while

    return error.get();
}

void clsJuego::gameOver()
{
    char nombre[5+1]="";
    int i=0;

    while(event->getKey() != KEY_ENTER || strlen(nombre)<5)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                char letra = (char) event->getKey();
                if(letra == ' ' || (letra >= '0' && letra <= '9') || (letra >= 'a' && letra <= 'z'))
                {
                    if(event->getKeyMode() == KEY_MDF_CAPSLOCK && letra != ' ' && (letra < '0' || letra > '9'))
                        letra -= 32;
                    if(i < 5)
                    {
                        nombre[i] = letra;
                        nombre[i+1] = '\0';
                        i++;
                    }
                }
                //HACER BACKSPACE
            }
        }
        screen->clean(VIOLET);
        texto.centredWrite("GAME OVER", 100, screen->getPtr());
        if(nombre[0] != '\0')
            texto.centredWrite(nombre, screen->getHeight()/2 - texto.getHeight()/2, screen->getPtr());
        screen->refresh();
    }
}
