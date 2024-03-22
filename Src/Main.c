#include "../Include/GUI/Components/Window.h"
#include "../Include/GUI/Components/Button.h"
#include "../Include/GUI/Components/Panel.h"
#include "../Include/Bool.h"

int main()
{

    Window MainWindow;
    InitializeWindow(&MainWindow, "Toido", 720, 480);
    ShowComponent(&MainWindow.WindowComponent, true);

    Color PrimaryButtonColor, TextColor, BackgroundColor;

    InitializeColor(&PrimaryButtonColor, 255, 0, 0);
    InitializeColor(&TextColor, 255, 255, 255);
    InitializeColor(&BackgroundColor, 0, 0, 255);

    Font MainFont;
    InitializeFont(&MainFont, "Arial", 18, TextColor);

    Panel MainPanel;
    InitializePanel(&MainPanel, MainWindow.WindowComponent, 0, 0, 700, 400, BackgroundColor);

    Button TestButton;
    InitializeButton(&TestButton, MainPanel.PanelComponent, 1, "Click Me", 10, 10, 200, 50, PrimaryButtonColor, MainFont);

    while (!WindowShouldClose(&MainWindow))
    {



    }

    DestroyButton(&TestButton);
    DestroyFont(&MainFont);
    DestroyActiveWindow(&MainWindow);
    return 0;

}