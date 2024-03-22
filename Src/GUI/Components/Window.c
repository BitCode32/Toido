#include "../../../Include/GUI/Components/Window.h"

#include <stdlib.h>
#include <stddef.h>

#ifdef WIN

    static bool RegisteredWindow = false;
    LRESULT CALLBACK WindowEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam);

#endif

int InitializeWindow(Window* NewWindow, char* Title, unsigned short Width, unsigned short Height)
{

    NewWindow->WindowComponent.Width = Width;
    NewWindow->WindowComponent.Height = Height;

    unsigned int Length = 0;
    while (Title[Length] != '\0')
        Length++;

    NewWindow->Title = (char*)malloc(sizeof(char) * (Length + 1));
    for (unsigned int i = 0; i <= Length; i++)
        NewWindow->Title[i] = Title[i];

    #ifdef WIN

        if (!RegisteredWindow)
        {

            WNDCLASSEXA WindowClass = { 0 };

            WindowClass.cbSize = sizeof(WindowClass);
            WindowClass.style = CS_HREDRAW | CS_VREDRAW;
            WindowClass.lpfnWndProc = WindowEventHandler;
            WindowClass.hInstance = GetModuleHandleA(NULL);
            WindowClass.hIcon = LoadIcon(WindowClass.hInstance, IDI_APPLICATION);
            WindowClass.hCursor = LoadCursor(WindowClass.hInstance, IDC_ARROW);
            WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            WindowClass.lpszMenuName = NULL;
            WindowClass.lpszClassName = "MainWindow";

            if (!RegisterClassExA(&WindowClass))
            {

                MessageBoxA(NULL, "Could not register window!", "Error", MB_ICONERROR);
                return -1;

            }

            RegisteredWindow = true;

        }

        NewWindow->WindowComponent.ComponentWindow= CreateWindowExA(0, "MainWindow", NewWindow->Title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, NewWindow->WindowComponent.Width, NewWindow->WindowComponent.Height, NULL, NULL, GetModuleHandleA(NULL), NULL);

        if (!NewWindow->WindowComponent.ComponentWindow)
        {

            MessageBoxA(NULL, "Could not create window!", "Error", MB_ICONERROR);
            return -2;

        }

    #elif defined LIN

    #endif

}

void DestroyActiveWindow(Window* CurrentWindow)
{

    free(CurrentWindow->Title);

}

bool WindowShouldClose(Window* CurrentWindow)
{

    if (PeekMessageA(&CurrentWindow->Message, NULL, 0, 0, PM_REMOVE) > 0)
    {

        TranslateMessage(&CurrentWindow->Message);
        DispatchMessage(&CurrentWindow->Message);

        if (CurrentWindow->Message.message == WM_QUIT)
            return true;

    }

    return false;

}

#ifdef WIN

    LRESULT CALLBACK WindowEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam)
    {

        switch(Message)
        {

            case WM_DESTROY:
                PostQuitMessage(0);
                break;

            default:
                return DefWindowProcA(EventWindow, Message, WParam, LParam);

        }

        return 0;

    }

#endif