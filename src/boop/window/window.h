#pragma once
/**
 * @example Window(name, width, height)
 */
#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
using namespace std;

class Window
{
private:
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event event;
    int width;
    int height;

    bool open;
public:
    Window(string name, int width, int height);
    bool isOpen() {
        return open;
    }

    SDL_Renderer* _SDL_RENDERER() {
        return render;
    }

    void start() {
        SDL_SetRenderDrawColor(render, 0,0,0,0);
        SDL_RenderClear(render);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)  {
                open = false;
            }
        }
    }
    
    void setPosition(float x, float y) {
        SDL_SetWindowPosition(window, x, y);
    }

    void setFullscreen(bool state) {
        SDL_SetWindowFullscreen(window, state);
    }

    void setSize(float width, float height) {
        SDL_SetWindowSize(window, width, height);
    }

    void end() {
        SDL_RenderPresent(render);
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }
};

Window::Window(string name, int width, int height): width(width), height(height)
{



    string sessionType = std::getenv("XDG_SESSION_TYPE"); 

    if (sessionType == "wayland") {
        setenv("SDL_VIDEODRIVER", "wayland", 1);
    }

    const bool initalized = SDL_Init(SDL_INIT_VIDEO);

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

    open = true;


}
