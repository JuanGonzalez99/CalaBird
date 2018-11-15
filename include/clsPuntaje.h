//#############################################################################
// ARCHIVO             : clsPuntaje.h
// AUTOR               : Javier Pereyra.
// VERSION             : 1.0.
// FECHA DE CREACION   : 13/11/2018.
// ULTIMA ACTUALIZACION: 15/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsPuntaje".
//
//              "clsPuntaje" consta de los métodos necesarios para el guardado
//              del puntaje junto a un nombre ligado al mismo.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPUNTAJE_H
#define CLSPUNTAJE_H

#include <cstdio>
#include <cstring>

class clsPuntaje
{
    public:
        int init();
        void guardar();
        void setNombre(const char*);
        void setPuntos(int);
        int getPuntos();
        const char* getNombre();
        void operator=(clsPuntaje);

    protected:
        int puntos;
        char nombre[5+1];

};

#endif // CLSPUNTAJE_H
