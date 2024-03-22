#include "../../../Include/GUI/Components/Component.h"

void ShowComponent(Component* CurrentComponent, bool Visible)
{

    #ifdef WIN

        ShowWindow(CurrentComponent->ComponentWindow, SW_SHOW * Visible);

    #elif defined LIN

    #endif

}

void EnableComponent(Component* CurrentComponent, bool Enabled)
{

    #ifdef WIN

        EnableWindow(CurrentComponent->ComponentWindow, Enabled);

    #elif defined LIN

    #endif

}