//#############################################################################
// ARCHIVO             : clsPuntajes.h
// AUTOR               : Javier Pereyra/Juan Agustin Gonzalez.
// VERSION             : 1.0.
// FECHA DE CREACION   : 13/11/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase
//              "clsPuntajes".
//
//              "clsPuntajes" consta de los métodos necesarios para el manejo,
//              carga y ordenamiento de los puntajes guardados en disco.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPUNTAJES_H
#define CLSPUNTAJES_H

#include <cstdio>
#include <clsError.h>
#include <clsPuntaje.h>

class clsPuntajes
{
    public:
        ~clsPuntajes();
        int init();
        void cargarYordenar();
        void borrar();
        int cantPuntajes();
        void setI(int);
        int getI();
        clsPuntaje getPuntaje();

    protected:
        int i;
        clsError error;
        clsPuntaje *ptr;
};

#endif // CLSPUNTAJES_H
