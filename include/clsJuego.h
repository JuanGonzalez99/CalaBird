//#############################################################################
// ARCHIVO             : clsJuego.h
// AUTOR               : Juan Agustin Gonzalez.
// VERSION             : 1.0.
// FECHA DE CREACION   : 30/10/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsJuego".
//
//              "clsJuego" consta de los objetos y métodos necesarios para el
//              funcionamiento del juego en sí.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsMenu.h>
#include <clsMusic.h>
#include <clsScreen.h>
#include <clsPajaro.h>
#include <clsParedes.h>
#include <clsPuntaje.h>
#include <clsFondo.h>
#include <clsTimer.h>
#include <clsText.h>

class clsJuego
{
    private:
        int FRAMES_POR_SEGUNDO;
        clsError error;
        clsEvent *event;
        clsMusic *music;
        clsScreen *screen;
        clsFondo fondo;
        clsFondo finJuego;
        clsFondo marcoTexto;
        clsMenu menu;
        clsPajaro pajaro;
        clsParedes paredes;
        clsPuntaje puntaje;
        clsText txtPuntos;
        clsText texto;
        clsTimer fps;

    public:
        int init(clsScreen*, clsEvent*, clsMusic*);
        int run();
        int gameOver();
};

#endif // CLSJUEGO_H
