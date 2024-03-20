#ifndef TOIDO_BUTTON
#define TOIDO_BUTTON

#include "../Color.h"
#include "../Font.h"
#include "Component.h"
#include "../../Bool.h"

typedef struct
{

    char* Text;

    unsigned int Id;
    unsigned int X, Y;

    Component ButtonComponent;
    Font ButtonFont;
    Color BackgroundColor;

    bool Hovering, Pressed;

    #ifdef WIN

        WNDPROC OldProc;

    #elif defined LIN

    #endif

} Button;

int InitializeButton(Button* NewButton, Component Parent, unsigned int Id, char* Text, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor, Font ButtonFont);
void DestroyButton(Button* CurrentButton);

#endif