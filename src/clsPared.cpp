//#############################################################################
// ARCHIVO             : clsPared.cpp
// AUTOR               : Juan Agustin Gonzalez
// VERSION             : 1.0.
// FECHA DE CREACION   : 10/11/2018.
// ULTIMA ACTUALIZACION: 11/11/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsPared".
//
//              "clsPared" consta de la carga de una imagen de pared, para su
//              posterior manejo en la clase "clsParedes".
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPared.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa la imagen y nombre del sprite.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsPared::init()
{
    error.set(0);

    setItems(1);
    setI(0);
    setName("pared");

    error.set(load("IMAGES/pared64x600.png"));
    if(error.get()) return error.get();

    return error.get();
}
