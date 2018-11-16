//#############################################################################
// ARCHIVO             : clsSalida.cpp
// AUTOR               : Javier Pereyra
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsSalida".
//
//              "clsSalida" consta de los objetos y métodos necesarios para
//              levantar la despedida del juego.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsSalida.h"

//=============================================================================
// METODO    : int init(clsScreen* scr, clsEvent* ev, clsMusic* mus)
// ACCION    : Inicializa los objetos de la clase.
// PARAMETROS: clsScreen* s --> puntero a la pantalla.
//             clsMusic* m --> puntero a la música.
//             clsEvent* e --> puntero al manager de eventos.
//             clsTimer *t --> puntero a un minutero virtual.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
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

//=============================================================================
// METODO    : void animar()
// ACCION    : Pega la imagen actual en pantalla y se prepara para pegar la
//             siguiente.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
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

//=============================================================================
// METODO    : int run()
// ACCION    : Dispone la despedida del juego a la espera del jugador.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsSalida::run()
{
    error.set(0);

    music->loadMusic("MUSIC/SALIDA.mp3");
    music->playMusic(-1);

    texto.write("Gracias por jugar!", 0, 0, screen->getPtr());

    while(true)
    {
        if(event->wasEvent())
        {
            switch(event->getEventType())
            {
            case SDL_QUIT:
                {
                    return -1;
                }break;
            case KEY_PRESSED:
                {
                    if(event->getKey() == KEY_ESCAPE)
                    {
                        music->closeMusic();
                        return -1;
                    }
                    if(event->getKey() == KEY_ENTER)
                    {
                        music->closeMusic();
                        return 0;
                    }
                }break;
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
