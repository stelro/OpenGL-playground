//
// Created by stel on 25/3/2017.
//

#ifndef OPENGLTUTORIAL_FPSLIMITER_H
#define OPENGLTUTORIAL_FPSLIMITER_H

#include <string>

class FpsLimiter {
public:
    FpsLimiter();
    ~FpsLimiter();

    void start();
    double end();

    void update_fps_counter(char *title);

private:
    double m_FrameCount;
    double m_PreviousSeconds;
};


#endif //OPENGLTUTORIAL_FPSLIMITER_H
