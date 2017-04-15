//
// Created by stel on 26/3/2017.
//

#ifndef INPUTHANDLING_INPUTHANDLER_H
#define INPUTHANDLING_INPUTHANDLER_H

#include <SDL2/SDL.h>
#include <unordered_map>

class InputHandler {
public:

    static InputHandler*                        instance();
    static void                                 deleteInstance();

    SDL_Event*                                  getEvent() const { return m_Event; }

    void                                        update();

    bool                                        isPressed(SDL_Keycode key);
    bool                                        isHoldDown(SDL_Keycode key);

    float                                       mouseCoordX() const { return m_MouseCoordX; }
    float                                       mouseCoordY() const { return m_MouseCoordY; }

private:
    InputHandler();
    ~InputHandler();

    bool                                        wasKeyDown(SDL_Keycode key);
    bool                                        pressKey(SDL_Keycode key);
    bool                                        releaseKey(SDL_Keycode key);

    static InputHandler*                        m_Instance;

    SDL_Event*                                  m_Event;

    std::unordered_map<SDL_Keycode, bool>       m_mapKeys;
    std::unordered_map<SDL_Keycode, bool>       m_PreviousMapKeys;

    float                                       m_MouseCoordX;
    float                                       m_MouseCoordY;

};


#endif //INPUTHANDLING_INPUTHANDLER_H
