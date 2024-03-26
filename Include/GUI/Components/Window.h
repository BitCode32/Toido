#ifndef TOIDO_WINDOW
#define TOIDO_WINDOW

#include "Component.h"
#include "../../Bool.h"
#include "../../Events/Event.h"

typedef struct
{

    Component WindowComponent;
    char* Title;

    void (*EventHandler)(Event* e);

    #ifdef WIN

        MSG Message;

    #elif defined LIN

    #endif

} Window;

int InitializeWindow(Window* NewWindow, char* Title, unsigned short Width, unsigned short Height);
void DestroyActiveWindow(Window* CurrentWindow);

bool WindowShouldClose(Window* CurrentWindow);

#endif