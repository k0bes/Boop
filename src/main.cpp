#include <boop/window/window.h>
int main() {
    Window window = Window("Example Window",600,400);
    while (window.isOpen()) {
        window.start();
        window.end();
    }
    
}