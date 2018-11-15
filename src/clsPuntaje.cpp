//#############################################################################
// ARCHIVO             : clsPuntaje.cpp
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
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsPuntaje".
//
//              "clsPuntaje" consta de los métodos necesarios para el guardado
//              del puntaje junto a un nombre ligado al mismo.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPuntaje.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa los atributos de la clase y hace un chequeo de la
//             existencia del archivo para guardar la información.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsPuntaje::init()
{
    puntos = 0;
    strcpy(nombre, "");

    FILE *p = fopen("puntajes.dat", "rb");
    if(p == NULL) p = fopen("puntajes.dat", "wb");
    fclose(p);

    return 0;
}

//=============================================================================
// METODO    : void guardar()
// ACCION    : Guarda el valor de los atributos en memoria secundaria (disco).
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntaje::guardar()
{
    FILE *p = fopen("puntajes.dat", "ab");
    fwrite(this, sizeof(clsPuntaje), 1, p);
    fclose(p);
}

//=============================================================================
// METODO    : void setNombre(const char* nombre)
// ACCION    : Cambia el nombre ligado al puntaje.
// PARAMETROS: const char* --> nuevo nombre.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntaje::setNombre(const char* nombre)
{
    strcpy(this->nombre, nombre);
}

//=============================================================================
// METODO    : void setPuntos(int p)
// ACCION    : Cambia la cantidad de puntos.
// PARAMETROS: int p --> nueva cantidad de puntos.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntaje::setPuntos(int p)
{
    puntos = p;
}

//=============================================================================
// METODO    : int getPuntos()
// ACCION    : Devuelve la cantidad de puntos.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de 'puntos'.
//-----------------------------------------------------------------------------
int clsPuntaje::getPuntos()
{
    return puntos;
}

//=============================================================================
// METODO    : int getNombre()
// ACCION    : Devuelve la cadena que contiene el nombre del jugador.
// PARAMETROS: NADA
// DEVUELVE  : const char* --> puntero 'nombre'.
//-----------------------------------------------------------------------------
const char* clsPuntaje::getNombre()
{
    return nombre;
}

//=============================================================================
// METODO    : void operator=(clsPuntaje externo)
// ACCION    : Devuelve la coordenada y del sprite.
// PARAMETROS: clsPuntaje externo --> objeto externo del cual se extraeran los
//             atributos para copiarlos en el objeto que llama al método.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntaje::operator=(clsPuntaje externo)
{
    this->puntos = externo.puntos;
    strcpy(this->nombre, externo.nombre);
}

