#include "clsPajaro.h"

int clsPajaro::init()
{
    error.set(0);

    setItems(2);
    setI(0);
    error.set(load("IMAGES/PAJARO/pajaro64x64.png"));
    if(error.get()) return error.get();
    setI(1);
    error.set(load("IMAGES/PAJARO/pajaroMuerto64x64.png"));
    if(error.get()) return error.get();

    setI(0);

    setX(200);
    setY(100);
    subir = false;

    return error.get();
}

void clsPajaro::manejoEventos(clsEvent* event)
{
    switch(event->getEventType())
    {
    case KEY_PRESSED:
        {
            if(event->getKey() == KEY_SPACE)
            {
                subir = true;
            }
        }break;
    case KEY_FREE:
        {
            if(event->getKey() == KEY_SPACE)
            {
                subir = false;
            }
        }break;
    }
}

bool clsPajaro::getSubir()
{
    return subir;
}

