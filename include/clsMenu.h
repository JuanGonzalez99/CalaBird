//#############################################################################
// ARCHIVO             : clsMenu.h
// AUTOR               : Javier Pereyra.
// VERSION             : 1.0.
// FECHA DE CREACION   : 06/11/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsMenu".
//
//              "clsMenu" consta de los métodos necesarios para el control del
//              juego con un sistema de menú.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsPuntajes.h>
#include <clsFondo.h>

class clsMenu : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen*, clsMusic*, clsEvent*);
       int run();

    private:
        bool salir;
        clsScreen *screen;
        clsMusic *musicMenu;
        clsEvent *event;
        clsFondo fondoPuntajes;
        clsText texto;
        clsPuntajes puntajes;
};

#endif // CLSMENU_H
