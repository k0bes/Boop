#pragma once
#include <boop/window/window.h>
#include <boop/color/color.h>
#include <math.h>
class Renderer
{
private:
    SDL_Renderer* ren;
public:
    Renderer(Window window);

    void rect(float x, float y, float w, float h, Color color) {
        SDL_FRect rect = { x, y, w, h };
        SDL_SetRenderDrawColor(ren, color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
        SDL_RenderFillRect(ren, &rect);
    }
};

Renderer::Renderer(Window window)
{
    ren = window._SDL_RENDERER();
}