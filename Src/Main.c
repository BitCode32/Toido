#include "../Include/GUI/Components/Window.h"
#include "../Include/GUI/Components/Button.h"
#include "../Include/Bool.h"

int main()
{

    Window MainWindow;
    InitializeWindow(&MainWindow, "Toido", 720, 480);
    DisplayWindow(&MainWindow, true);

    Color PrimaryButtonColor;
    InitializeColor(&PrimaryButtonColor, 255, 0, 0);

    Color TextColor;
    InitializeColor(&TextColor, 255, 255, 255);

    Font MainFont;
    InitializeFont(&MainFont, "Arial", 18, TextColor);

    Button TestButton;
    InitializeButton(&TestButton, MainWindow.WindowComponent, 1, "Click Me", 10, 10, 200, 50, PrimaryButtonColor, MainFont);

    while (!WindowShouldClose(&MainWindow))
    {



    }

    DestroyButton(&TestButton);
    DestroyFont(&MainFont);
    DestroyActiveWindow(&MainWindow);
    return 0;

}