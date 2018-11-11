#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsTimer.h>


class clsMenu : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen*, clsMusic*, clsEvent*);
       void opciones();
       int run();
    private:
        clsScreen *screen;
        clsMusic *music;
        clsEvent *event;
};

#endif // CLSMENU_H
