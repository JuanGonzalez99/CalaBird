#ifndef CLSPAJARO_H
#define CLSPAJARO_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsScreen.h>

class clsPajaro : public clsSprite
{
    private:
        int status;
        clsScreen *screen;

    public:
        void inherit(){}
        int init(clsScreen*);
        void manejoEventos(clsEvent*);
        void setStatus(int);
        int getStatus();
};

#endif // CLSPAJARO_H
