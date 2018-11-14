#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
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
        clsPajaro pajaro;
        clsParedes paredes;
        clsPuntaje puntaje;
        clsText texto;
        clsTimer fps;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
        void gameOver();
};

#endif // CLSJUEGO_H
