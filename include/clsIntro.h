//#############################################################################
// ARCHIVO             : clsIntro.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsIntro".
//
//              "clsIntro" consta de los objetos necesarios para los objetos y
//              métodos necesarios para levantar la presentación del juego.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSINTRO_H
#define CLSINTRO_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsTimer.h>


class clsIntro : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen*, clsMusic*, clsEvent*, clsTimer*);
       void animar();
       int run();
    private:
        clsScreen *screen;
        clsMusic *music;
        clsEvent *event;
        clsText texto;
        clsTimer *timer;

};

#endif // CLSINTRO_H
