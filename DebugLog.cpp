//
// Created by stel on 25/3/2017.
//

#include "DebugLog.h"

#include <cstdarg>
#include <ctime>
#include <fstream>
#include <iostream>

DebugLog::DebugLog() {

}

DebugLog::~DebugLog() {

}

bool DebugLog::restart_gl_log() {

    std::fstream infile("gl.log");
    if (!infile.is_open()) {
        std::cerr << "Could not write / open to gl.log file " << std::endl;
        return false;
    }

    time_t now = time (NULL);
    char *date = ctime(&now);
    infile << "GL_LOG_FILE log. local time : " << date << "\n";
    infile.close();

    return true;
}

bool DebugLog::gl_log(const char *message, ...) {



}



