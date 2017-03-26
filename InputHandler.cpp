//
// Created by stel on 25/3/2017.
//

#include "InputHandler.h"


InputHandler::InputHandler()
    : m_Event(new SDL_Event())
{

}

InputHandler::~InputHandler() {

}

void InputHandler::update() {


}

bool InputHandler::isPressed(SDL_Keycode keycode) {

    return ((m_Event->type == SDL_KEYDOWN) && (m_Event->key.keysym.sym == keycode));

}

bool InputHandler::isReleased(SDL_Keycode) {
    return false;
}



