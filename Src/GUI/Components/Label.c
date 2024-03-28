#include "../../../Include/GUI/Components/Label.h"

#ifdef WIN

    LRESULT CALLBACK LabelEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam);

#endif

void InitializeLabel(Label* NewLabel, Component Parent, unsigned int Id, char* Text, unsigned int X, unsigned int Y, unsigned int Width, unsigned int Height, Color BackgroundColor, Font ButtonFont)
{

    NewLabel->Id = Id;

    NewLabel->X = X;
    NewLabel->Y = Y;
    NewLabel->LabelComponent.Width = Width;
    NewLabel->LabelComponent.Height = Height;

    NewLabel->BackgroundColor = BackgroundColor;
    NewLabel->LabelFont = ButtonFont;

    NewLabel->TextLength = 0;
    while (Text[NewLabel->TextLength] != '\0')
        NewLabel->TextLength++;

    NewLabel->Text = (char*)malloc(sizeof(char) * (NewLabel->TextLength + 1));
    for (unsigned int i = 0; i <= NewLabel->TextLength; i++)
        NewLabel->Text[i] = Text[i];

    #ifdef WIN

        NewLabel->LabelComponent.ComponentWindow = CreateWindowA("static", NewLabel->Text, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, NewLabel->X, NewLabel->Y, NewLabel->LabelComponent.Width, NewLabel->LabelComponent.Height, Parent.ComponentWindow, (HMENU)NewLabel->Id, NULL, NULL);

        SetWindowLongPtrA(NewLabel->LabelComponent.ComponentWindow, GWLP_WNDPROC, (LONG_PTR)LabelEventHandler);
		SetWindowLongPtrA(NewLabel->LabelComponent.ComponentWindow, GWLP_USERDATA, (LONG_PTR)NewLabel);

    #elif defined LIN

    #endif

}

LRESULT CALLBACK LabelEventHandler(HWND EventWindow, UINT Message, WPARAM WParam, LPARAM LParam)
{

    switch (Message)
    {
    
        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_XBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP:
        case WM_XBUTTONUP:
            SendMessageA(GetParent(EventWindow), Message, WParam, LParam);
            break;        

        case WM_PAINT:
        {

            Label* CurrentLabel = (Label*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);

            PAINTSTRUCT LabelPaintStruct;
            HDC DeviceContext = BeginPaint(EventWindow, &LabelPaintStruct);

            HFONT PreviousFont = (HFONT)SelectObject(DeviceContext, CurrentLabel->LabelFont.ApiFont);

            RECT LabelRect;
            GetClientRect(EventWindow, &LabelRect);

            SetBkColor(DeviceContext, RGB(CurrentLabel->BackgroundColor.R, CurrentLabel->BackgroundColor.G, CurrentLabel->BackgroundColor.B));
            SetTextColor(DeviceContext, RGB(CurrentLabel->LabelFont.TextColor.R, CurrentLabel->LabelFont.TextColor.G, CurrentLabel->LabelFont.TextColor.B));
            DrawTextA(DeviceContext, CurrentLabel->Text, CurrentLabel->TextLength, &LabelRect, DT_NOPREFIX | DT_NOCLIP | DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            SelectObject(DeviceContext, PreviousFont);

            EndPaint(EventWindow, &LabelPaintStruct);
            break;

        }

        default:
            return DefWindowProc(EventWindow, Message, WParam, LParam);

    }

    return 0;

}