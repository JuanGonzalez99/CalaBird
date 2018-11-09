#include "clsPajaro.h"

int clsPajaro::init()
{
    error.set(0);

    return error.get();
}

void clsPajaro::manejoEventos(clsEvent &event)
{
    switch(event.getKey())
    {
    case KEY_SPACE:
        {

        }break;
    case KEY_LEFT:
        {

        }break;
    case KEY_RIGHT:
        {

        }break;
    case KEY_p:
    case KEY_P:
        {

        }break;
    }
}
