//
// Created by stel on 25/3/2017.
//

#ifndef OPENGLTUTORIAL_INPUTHANDLER_H
#define OPENGLTUTORIAL_INPUTHANDLER_H

#include <SDL2/SDL.h>
#include <map>

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void update();

    bool isPressed(SDL_Keycode);
    bool isReleased(SDL_Keycode);

    SDL_Event* getEvent() { return m_Event; }

private:
    SDL_Event *m_Event;
    std::map<SDL_Keycode, bool> m_mapKeys;
};


#endif //OPENGLTUTORIAL_INPUTHANDLER_H
