#include <stdio.h>
#include "../Include/GUI/Font.h"

int main()
{

    Color TextColor;
    InitializeColor(&TextColor, 255, 50, 25);

    Font MyFont;
    InitializeFont(&MyFont, "Arial", 20, TextColor);

    printf("R: %d, G: %d, B: %d", MyFont.TextColor.R, MyFont.TextColor.G, MyFont.TextColor.B);

    DestroyFont(&MyFont);

    return 0;

}