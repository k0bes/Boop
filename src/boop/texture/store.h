#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include <boop/window/window.h>
#include <string>
static std::unordered_map<std::string, SDL_Texture*> textures;
static SDL_Texture* loadTexture(SDL_Renderer* ren, std::string texture) {
    try
    {
        return textures.at(texture);
    }
    catch(const std::exception& e)
    {
        SDL_Texture* loadedTexture = IMG_LoadTexture(ren,texture.c_str());

        textures.insert({texture, loadedTexture});
        return loadedTexture;
    }
    

}