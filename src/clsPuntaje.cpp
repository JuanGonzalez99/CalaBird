#include "clsPuntaje.h"

void clsPuntaje::mostrar(int puntos, int x, int y, SDL_Surface* scr)
{
    char txt[5]="";
    itoa(puntos, txt, 10);
    write(txt, x, y, scr);
}
