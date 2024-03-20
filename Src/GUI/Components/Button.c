#include "../../../Include/GUI/Components/Button.h"

#include <stdlib.h>
#include <stddef.h>

#ifdef WIN

    LRESULT CALLBACK EventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam);

#endif

int InitializeButton(Button* NewButton, Component Parent, unsigned int Id, char* Text, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor, Font ButtonFont)
{

    NewButton->Id = Id;

    NewButton->X = X;
    NewButton->Y = Y;
    NewButton->ButtonComponent.Width = Width;
    NewButton->ButtonComponent.Height = Height;

    NewButton->BackgroundColor = BackgroundColor;
    NewButton->ButtonFont = ButtonFont;

    NewButton->Hovering = false;
    NewButton->Pressed = false;

    unsigned int Length = 0;
    while (Text[Length] != '\0')
        Length++;

    NewButton->Text = (char*)malloc(sizeof(char) * (Length + 1));
    for (unsigned int i = 0; i <= Length; i++)
        NewButton->Text[i] = Text[i];

    #ifdef WIN

        NewButton->ButtonComponent.ComponentWindow = CreateWindowA("Button", NewButton->Text, WS_CHILD | WS_VISIBLE, NewButton->X, NewButton->Y, NewButton->ButtonComponent.Width, NewButton->ButtonComponent.Height, Parent.ComponentWindow, (HMENU)NewButton->Id, NULL, NULL);
        SendMessageA(NewButton->ButtonComponent.ComponentWindow, WM_SETFONT, (WPARAM)NewButton->ButtonFont.ApiFont, 0);

        NewButton->OldProc = (WNDPROC)SetWindowLongPtrA(NewButton->ButtonComponent.ComponentWindow, GWLP_WNDPROC, (LONG_PTR)EventHandler);
		SetWindowLongPtrA(NewButton->ButtonComponent.ComponentWindow, GWLP_USERDATA, (LONG_PTR)NewButton);

    #elif defined LIN

    #endif

    return 0;

}

void DestroyButton(Button* CurrentButton)
{

    free(CurrentButton->Text);

}

LRESULT CALLBACK EventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam)
{

    switch(Message)
    {

        default:
            return CallWindowProcA(((Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA))->OldProc, EventWindow, Message, WParam, LParam);

    }

    return 0;

}