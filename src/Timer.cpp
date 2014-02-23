#include "Timer.h"

namespace GUI {

Timer::Timer (void)
{
    _startTicks  = 0;
    _pausedTicks = 0;
    _paused      = false;
    _started     = false;
}

void Timer::start (void)
{
    _started    = true;
    _paused     = false;
    _startTicks = SDL_GetTicks();
}

void Timer::stop (void)
{
    _started = false;
    _paused  = false;
}

void Timer::pause (void)
{
    if (_started && !_paused) {
        _paused      = true;
        _pausedTicks = SDL_GetTicks() - _startTicks;
    }
}

void Timer::unpause (void)
{
    if (_paused) {
        _paused      = false;
        _startTicks  = SDL_GetTicks() - _pausedTicks;
        _pausedTicks = 0;
    }
}

int Timer::getTicks (void)
{
    if (_started) {
        if (_paused) {
            return _pausedTicks;
        }
        else {
            return SDL_GetTicks() - _startTicks;
        }
    }

    return 0;
}

bool Timer::isStarted (void)
{
    return _started;
}

bool Timer::isPaused (void) {
    return _paused;
}

};
