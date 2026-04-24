#include <string>
#include <SDL3_ttf/SDL_ttf.h>
#include <boop/window/window.h>
#include <boop/color/color.h>
class Font
{
private:
    TTF_Font* font;
    Window& window;
public:
    Font(Window& window, std::string fontPath);
    void render(std::string text, float x, float y, Color color) {
        SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), 0, color.toSdl());
        if (!surface) return;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(window._SDL_RENDERER(), surface);
        SDL_DestroySurface(surface);

        if (!texture) return;

        float w, h;
        SDL_GetTextureSize(texture, &w, &h);

        SDL_FRect dst = { (float)x, (float)y, (float)w, (float)h };

        SDL_RenderTexture(window._SDL_RENDERER(), texture, NULL, &dst);

        SDL_DestroyTexture(texture);
    }

    void renderCenter(std::string text, float x, float y, Color color) {
        render(text,x/2 - stringWidth(text)/2,y/2 - stringHeight(text)/2,color);
    }

    void renderCenterVertically(std::string text, float x, float y, Color color) {
        render(text,x, y/2 - stringHeight(text)/2,color);
    }

    void renderCenterHorizontal(std::string text, float x, float y, Color color) {
        render(text,x/2 - stringWidth(text)/2, y,color);
    }

    float stringWidth(std::string text) {
        int w;
        TTF_GetStringSize(font,text.c_str(),text.length(),&w,0);
        return w;
    }
        
    float stringHeight(std::string text) {
        int h;
        TTF_GetStringSize(font,text.c_str(),text.length(),0,&h);
        return h;
    }
};

Font::Font(Window& window, std::string fontPath): window(window)
{
    if (!TTF_WasInit()) {
        if (!TTF_Init()) {
        }
    }
    font = TTF_OpenFont(fontPath.c_str(),20);
    if (!font) {
        SDL_Log("%s (Does the fontPath exist?)", SDL_GetError());
    }
}
