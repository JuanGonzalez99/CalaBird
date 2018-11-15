//#############################################################################
// ARCHIVO             : clsMotor.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsMotor".
//
//              "clsMotor" consta de los objetos necesarios para levantar el
//              modo gráfico, la presentación, el juego y la salida.
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
#include <clsSoundEffect.h>

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
        clsSoundEffect sonido;
};

#endif // CLSMENU_H
