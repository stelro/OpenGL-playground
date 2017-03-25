//
// Created by stel on 25/3/2017.
//

#ifndef OPENGLTUTORIAL_DEBUGLOG_H
#define OPENGLTUTORIAL_DEBUGLOG_H


class DebugLog {
public:
    DebugLog();
    ~DebugLog();

    bool restart_gl_log();
    bool gl_log(const char* message, ...);

private:

};


#endif //OPENGLTUTORIAL_DEBUGLOG_H
