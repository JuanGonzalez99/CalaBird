#include "clsFondo.h"

int clsFondo::init(const char* ruta)
{
    setItems(1);
    setI(0);
    error.set(load(ruta));
    if(error.get()) return error.get();

    return 0;
}
