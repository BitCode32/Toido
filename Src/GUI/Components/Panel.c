#include "../../../Include/GUI/Components/Panel.h"

#ifdef WIN

    static bool RegisteredPanel = false;
    LRESULT CALLBACK PanelEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam);

#endif

int InitializePanel(Panel* NewPanel, Component Parent, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor)
{

    NewPanel->X = X;
    NewPanel->Y = Y;

    NewPanel->PanelComponent.Width = Width;
    NewPanel->PanelComponent.Height = Height;

    NewPanel->BackgroundColor = BackgroundColor;

    #ifdef WIN

        if (!RegisteredPanel)
        {

            WNDCLASSEXA PanelClass = { 0 };

            PanelClass.cbSize = sizeof(PanelClass);
            PanelClass.style = CS_HREDRAW | CS_VREDRAW;
            PanelClass.lpfnWndProc = PanelEventHandler;
            PanelClass.hInstance = GetModuleHandleA(NULL);
            PanelClass.hIcon = LoadIcon(PanelClass.hInstance, IDI_APPLICATION);
            PanelClass.hCursor = LoadCursor(PanelClass.hInstance, IDC_ARROW);
            PanelClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            PanelClass.lpszMenuName = NULL;
            PanelClass.lpszClassName = "Panel";

            if (!RegisterClassExA(&PanelClass))
            {

                MessageBoxA(NULL, "Could not register panel!", "Error", MB_ICONERROR);
                return -1;

            }

            RegisteredPanel = true;

        }

        NewPanel->PanelComponent.ComponentWindow = CreateWindowA("Panel", "", WS_OVERLAPPED | WS_CHILD | WS_VISIBLE, NewPanel->X, NewPanel->Y, NewPanel->PanelComponent.Width, NewPanel->PanelComponent.Height, Parent.ComponentWindow, NULL, NULL, NULL);
        SetWindowLongPtrA(NewPanel->PanelComponent.ComponentWindow, GWLP_USERDATA, (LONG_PTR)NewPanel);

    #elif defined LIN

    #endif

    return 0;

}

#ifdef WIN

    LRESULT CALLBACK PanelEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam)
    {

        switch (Message)
        {

            case WM_ERASEBKGND:
            {

                Panel* CurrentPanel = (Panel*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);

                HDC DeviceContext = (HDC)WParam;

                RECT PanelRect;
                GetClientRect(EventWindow, &PanelRect);

                HBRUSH BackgroundBrush = CreateSolidBrush(RGB(CurrentPanel->BackgroundColor.R, CurrentPanel->BackgroundColor.G, CurrentPanel->BackgroundColor.B));
                FillRect(DeviceContext, &PanelRect, BackgroundBrush);
                DeleteObject(BackgroundBrush);

                break;

            }

            default:
                return DefWindowProcA(EventWindow, Message, WParam, LParam);

        }

        return 0;

    }

#endif