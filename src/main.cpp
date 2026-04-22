#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/render/font.h>


int main() {
    Window window = Window("text.",1280,720);
    Renderer render = Renderer(window);
    Font font = Font(window, "font.ttf");
 
    while (window.isOpen()) {
        window.start();

        font.render("Hello, World!", 0, 0, Color(255,255,255));

        window.end();
    }
}