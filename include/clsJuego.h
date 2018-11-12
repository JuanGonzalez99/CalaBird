#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsMusic.h>
#include <clsScreen.h>
#include <clsPajaro.h>
#include <clsParedes.h>
#include <clsFondo.h>
#include <clsTimer.h>

class clsJuego
{
    private:
        int FRAMES_POR_SEGUNDO;
        clsError error;
        clsEvent *event;
        clsFondo fondo;
        clsMusic *music;
        clsScreen *screen;
        clsPajaro pajaro;
        clsParedes paredes;
        clsTimer fps;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
};

#endif // CLSJUEGO_H
