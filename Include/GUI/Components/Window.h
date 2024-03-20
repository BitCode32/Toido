#ifndef TOIDO_WINDOW
#define TOIDO_WINDOW

#include "../../OS.h"
#include "../../Bool.h"

typedef struct
{

    char* Title;
    unsigned short Width, Height;

    #ifdef WIN

        HWND ApiWindow;
        MSG Message;

    #elif defined LIN

    #endif

} Window;

int InitializeWindow(Window* NewWindow, char* Title, unsigned short Width, unsigned short Height);
void DestroyActiveWindow(Window* CurrentWindow);

bool WindowShouldClose(Window* CurrentWindow);
void DisplayWindow(Window* CurrentWindow, bool Visible);

#endif