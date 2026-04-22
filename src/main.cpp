#include <boop/window/window.h>
#include <boop/render/render.h>



int main() {
    Window window = Window("text.",1280,720);
    Renderer render = Renderer(window);
 
    while (window.isOpen()) {
        window.start();
        window.end();
    }
}