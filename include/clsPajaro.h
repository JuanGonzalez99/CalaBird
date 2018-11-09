#ifndef CLSPAJARO_H
#define CLSPAJARO_H

#include <clsSprite.h>
#include <clsEvent.h>

class clsPajaro : public clsSprite
{
    private:


    public:
        void inherit(){}
        int init();
        void manejoEventos(clsEvent&);
};

#endif // CLSPAJARO_H
