//#############################################################################
// ARCHIVO             : clsPajaro.cpp
// AUTOR               : Juan Agustin Gonzalez
// VERSION             : 1.0.
// FECHA DE CREACION   : 10/11/2018.
// ULTIMA ACTUALIZACION: 13/11/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsPajaro".
//
//              "clsPajaro" consta de los métodos necesarios para el manejo
//              del pajaro ("personaje principal") del juego.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPajaro.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa los atributos e imágenes de la clase.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
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

//=============================================================================
// METODO    : void manejoEventos(clsEvent* event)
// ACCION    : Maneja los eventos para determinar el estado de una de sus
//             propiedades.
// PARAMETROS: clsEvent* event --> puntero al objeto evento a manejar.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
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

//=============================================================================
// METODO    : bool getSubir()
// ACCION    : Retorna el estado del atributo booleano 'subir'.
// PARAMETROS: NADA.
// DEVUELVE  : bool --> Estado de 'subir'.
//-----------------------------------------------------------------------------
bool clsPajaro::getSubir()
{
    return subir;
}

