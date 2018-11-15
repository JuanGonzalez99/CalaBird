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
#include "clsFondo.h"

int clsFondo::init(const char* ruta)
{
    setItems(1);
    setI(0);
    error.set(load(ruta));
    if(error.get()) return error.get();

    return 0;
}
