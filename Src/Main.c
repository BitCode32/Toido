#include "../Include/GUI/Components/Window.h"
#include "../Include/Bool.h"

int main()
{

    Window MainWindow;
    InitializeWindow(&MainWindow, "Toido", 720, 480);
    DisplayWindow(&MainWindow, true);

    while (!WindowShouldClose(&MainWindow))
    {



    }

    DestroyActiveWindow(&MainWindow);
    return 0;

}