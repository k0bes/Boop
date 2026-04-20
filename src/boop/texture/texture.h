
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <boop/window/window.h>

class Texture
{
private:
    SDL_Texture* texture;
    Window& win;
public:
    Texture(Window& window, std::string textureLocation);
};

Texture::Texture(Window& window, string textureLocation): win(window)
{
    texture = IMG_LoadTexture(window._SDL_RENDERER(),textureLocation.c_str());
}