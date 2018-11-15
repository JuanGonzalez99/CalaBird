//#############################################################################
// ARCHIVO             : clsParedes.h
// AUTOR               : Juan Agustin Gonzalez.
// VERSION             : 1.0.
// FECHA DE CREACION   : 10/11/2018.
// ULTIMA ACTUALIZACION: 13/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks - 17.12.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsParedes".
//
//              "clsParedes" consta de los atributos y métodos necesarios para
//              poder trabajar cómodamente con varios objetos de la clase
//              "clsPared".
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPAREDES_H
#define CLSPAREDES_H

#include <clsPared.h>
#include <clsRandom.h>
#include <clsScreen.h>
#include <clsError.h>

class clsParedes
{
    private:
        int cantParedes, distHorizontal, distVertical;
        clsError error;
        clsPared *inferiores;
        clsPared *superiores;
        clsRandom random;
        clsScreen *screen;

    public:
        int init(clsScreen*, int);
        void mostrar();
        void mover(int);
        bool seTocan(clsSprite*);
        int pasadas(clsSprite*);
        ~clsParedes();
};

#endif // CLSPAREDES_H
