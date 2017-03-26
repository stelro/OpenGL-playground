//
// Created by stel on 25/3/2017.
//

#include "FpsLimiter.h"
#include <SDL2/SDL.h>

FpsLimiter::FpsLimiter()
    : m_FrameCount(0)
    , m_PreviousSeconds(0.0f)
{

}

FpsLimiter::~FpsLimiter() {

}

void FpsLimiter::update_fps_counter(char *title) {
//    double current_seconds;
//    double elapsed_seconds;
//    current_seconds = SDL_GetTicks();
//
//    elapsed_seconds = current_seconds - previous_seconds;
//
//    if (elapsed_seconds > 0.25) {
//        previous_seconds = current_seconds;
//        double fps = (double)m_FrameCount / elapsed_seconds;
//        char tmp[128];
//        sprintf(title, "opengl @ fps: %f", fps);
//
//        m_FrameCount = 0;
//
//    }
//
//    m_FrameCount++;
}

void FpsLimiter::start() {
    m_FrameCount = SDL_GetTicks();
}

double FpsLimiter::end() {

    double elapsed_time = SDL_GetTicks() - m_FrameCount;
    if (elapsed_time < (1000/60)) {
        SDL_Delay((1000/60) - elapsed_time);
    }

    return elapsed_time;

}



