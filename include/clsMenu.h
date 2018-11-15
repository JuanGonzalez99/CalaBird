#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsPuntajes.h>
#include <clsTimer.h>

class clsMenu : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen*, clsMusic*, clsEvent*);
       int run();

    private:
        bool salir;
        clsScreen *screen;
        clsMusic *musicMenu;
        clsEvent *event;
        clsText texto;
        clsPuntajes puntajes;
        clsTimer timer;
};

#endif // CLSMENU_H
