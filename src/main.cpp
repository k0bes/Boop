#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/render/font.h>
#include <boop/texture/texture.h>
#include <boop/timer/timer.h>
#include <chrono>
#include <thread>
#include <format>
#include <string>
using namespace std;
int main() {
    Window window = Window("text.",1280,720);
    Renderer render = Renderer(window);
    Font font = Font(window, "build/font.ttf");

 
    while (window.isOpen()) {
        window.start();

        font.renderCenter("Hello, World",window.getWidth(),window.getHeight(), Color(255,255,255));
     
        window.end();        
    }
}