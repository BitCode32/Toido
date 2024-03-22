#ifndef TOIDO_PANEL
#define TOIDO_PANEL

#include "Component.h"
#include "../Color.h"

typedef struct
{

    Component PanelComponent;
    unsigned int X, Y;

    Color BackgroundColor;

} Panel;

int InitializePanel(Panel* NewPanel, Component Parent, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor);

#endif