#include "clsPajaro.h"

int clsPajaro::init(clsScreen *scr)
{
    error.set(0);

    screen = scr;

    setItems(2);
    setI(0);
    error.set(load("IMAGES/PAJARO/pajaro64x64.png"));
    if(error.get()) return error.get();
    setI(1);
    error.set(load("IMAGES/PAJARO/pajaroMuerto64x64.png"));
    if(error.get()) return error.get();

    setI(0);
    status = 0;

    setX(100);
    setY(100);

    return error.get();
}

void clsPajaro::manejoEventos(clsEvent *event)
{
    if(event->getEventType() == KEY_PRESSED)
    {
        switch(event->getKey())
        {
        case KEY_SPACE:
            {

            }break;
        }
    }
    if(event->getEventType() == KEY_FREE)
    {
        switch(event->getKey())
        {

        }
    }
}

void clsPajaro::setStatus(int stat)
{
    status = stat;
}

int clsPajaro::getStatus()
{
    return status;
}
