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
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsParedes".
//
//              "clsParedes" consta de los atributos y métodos necesarios para
//              poder trabajar cómodamente con varios objetos de la clase
//              "clsPared".
//
///////////////////////////////////////////////////////////////////////////////
#include "clsParedes.h"

//=============================================================================
// METODO    : int init(clsScreen *scr, int cant)
// ACCION    : Inicializa los atributos de la clase, incluyendo las paredes.
// PARAMETROS: clsScreen *scr --> puntero a la pantalla.
//             int cant --> cantidad de paredes a utilizar.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsParedes::init(clsScreen *scr, int cant)
{
    screen = scr;
    cantParedes = cant;
    distHorizontal = 450;
    distVertical = 150;

    random.init();

    inferiores = new clsPared[cantParedes];
    if(inferiores == NULL) return 2;

    superiores = new clsPared[cantParedes];
    if(superiores == NULL) return 2;

    for(int x=0; x<cantParedes; x++)
    {
        error.set(superiores[x].init());
        if(error.get()) return error.get();

        error.set(inferiores[x].init());
        if(error.get()) return error.get();

        superiores[x].setY(random.getNumber(screen->getHeight()-distVertical*2)+distVertical-screen->getHeight());
        superiores[x].setX(distHorizontal*x+(screen->getWidth()*3/2));

        inferiores[x].setY(superiores[x].getY()+screen->getHeight()+distVertical);
        inferiores[x].setX(distHorizontal*x+(screen->getWidth()*3/2));
    }

    return 0;
}

//=============================================================================
// METODO    : void mostrar()
// ACCION    : Pega en pantalla todas las paredes cuya 'X' no se exceda de la
//             misma.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsParedes::mostrar()
{
    for(int x=0; x<cantParedes; x++)
    {
        if(superiores[x].getX() <= screen->getWidth() && superiores[x].getX() >= -superiores[x].getWidth())
            superiores[x].paste(screen->getPtr());
        if(inferiores[x].getX() <= screen->getWidth() && inferiores[x].getX() >= -inferiores[x].getWidth())
            inferiores[x].paste(screen->getPtr());
    }
}

//=============================================================================
// METODO    : void mover(int dist)
// ACCION    : Mueve todos las paredes hacia la izquierda según el entero
//             pasado por parámetro.
// PARAMETROS: int dist --> cantidad de píxeles a mover.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsParedes::mover(int dist)
{
    for(int x=0; x<cantParedes; x++)
    {
        superiores[x].setX(superiores[x].getX()-dist);
        inferiores[x].setX(inferiores[x].getX()-dist);
    }
}

//=============================================================================
// METODO    : bool seTocan(clsSprite *sprite)
// ACCION    : Evalúa si el sprite pasado por parámetro se toca con alguna de
//             las paredes.
// PARAMETROS: clsSprite *sprite --> puntero al sprite a evaluar.
// DEVUELVE  : bool --> false si no se toca con ninguna, true caso contrario.
//-----------------------------------------------------------------------------
bool clsParedes::seTocan(clsSprite *sprite)
{
    for(int x=0; x<cantParedes; x++)
    {
        if(superiores[x].getContact(sprite))
            return true;

        if(inferiores[x].getContact(sprite))
            return true;
    }
    return false;
}

//=============================================================================
// METODO    : int pasadas(clsSprite *spr)
// ACCION    : Cuenta la cantidad de paredes pasadas por el sprite que se pasa
//             por parámetro.
// PARAMETROS: clsSprite *spr --> puntero al sprite a evaluar.
// DEVUELVE  : int --> cantidad de paredes pasadas por el sprite.
//-----------------------------------------------------------------------------
int clsParedes::pasadas(clsSprite *spr)
{
    int cont=0;

    for(int x=0; x<cantParedes; x++)
    {
        if(spr->getX() >= superiores[x].getX()+superiores[x].getWidth())
            cont++;
    }

    return cont;
}

//=============================================================================
// METODO    : ~clsParedes()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsParedes::~clsParedes()
{
    delete inferiores;
    delete superiores;
}
