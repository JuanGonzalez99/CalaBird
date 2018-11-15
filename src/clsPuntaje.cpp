#include "clsPuntaje.h"

int clsPuntaje::init()
{
    puntos = 0;
    strcpy(nombre, "");

    FILE *p = fopen("puntajes.dat", "rb");
    if(p == NULL) p = fopen("puntajes.dat", "wb");
    fclose(p);

    return 0;
}

void clsPuntaje::guardar()
{
    FILE *p = fopen("puntajes.dat", "ab");
    fwrite(this, sizeof(clsPuntaje), 1, p);
    fclose(p);
}

void clsPuntaje::setNombre(const char* nombre)
{
    strcpy(this->nombre, nombre);
}

void clsPuntaje::setPuntos(int p)
{
    puntos = p;
}

int clsPuntaje::getPuntos()
{
    return puntos;
}

const char* clsPuntaje::getNombre()
{
    return nombre;
}

void clsPuntaje::operator=(clsPuntaje externo)
{
    this->puntos = externo.puntos;
    strcpy(this->nombre, externo.nombre);
}
