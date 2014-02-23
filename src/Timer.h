#ifndef PKMN_SDL_TIMER
#define PKMN_SDL_TIMER

#include "../SDL.h"

using namespace Core;

namespace GUI {

class Timer
{
  public:
    Timer (void);

    void start (void);
    void stop (void);
    void pause (void);
    void unpause (void);

    int getTicks (void);

    bool isStarted (void);
    bool isPaused (void);

  protected:
    int _startTicks;

    int _pausedTicks;

    bool _paused;

    bool _started;

};

};
#endif

