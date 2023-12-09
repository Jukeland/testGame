#include <iostream>

static bool running = true;

int main(){

    int n = 0;
    std::cout << "XD? " << n << std::endl;

    while(running){

        // Update
        n++;
        if(n < 10)
            std:: cout << "XD?\n";

    }

    return 0;
}