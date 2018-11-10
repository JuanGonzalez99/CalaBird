#ifndef CLSPAREDES_H
#define CLSPAREDES_H

#include <clsPared.h>
#include <clsRandom.h>
#include <clsScreen.h>
#include <clsError.h>

class clsParedes
{
    private:
        int cantParedes, distHorizontal, distVertical;
        clsError error;
        clsPared *inferiores;
        clsPared *superiores;
        clsRandom random;
        clsScreen *screen;

    public:
        int init(clsScreen*);
        void mostrar();
        void mover(int);
        ~clsParedes();
};

#endif // CLSPAREDES_H
