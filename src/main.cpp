#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/texture/texture.h>

int main() {
    Window window = Window("Example Window",800,600);
    Renderer render = Renderer(window);
    Texture texture = Texture(window, "image.png");
    
    while (window.isOpen()) {
        window.start();
        render.rect(0,0,100,80,Color(255,255,255));

        window.end();
    }
}