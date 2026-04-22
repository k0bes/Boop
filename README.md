# Boop
A extremely simple wrapper designed to make SDL code easier to write.
<br>
# Example
```c
#include <boop/window/window.h>
#include <boop/render/render.h>

int main() {
    Window window = Window("Your window name",1280,720);
    Renderer render = Renderer(window);
 
    while (window.isOpen()) {
        window.start();

        render.rect(0, 0, 64, 64, Color(255,255,255)); // draw a rectangle at the top left of the screen

        window.end();
    }
}
```