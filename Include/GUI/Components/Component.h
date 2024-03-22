#ifndef TOIDO_COMPONENT
#define TOIDO_COMPONENT

#include "../../OS.h"
#include "../../Bool.h"

typedef struct
{

    unsigned int Width, Height;

    #ifdef WIN

        HWND ComponentWindow;

    #elif defined LIN

    #endif

} Component;

void ShowComponent(Component* CurrentComponent, bool Visible);
void EnableComponent(Component* CurrentComponent, bool Enabled);

#endif