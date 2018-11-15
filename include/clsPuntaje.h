#ifndef CLSPUNTAJE_H
#define CLSPUNTAJE_H

#include <cstdio>
#include <cstring>

class clsPuntaje
{
    public:
        int init();
        void guardar();
        void setNombre(const char*);
        void setPuntos(int);
        int getPuntos();
        const char* getNombre();
        void operator=(clsPuntaje);

    protected:
        int puntos;
        char nombre[5+1];

};

#endif // CLSPUNTAJE_H
