//#############################################################################
// ARCHIVO             : clsFondo.h
// AUTOR               : Javier Pereyra.
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsFondo".
//
//              "clsFondo" consta de un método para cargar una imagen por
//              objeto.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>

class clsFondo : public clsSprite
{
    public:
        void inherit(){}
        int init(const char*);
};

#endif // CLSFONDO_H
