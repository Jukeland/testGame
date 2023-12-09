//  #######################################################################################
//                                   Platform Globals
//  #######################################################################################

static bool running = true;

//  #######################################################################################
//                                  Platform Functions
//  #######################################################################################

bool platformCreateWindow(int width, int height, char* title);

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



//  #######################################################################################
//                                Platform Implementations
//  #######################################################################################

bool platformCreateWindow(int width, int height, char* title){

    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;           // Not the title
    wc.lpfnWndProc = DefWindowProcA;    // Callbakck for input into the window

    if(!RegisterClassA(&wc)){
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    HWND window = CreateWindowExA(0, title, title, dwStyle, 100, 100, width, height, 
                                    NULL, NULL, instance, NULL);

    if(window == NULL)
        return false;

    ShowWindow(window, SW_SHOW);

    return true;

}


#endif

int main(){

    platformCreateWindow(1200, 720, "Dog");
    while(running){

        // Update

    }

    return 0;
}