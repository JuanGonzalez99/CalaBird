#include "clsPared.h"

int clsPared::init()
{
    error.set(0);

    setItems(1);
    setI(0);
    setName("pared");

    error.set(load("IMAGES/pared64x600.png"));
    if(error.get()) return error.get();

    return error.get();
}
