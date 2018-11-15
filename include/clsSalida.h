#ifndef CLSSALIDA_H
#define CLSSALIDA_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsMusic.h>
#include <clsTimer.h>
#include <clsText.h>

class clsSalida : public clsSprite
{
    public:
        void inherit(){}
        int init(clsScreen*,clsMusic*,clsEvent*,clsTimer*);
        void animar();
        int run();

    private:
        clsScreen *screen;
        clsEvent *event;
        clsMusic *music;
        clsTimer *timer;
        clsText texto;
};

#endif // CLSSALIDA_H
