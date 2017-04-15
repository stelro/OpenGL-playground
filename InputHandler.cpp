//
// Created by stel on 26/3/2017.
//

#include "InputHandler.h"

InputHandler* InputHandler::m_Instance;

InputHandler::InputHandler()
        : m_Event(new SDL_Event())
        , m_MouseCoordX(0.0f)
        , m_MouseCoordY(0.0f)
{

}

InputHandler::~InputHandler() {

    delete m_Event;

}

InputHandler *InputHandler::instance() {

    if (m_Instance) {
        return m_Instance;
    }

    else {
        m_Instance = new InputHandler();
        return m_Instance;
    }

}

void InputHandler::deleteInstance() {

    if (m_Instance) {
        delete m_Instance;
        m_Instance = nullptr;
    }
    else {
        return;
    }
}

void InputHandler::update() {

    for (auto& i : m_mapKeys ) {
        m_PreviousMapKeys[i.first] = i.second;
    }

    while (SDL_PollEvent(m_Event)) {

        switch(m_Event->type) {

            case SDL_KEYDOWN:
                this->pressKey(m_Event->key.keysym.sym);
                break;
            case SDL_KEYUP:
                this->releaseKey(m_Event->key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->pressKey(m_Event->button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                this->releaseKey(m_Event->button.button);
                break;
            case SDL_MOUSEMOTION:
                this->m_MouseCoordX = m_Event->motion.x;
                this->m_MouseCoordY = m_Event->motion.y;
                break;
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;

        }

    }

}

bool InputHandler::isPressed(SDL_Keycode key) {

    if (isHoldDown(key) && !wasKeyDown(key)) {
        return true;
    }

    return false;
}

bool InputHandler::isHoldDown(SDL_Keycode key) {

    auto it = m_mapKeys.find(key);
    if (it != m_mapKeys.end()) {
        return it->second;
    } else {
        return false;
    }
}


bool InputHandler::wasKeyDown(SDL_Keycode key) {

    auto it = m_PreviousMapKeys.find(key);
    if (it != m_PreviousMapKeys.end()) {
        return it->second;
    } else {
        return false;
    }

}

bool InputHandler::pressKey(SDL_Keycode key) {

    m_mapKeys[key] = true;
}

bool InputHandler::releaseKey(SDL_Keycode key) {

    m_mapKeys[key] = false;
}




