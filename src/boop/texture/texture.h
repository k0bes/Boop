
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <boop/window/window.h>
#include <boop/texture/store.h>
class Texture
{
private:
    SDL_Texture* texture;
    Window& win;
public:
    Texture(Window& window, std::string textureLocation);

    void render(float x, float y, float width, float height) {
        SDL_FRect dst = {x, y, width, height};
        SDL_RenderTexture(win._SDL_RENDERER(), texture, NULL, &dst);

    }
    
};

Texture::Texture(Window& window, string textureLocation): win(window)
{
    texture = loadTexture(window._SDL_RENDERER(),textureLocation.c_str());
}