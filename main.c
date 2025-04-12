#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "menu.h"

int main(){
    #ifdef _WIN32
        AllocConsole();
        SetConsoleTitle("dlc lists");
        freopen("CONOUT$", "w", stdout); 
        freopen("CONIN$", "r", stdin); 
    #endif

    if(menu_main_render() != 0){
        fprintf(stderr, "Something went wrong..");
        return 1;
    }

    #ifdef _WIN32
        FreeConsole();
    #endif

    return 0;
}