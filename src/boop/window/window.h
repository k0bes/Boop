/**
 * @example Window(name, width, height)
 */
#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Window
{
private:
    SDL_Window* window;
    SDL_Renderer* render;
public:
    Window(string name, int width, int height);
};

Window::Window(string name, int width, int height)
{
    bool initalized = SDL_Init(SDL_INIT_VIDEO);

    if (!initalized) {
        cout << SDL_GetError();
        throw runtime_error("Couldn't initalize the SDL Backend.");
    }


    window = SDL_CreateWindow(name.c_str(), width,height,0);
    render = SDL_CreateRenderer(window, NULL);

    if (!render) {
        cout << "Can't create renderer. Do you have a GPU?";
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(-1);
    }

    if (!window) {
        SDL_Quit();
        exit(-1);
    }
    
}
