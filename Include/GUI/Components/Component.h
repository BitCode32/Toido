#ifndef TOIDO_COMPONENT
#define TOIDO_COMPONENT

#include "../../OS.h"

typedef struct
{

    unsigned int Width, Height;

    #ifdef WIN

        HWND ComponentWindow;

    #elif defined LIN

    #endif

} Component;

#endif