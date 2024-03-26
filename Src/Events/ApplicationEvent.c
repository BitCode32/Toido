#include "../../Include/Events/ApplicationEvent.h"

void InitializeWindowResizeEvent(WindowResizeEvent* NewResizeEvent, unsigned int Width, unsigned int Height)
{

    NewResizeEvent->ApplicationEvent.Type = WindowResize;
    NewResizeEvent->ApplicationEvent.Category = EventCategoryApplication;

    NewResizeEvent->Width = Width;
    NewResizeEvent->Height = Height;

}

void InitializeWindowCloseEvent(WindowCloseEvent* NewCloseEvent)
{

    NewCloseEvent->ApplicationEvent.Type = WindowClose;
    NewCloseEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeWindowFocusEvent(WindowFocusEvent* NewFocusEvent)
{

    NewFocusEvent->ApplicationEvent.Type = WindowFocus;
    NewFocusEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeWindowLostFocusEvent(WindowLostFocusEvent* NewLostFocusEvent)
{

    NewLostFocusEvent->ApplicationEvent.Type = WindowLostFocus;
    NewLostFocusEvent->ApplicationEvent.Category = EventCategoryApplication;

}

void InitializeComponentEvent(ComponentEvent* NewComponentEvent, unsigned int ComponentId, unsigned int ComponentEvent)
{

    NewComponentEvent->ApplicationEvent.Type = ApplicationComponent;
    NewComponentEvent->ApplicationEvent.Category = EventCategoryApplication;

    NewComponentEvent->ComponentId = ComponentId;
    NewComponentEvent->ComponentEvent = ComponentEvent;

}