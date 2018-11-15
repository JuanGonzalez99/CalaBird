//#############################################################################
// ARCHIVO             : clsMotor.cpp
// AUTOR               : Juan Agustin Gonzalez
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.          .
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clas
//              "clsMotor".
//
//              "clsMotor" consta de los objetos necesarios para levantar el
//              modo gráfico, la presentación, el juego y la salida.
//
///////////////////////////////////////////////////////////////////////////////
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
