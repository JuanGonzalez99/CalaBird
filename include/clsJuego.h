#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsMusic.h>
#include <clsScreen.h>
#include <clsPajaro.h>
#include <clsParedes.h>
#include <clsFondo.h>

class clsJuego
{
    private:
        clsError error;
        clsEvent *event;
        clsMusic *music;
        clsScreen *screen;
        clsParedes paredes;
        clsFondo fondo;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
};

#endif // CLSJUEGO_H
