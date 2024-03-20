#ifndef TOIDO_WINDOW
#define TOIDO_WINDOW

#include "Component.h"
#include "../../Bool.h"

typedef struct
{

    char* Title;
    Component WindowComponent;

    #ifdef WIN

        MSG Message;

    #elif defined LIN

    #endif

} Window;

int InitializeWindow(Window* NewWindow, char* Title, unsigned short Width, unsigned short Height);
void DestroyActiveWindow(Window* CurrentWindow);

bool WindowShouldClose(Window* CurrentWindow);
void DisplayWindow(Window* CurrentWindow, bool Visible);

#endif