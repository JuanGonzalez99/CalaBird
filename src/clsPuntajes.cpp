//#############################################################################
// ARCHIVO             : clsPuntajes.cpp
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
// DESCRIPCION: Este archivo contiene la definición de los métodos de la clase
//              "clsPuntajes".
//
//              "clsPuntajes" consta de los métodos necesarios para el manejo,
//              carga y ordenamiento de los puntajes guardados en disco.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPuntajes.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa un atributo de la clase.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsPuntajes::init()
{
    error.set(0);

    i = 0;

    return error.get();
}

//=============================================================================
// METODO    : int cantPuntajes()
// ACCION    : Abre el archivo de puntajes y retorna la cantidad haciendo un
//             cálculo entre el tamaño del archivo y el sizeof de la clase.
// PARAMETROS: NADA.
// DEVUELVE  : int --> cantidad de puntajes guardados en el archivo.
//-----------------------------------------------------------------------------
int clsPuntajes::cantPuntajes()
{
    int cant;
    FILE *p = fopen("puntajes.dat", "rb");
    if(p == NULL)
        return 0;

    fseek(p, 0, SEEK_END);
    cant = ftell(p) / sizeof(clsPuntaje);
    fclose(p);

    return cant;
}

//=============================================================================
// METODO    : void cargarYordenar()
// ACCION    : Carga en el puntero de la clase todos los puntajes que estén en
//             el archivo y los ordena de mayor a menor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntajes::cargarYordenar()
{
    ptr = new clsPuntaje[cantPuntajes()];
    FILE *p = fopen("puntajes.dat", "rb");
    fread(ptr, sizeof(clsPuntaje), cantPuntajes(), p);

    bool ordenado = false;
    while(!ordenado)
    {
        ordenado = true;
        for(int x=0; x<cantPuntajes()-1; x++)
        {
            if(ptr[x].getPuntos() < ptr[x+1].getPuntos())
            {
                clsPuntaje aux;
                aux = ptr[x];
                ptr[x] = ptr[x+1];
                ptr[x+1] = aux;
                ordenado = false;
            }
        }
    }
}

//=============================================================================
// METODO    : void borrar()
// ACCION    : Borra el registro de los puntajes guardados en disco.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntajes::borrar()
{
    FILE *p;
    p = fopen("puntajes.dat", "wb");
    fclose(p);
}

//=============================================================================
// METODO    : int getI()
// ACCION    : Devuelve la posición del índice de la clase.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de i.
//-----------------------------------------------------------------------------
int clsPuntajes::getI()
{
    return i;
}

//=============================================================================
// METODO    : void setI(int i)
// ACCION    : Cambia el valor del índice.
// PARAMETROS: int i -> nueva valor de i.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsPuntajes::setI(int i)
{
    this->i = i;
}

//=============================================================================
// METODO    : clsPuntaje getPuntaje()
// ACCION    : Devuelve el objeto puntaje en la posición i del puntero
//             utilizado como vector.
// PARAMETROS: NADA
// DEVUELVE  : clsPuntaje --> puntaje en la posición i.
//-----------------------------------------------------------------------------
clsPuntaje clsPuntajes::getPuntaje()
{
    return ptr[i];
}

//=============================================================================
// METODO    : ~clsPuntajes()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsPuntajes::~clsPuntajes()
{
    delete ptr;
}
