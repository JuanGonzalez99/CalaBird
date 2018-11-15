//#############################################################################
// ARCHIVO             : clsMotor.cpp
// AUTOR               : Javier Pereyra.
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsMotor".
//
//              "clsMotor" consta de los objetos necesarios para levantar el
//              modo gráfico, la presentación, el juego y la salida.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsMotor.h"

int clsMotor::init()
{
    error.set(0);

    error.set(mode.init(DEFAULT));
    if(error.get()) return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get()) return error.get();

    error.set(audio.init());
    if(error.get()) return error.get();

    error.set(intro.init(&screen, &music, &event, &timer));
    if(error.get()) return error.get();

    error.set(juego.init(&screen, &event, &music));
    if(error.get()) return error.get();

    error.set(salida.init(&screen, &music, &event, &timer));
    if(error.get()) return error.get();

    return error.get();
}

int clsMotor::run()
{
//    error.set(intro.run());
//    if(error.get() > 0) return error.get();
//    if(error.get() < 0) return 0;
//
    error.set(juego.run());
    if(error.get() > 0) return error.get();
    if(error.get() < 0) return 0;

//    error.set(salida.run());
//    if(error.get() > 0) return error.get();
//    if(error.get() < 0) return 0;

    return error.get();
}

