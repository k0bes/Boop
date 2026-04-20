#include <boop/window/window.h>
#include <boop/render/render.h>

int main() {
    Window window = Window("Example Window",600,400);
    Renderer render = Renderer(window);
    
    while (window.isOpen()) {
        window.start();

        render.rect(0,0,100,20,Color(255,255,255));

        window.end();
    }
}