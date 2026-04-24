#include <SDL3/SDL.h>

class Timer
{
private:
    int tick;
    int interval;
public:
    Timer(int interval);
    ~Timer();

    bool trigger() {
        if (SDL_GetTicks() > tick) {
            tick = SDL_GetTicks() + interval;
            return true;
        } else {
            return false;
        }
    }
};

Timer::Timer(int interval): interval(interval)
{
    tick = SDL_GetTicks();
}

Timer::~Timer()
{
}
