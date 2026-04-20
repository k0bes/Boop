#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/texture/texture.h>

int main() {
    Window window = Window("Example Window",1280,720);
    Renderer render = Renderer(window);
    Texture texture = Texture(window, "image.png");
    
    while (window.isOpen()) {
        window.start();

        texture.render(0,0,693,199);

        window.end();
    }
}