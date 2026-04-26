# Boop
A extremely simple wrapper designed to make SDL code easier to write.
<br>
# Example
```c
#include <boop/window/window.h>
#include <boop/render/render.h>
#include <boop/render/font.h>
#include <boop/color/color.h>
int main() {
    Window window = Window("Your window name",1280,720);
    Renderer render = Renderer(window);
    Font font = Font("yourfont.ttf");
 
    while (window.isOpen()) {
        window.start();

        render.rect(0, 0, 64, 64, Color(255,255,255)); // draw a rectangle at the top left of the screen

        font.render("Hello, World",0,0,Color(255,255,255));

        window.end();
    }
}
```
