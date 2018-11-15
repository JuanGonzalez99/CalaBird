#include "clsPuntajes.h"

int clsPuntajes::init()
{
    error.set(0);

    i = 0;

    return error.get();
}

int clsPuntajes::cantPuntajes()
{
    int cant;
    FILE *p = fopen("puntajes.dat", "rb");
    if(p == NULL)
        return 0;

    fseek(p, 0, SEEK_END);
    cant = ftell(p) / sizeof(clsPuntaje);
    fclose(p);

    return cant;
}

void clsPuntajes::cargarYordenar()
{
    ptr = new clsPuntaje[cantPuntajes()];
    FILE *p = fopen("puntajes.dat", "rb");
    fread(ptr, sizeof(clsPuntaje), cantPuntajes(), p);

    bool ordenado = false;
    while(!ordenado)
    {
        ordenado = true;
        for(int x=0; x<cantPuntajes()-1; x++)
        {
            if(ptr[x].getPuntos() < ptr[x+1].getPuntos())
            {
                clsPuntaje aux;
                aux = ptr[x];
                ptr[x] = ptr[x+1];
                ptr[x+1] = aux;
                ordenado = false;
            }
        }
    }
}

int clsPuntajes::getI(){ return i; }

void clsPuntajes::setI(int i){ this->i = i; }

clsPuntaje clsPuntajes::getPuntaje(){ return ptr[i]; }

clsPuntajes::~clsPuntajes()
{
    delete ptr;
}
