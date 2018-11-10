#include "clsFondo.h"

int clsFondo::init()
{
    setItems(1);
    setI(0);
    error.set(load("IMAGES/fondo600x2000.png"));
    if(error.get()) return error.get();

    return 0;
}
