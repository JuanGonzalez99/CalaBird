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
#include "clsPajaro.h"

int clsPajaro::init()
{
    error.set(0);

    setItems(2);
    setI(0);
    error.set(load("IMAGES/PAJARO/pajaro64x64.png"));
    if(error.get()) return error.get();
    setI(1);
    error.set(load("IMAGES/PAJARO/pajaroMuerto64x64.png"));
    if(error.get()) return error.get();

    setI(0);

    setX(200);
    setY(100);
    subir = false;

    return error.get();
}

void clsPajaro::manejoEventos(clsEvent* event)
{
    switch(event->getEventType())
    {
    case KEY_PRESSED:
        {
            if(event->getKey() == KEY_SPACE)
            {
                subir = true;
            }
        }break;
    case KEY_FREE:
        {
            if(event->getKey() == KEY_SPACE)
            {
                subir = false;
            }
        }break;
    }
}

bool clsPajaro::getSubir()
{
    return subir;
}

