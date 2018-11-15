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
#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsEvent.h>
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsMotor.h>
#include <clsIntro.h>
#include <clsTimer.h>
#include <clsText.h>
#include <clsAudio.h>
#include <clsJuego.h>
#include <clsSalida.h>
#include <clsMenu.h>

class clsMotor
{
    private:
        clsAudio audio;
        clsError error;
        clsEvent event;
        clsIntro intro;
        clsJuego juego;
        clsMode mode;
        clsMusic music;
        clsSalida salida;
        clsScreen screen;
        clsTimer timer;

    public:
        int init();
        int run();
};

#endif // CLSMOTOR_H
