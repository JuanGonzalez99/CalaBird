//#############################################################################
// ARCHIVO             : clsFondo.cpp.
// AUTOR               : Javier Pereyra.
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.
// LICENCIA             : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsFondo".
//
//              "clsFondo" consta de un método para cargar una imagen por
//              objeto.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsFondo.h"

//=============================================================================
// METODO    : int init(const char* ruta)
// ACCION    : Inicializa la imagen de la clase.
// PARAMETROS: const char* ruta --> ruta de la imagen a cargar.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsFondo::init(const char* ruta)
{
    setItems(1);
    setI(0);
    error.set(load(ruta));
    if(error.get()) return error.get();

    return 0;
}
