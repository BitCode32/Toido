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

    NewButton->TextLength = 0;
    while (Text[NewButton->TextLength] != '\0')
        NewButton->TextLength++;

    NewButton->Text = (char*)malloc(sizeof(char) * (NewButton->TextLength + 1));
    for (unsigned int i = 0; i <= NewButton->TextLength; i++)
        NewButton->Text[i] = Text[i];

    #ifdef WIN

        NewButton->ButtonComponent.ComponentWindow = CreateWindowA("Button", NewButton->Text, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, NewButton->X, NewButton->Y, NewButton->ButtonComponent.Width, NewButton->ButtonComponent.Height, Parent.ComponentWindow, (HMENU)NewButton->Id, NULL, NULL);
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

        case WM_LBUTTONDOWN:
        {

            Button* CurrentButton = (Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);
            CurrentButton->Pressed = true;
            CurrentButton->Hovering = true;

            SetCapture(CurrentButton->ButtonComponent.ComponentWindow);
            InvalidateRect(CurrentButton->ButtonComponent.ComponentWindow, NULL, TRUE);

            break;

        }

        case WM_LBUTTONUP:
        {

            Button* CurrentButton = (Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);
            CurrentButton->Pressed = false;

            RECT ButtonRect;
            GetWindowRect(EventWindow, &ButtonRect);

            POINT CursorPosition;
            GetCursorPos(&CursorPosition);

            if (PtInRect(&ButtonRect, CursorPosition))
            {

                CurrentButton->Hovering = true;
                SendMessageA(GetParent(EventWindow), WM_COMMAND, MAKEWORD(CurrentButton->Id, BN_CLICKED), 0);

            }

            ReleaseCapture();
            InvalidateRect(EventWindow, NULL, TRUE);

            break;

        }

        case WM_MOUSEMOVE:
        {

            Button* CurrentButton = (Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);

            if (!CurrentButton->Pressed && !CurrentButton->Hovering)
            {

                CurrentButton->Hovering = true;

                RECT buttonRect;
                GetClientRect(EventWindow, &buttonRect);

                InvalidateRect(EventWindow, &buttonRect, TRUE);

            }

            TRACKMOUSEEVENT MouseEvent;

            MouseEvent.cbSize = sizeof(MouseEvent);
            MouseEvent.dwFlags = TME_LEAVE;
            MouseEvent.hwndTrack = EventWindow;

            TrackMouseEvent(&MouseEvent);

            break;

        }
        
        case WM_MOUSELEAVE:
        {

            Button* CurrentButton = (Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);
            CurrentButton->Hovering = false;

            if (!CurrentButton->Pressed)
            {

                RECT buttonRect;
                GetClientRect(EventWindow, &buttonRect);

                InvalidateRect(EventWindow, &buttonRect, TRUE);

            }

            break;

        }

        case WM_PAINT:
        {

            Button* CurrentButton = (Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA);

            PAINTSTRUCT ButtonPaintStruct;
            HDC DeviceContext = BeginPaint(EventWindow, &ButtonPaintStruct);

            RECT ButtonRect;
            GetClientRect(EventWindow, &ButtonRect);

            Color BackgroundColor = CurrentButton->BackgroundColor;
            Color TopLeftPenColor = CurrentButton->BackgroundColor;
            Color BottomRightPenColor = CurrentButton->BackgroundColor;

            if (CurrentButton->Pressed)
            {

                ChangeColorBrightness(&BackgroundColor, 0.8f);

                ChangeColorBrightness(&TopLeftPenColor, 0.9f);
                ChangeColorBrightness(&BottomRightPenColor, 1.1f);

            }
            else
            {

                if (CurrentButton->Hovering)
                    ChangeColorBrightness(&BackgroundColor, 0.9f);

                ChangeColorBrightness(&TopLeftPenColor, 1.1f);
                ChangeColorBrightness(&BottomRightPenColor, 0.9f);

            }

            HBRUSH BackgroundBrush = CreateSolidBrush(RGB(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B));
            HBRUSH PreviousBrush = (HBRUSH)SelectObject(DeviceContext, BackgroundBrush);

            Rectangle(DeviceContext, ButtonRect.left, ButtonRect.top, ButtonRect.right, ButtonRect.bottom);

            SelectObject(DeviceContext, PreviousBrush);
            DeleteObject(BackgroundBrush);

            HPEN TopLeftPen = CreatePen(PS_SOLID, 2, RGB(TopLeftPenColor.R, TopLeftPenColor.G, TopLeftPenColor.B));
            HPEN BottomRightPen = CreatePen(PS_SOLID, 2, RGB(BottomRightPenColor.R, BottomRightPenColor.G, BottomRightPenColor.B));

            HPEN PreviousePen = (HPEN)SelectObject(DeviceContext, TopLeftPen);

            MoveToEx(DeviceContext, ButtonRect.left, ButtonRect.bottom, NULL);
            LineTo(DeviceContext, ButtonRect.left, ButtonRect.top - 1);
            LineTo(DeviceContext, ButtonRect.right - 1, ButtonRect.top);            

            SelectObject(DeviceContext, BottomRightPen);

            LineTo(DeviceContext, ButtonRect.right - 1, ButtonRect.bottom);
            LineTo(DeviceContext, ButtonRect.left - 1, ButtonRect.bottom);

            SelectObject(DeviceContext, PreviousePen);

            DeleteObject(TopLeftPen);
            DeleteObject(BottomRightPen);

            HFONT PreviousFont = (HFONT)SelectObject(DeviceContext, CurrentButton->ButtonFont.ApiFont);

            SetBkColor(DeviceContext, RGB(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B));
            SetTextColor(DeviceContext, RGB(CurrentButton->ButtonFont.TextColor.R, CurrentButton->ButtonFont.TextColor.G, CurrentButton->ButtonFont.TextColor.B));
            DrawTextA(DeviceContext, CurrentButton->Text, CurrentButton->TextLength, &ButtonRect, DT_NOPREFIX | DT_NOCLIP | DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            SelectObject(DeviceContext, PreviousFont);

            EndPaint(EventWindow, &ButtonPaintStruct);
            break;

        }

        default:
            return CallWindowProcA(((Button*)GetWindowLongPtrA(EventWindow, GWLP_USERDATA))->OldProc, EventWindow, Message, WParam, LParam);

    }

    return 0;

}