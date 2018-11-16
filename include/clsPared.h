//#############################################################################
// ARCHIVO             : clsPared.h
// AUTOR               : Juan Agustin Gonzalez.
// VERSION             : 1.0.
// FECHA DE CREACION   : 10/11/2018.
// ULTIMA ACTUALIZACION: 11/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsPared".
//
//              "clsPared" consta de la carga de una imagen de pared, para su
//              posterior manejo en la clase "clsParedes".
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPARED_H
#define CLSPARED_H

#include <clsSprite.h>

class clsPared : public clsSprite
{
    private:
        void inherit(){}

    public:
        int init();
};

#endif // CLSPARED_H
