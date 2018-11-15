#include "clsJuego.h"

int clsJuego::init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
{
    error.set(0);

    screen = scr;
    event = ev;
    music = mus;
    FRAMES_POR_SEGUNDO = 20;

    error.set(texto.init());
    if(error.get()) return error.get();
    error.set(texto.loadFont("FONTS/FreeSans.ttf", 60));
    if(error.get()) return error.get();

    error.set(menu.init(screen, music, event));
    if(error.get()) return error.get();

    error.set(puntaje.init());
    if(error.get()) return error.get();

    error.set(fondo.init("IMAGES/fondo600x2000.png"));
    if(error.get()) return error.get();

    error.set(paredes.init(screen, 300));
    if(error.get()) return error.get();

    error.set(txtPuntos.init());
    if(error.get()) return error.get();
    error.set(txtPuntos.loadFont("FONTS/FreeSans.ttf", 30));
    if(error.get()) return error.get();

    error.set(pajaro.init());
    if(error.get()) return error.get();

    error.set(finJuego.init("IMAGES/fondo600x2000.png"));
    if(error.get()) return error.get();

    error.set(marcoTexto.init("IMAGES/marcoTexto250x75.png"));
    if(error.get()) return error.get();

    return error.get();
}

int clsJuego::run()
{
    error.set(0);

    error.set(menu.run());
    if(error.get() > 0) return error.get();
    if(error.get() == -1) return 0;

    char aux[5];

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
        if(fondo.getX()<-1000) fondo.setX(-150);
        else fondo.setX(fondo.getX()-15);
        fondo.paste(screen->getPtr());
        paredes.mover(15);
        paredes.mostrar();

        //Manejo de puntaje
        itoa(paredes.pasadas(&pajaro), aux, 10);
        txtPuntos.write(aux, screen->getWidth()-100, 75, screen->getPtr());
        puntaje.setPuntos(paredes.pasadas(&pajaro));

        //Manejo del pajaro
        if(!pajaro.getSubir() || pajaro.getI() == 1)
        {
            if(pajaro.getY()+pajaro.getHeight()+10 <= screen->getHeight())
                pajaro.setY(pajaro.getY()+10);
        }
        else if(pajaro.getY()-10 >= 0)
            pajaro.setY(pajaro.getY()-10);

        if(paredes.seTocan(&pajaro))//Verificamos si el pajaro se choco con una pared
            pajaro.setI(1);

        if(pajaro.getI() == 1)      //Si el pajaro esta "muerto", hacemos que se mueva con el fondo
            pajaro.setX(pajaro.getX()-15);

        if(pajaro.getX()<-300)      //Cuando hayan pasado unos segundos desde su fallecimiento, llamamos a gameOver()
            break;

        pajaro.paste(screen->getPtr());


        screen->refresh();

        //Regulacion de FPS
        if(fps.getState() < 1000/FRAMES_POR_SEGUNDO)
            SDL_Delay((1000/FRAMES_POR_SEGUNDO) - fps.getState());

    }//Fin while
    error.set(gameOver());
    if(error.get()) return error.get();

    error.set(init(screen, event, music));
    if(error.get()) return error.get();

    error.set(run());
    if(error.get()) return error.get();

    return error.get();
}

int clsJuego::gameOver()
{
    error.set(0);

    char nombre[5+1]="";
    int i=0;

    while(event->getKey() != KEY_ENTER || strlen(nombre)<1)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                if(event->getKey() == KEY_ESCAPE) break;

                int letra = (int) event->getKey();
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
                if(event->getKey() == KEY_BACKSPACE && i > 0)
                {
                    nombre[i-1] = '\0';
                    i--;
                }
            }
            if(event->getEventType() == SDL_QUIT) return -1;
        }
        finJuego.paste(screen->getPtr());
        marcoTexto.paste(screen->getWidth()/2 - marcoTexto.getWidth()/2,
                         screen->getHeight()/2 - marcoTexto.getHeight()/2,
                         screen->getPtr());
        texto.centredWrite("GAME OVER", 100, screen->getPtr());
        if(nombre[0] != '\0')
            texto.centredWrite(nombre, screen->getHeight()/2 - texto.getHeight()/2, screen->getPtr());
        screen->refresh();
    }

    finJuego.paste(screen->getPtr());
    texto.setFontColor(WHITE);
    texto.write("Cargando...", 50, screen->getHeight()-100, screen->getPtr());
    screen->refresh();

    puntaje.setNombre(nombre);
    puntaje.guardar();

    return error.get();
}
