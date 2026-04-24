#pragma once
class Color
{
private:
    int red;
    int green;
    int blue;
    int alpha;
public:
    Color(int r, int g, int b, int a);
    Color(int r, int g, int b);

    int getRed()
    {
        return red;
    }

    int getGreen() {
        return green;
    }

    int getBlue() {
        return blue;
    }

    int getAlpha() {
        return alpha;
    }

    SDL_Color toSdl() {
        SDL_Color sdl;
        sdl.r = red;
        sdl.g = green;
        sdl.b = blue;
        sdl.a = alpha;
        return sdl;
    }
};

Color::Color(int r, int g, int b, int a)
{
    red = r;
    green = g;
    blue = b;
    alpha = a;
}

Color::Color(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
    alpha = 255;
}
