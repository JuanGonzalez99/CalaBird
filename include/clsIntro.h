#ifndef CLSINTRO_H
#define CLSINTRO_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsMusic.h>
#include <clsEvent.h>
#include <clsText.h>
#include <clsTimer.h>


class clsIntro : public clsSprite
{
    public:
       void inherit(){};
       int init(clsScreen*, clsMusic*, clsEvent*, clsTimer*);
       void animar();
       int run();
    private:
        clsScreen *screen;
        clsMusic *music;
        clsEvent *event;
        clsText texto;
        clsTimer *timer;

};

#endif // CLSINTRO_H
