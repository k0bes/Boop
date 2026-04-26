#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/render/font.h>
#include <boop/texture/texture.h>
#include <boop/timer/timer.h>
#include <chrono>
#include <thread>
#include <format>
#include <string>
#include <filesystem>
using namespace std;
int main() {
    Window window = Window("Application Launcher",1280,720);
    Renderer render = Renderer(window);
    Font font = Font(window, "build/font.ttf");

 
    while (window.isOpen()) {
        window.start();

        window.end();        
    }
}