#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
using namespace std;

class Texture
{
private:
    SDL_Texture* texture;
public:
    Texture(string textureLocation);
};

Texture::Texture(string textureLocation)
{
}