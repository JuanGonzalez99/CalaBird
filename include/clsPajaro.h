#ifndef CLSPAJARO_H
#define CLSPAJARO_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsScreen.h>

class clsPajaro : public clsSprite
{
    private:
        bool subir;

    public:
        void inherit(){}
        int init();
        void manejoEventos(clsEvent*);
        bool getSubir();
};

#endif // CLSPAJARO_H
