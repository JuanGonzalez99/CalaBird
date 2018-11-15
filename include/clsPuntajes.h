#ifndef CLSPUNTAJES_H
#define CLSPUNTAJES_H

#include <cstdio>
#include <clsError.h>
#include <clsPuntaje.h>

class clsPuntajes
{
    public:
        ~clsPuntajes();
        int init();
        void cargarYordenar();
        int cantPuntajes();
        void setI(int);
        int getI();
        clsPuntaje getPuntaje();

    protected:
        int i;
        clsError error;
        clsPuntaje *ptr;
};

#endif // CLSPUNTAJES_H
