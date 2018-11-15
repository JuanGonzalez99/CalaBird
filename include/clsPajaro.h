//#############################################################################
// ARCHIVO             : clsPajaro.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsPajaro".
//
//              "clsPajaro" consta de los métodos necesarios para el manejo
//              del pajaro ("personaje principal") del juego.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPAJARO_H
#define CLSPAJARO_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsScreen.h>

class clsPajaro : public clsSprite
{
    private:
        bool subir;

    public:
        void inherit(){}
        int init();
        void manejoEventos(clsEvent*);
        bool getSubir();
};

#endif // CLSPAJARO_H
