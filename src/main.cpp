#include "dog_lib.h"

//  #######################################################################################
//                                   Platform Globals
//  #######################################################################################

static bool running = true;

//  #######################################################################################
//                                  Platform Functions
//  #######################################################################################

bool platform_create_window(int width, int height, char* title);
void platform_update_window();

//  #######################################################################################
//                                  Windows Platform
//  #######################################################################################

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

//  #######################################################################################
//                                  Windows Globals
//  #######################################################################################

static HWND window;

//  #######################################################################################
//                                Platform Implementations
//  #######################################################################################

LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam){
    LRESULT result = 0;

    switch(msg){
        case WM_CLOSE:{
            running = false;
            break;
            }
        
        default:{
            result = DefWindowProcA(window, msg, wParam, lParam);
        }
    }

    return result;
}

bool platform_create_window(int width, int height, char* title){

    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;           // Not the title
    wc.lpfnWndProc = windows_window_callback;    // Callbakck for input into the window

    if(!RegisterClassA(&wc)){
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0, title, title, dwStyle, 100, 100, width, height, 
                                    NULL, NULL, instance, NULL);

    if(window == NULL)
        return false;

    ShowWindow(window, SW_SHOW);

    return true;

}

void platform_update_window(){

    MSG message;
    while(PeekMessageA(&message, window, 0, 0, PM_REMOVE)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

}


#endif

int main(){

    platform_create_window(1200, 720, "Dog");
    while(running){

        // Update
        platform_update_window();

        SM_TRACE("Test");
        SM_WARN("Test");
        SM_ERROR("Test");
    }

    return 0;
}