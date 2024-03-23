#ifndef TOIDO_LABEL
#define TOIDO_LABEL

#include "Component.h"
#include "../Font.h"
#include "../Color.h"

typedef struct
{

    char* Text;
    unsigned int TextLength;

    unsigned int Id;
    unsigned int X, Y;

    Component LabelComponent;
    Font LabelFont;
    Color BackgroundColor;

} Label;

void InitializeLabel(Label* NewLabel, Component Parent, unsigned int Id, char* Text, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor, Font ButtonFont);

#endif