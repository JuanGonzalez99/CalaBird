#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsMenu.h>
#include <clsMusic.h>
#include <clsScreen.h>
#include <clsPajaro.h>
#include <clsParedes.h>
#include <clsPuntaje.h>
#include <clsFondo.h>
#include <clsTimer.h>
#include <clsText.h>

class clsJuego
{
    private:
        int FRAMES_POR_SEGUNDO;
        clsError error;
        clsEvent *event;
        clsMusic *music;
        clsScreen *screen;
        clsFondo fondo;
        clsMenu menu;
        clsPajaro pajaro;
        clsParedes paredes;
        clsPuntaje puntaje;
        clsText txtPuntos;
        clsText texto;
        clsTimer fps;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
        int gameOver();
};

#endif // CLSJUEGO_H
