//#############################################################################
// ARCHIVO             : clsSalida.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsSalida".
//
//              "clsSalida" consta de los objetos y métodos necesarios para
//              levantar la despedida del juego.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSSALIDA_H
#define CLSSALIDA_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsMusic.h>
#include <clsTimer.h>
#include <clsText.h>

class clsSalida : public clsSprite
{
    public:
        void inherit(){}
        int init(clsScreen*,clsMusic*,clsEvent*,clsTimer*);
        void animar();
        int run();

    private:
        clsScreen *screen;
        clsEvent *event;
        clsMusic *music;
        clsTimer *timer;
        clsText texto;
};

#endif // CLSSALIDA_H
