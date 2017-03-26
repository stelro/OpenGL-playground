//
// Created by stel on 25/3/2017.
//

#ifndef OPENGLTUTORIAL_DEBUGLOG_H
#define OPENGLTUTORIAL_DEBUGLOG_H

#include <cstdarg>
#include <ctime>
#include <fstream>
#include <iostream>

inline bool restart_gl_log() {

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

inline bool gl_log(const char *message, ...) {

    va_list args;

    FILE* infile = fopen("gl.log", "a");

    if (!infile) {
        std::cerr << "Could not open gl.log file to write/read " << "\n";
        return false;
    }

    va_start(args, message);
    vfprintf(infile, message, args);
    va_end(args);
    fclose(infile);

    return true;

}

inline bool gl_log_error(const char *message, ...) {

    va_list args;

    FILE* infile = fopen("gl.log", "a");
    if (!infile) {
        std::cerr << "Could not open gl.log file to read/write" << "\n";
        return false;
    }

    va_start(args, message);
    vfprintf(infile, message, args);
    va_end(args);
    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fclose(infile);

    return true;

}




#endif //OPENGLTUTORIAL_DEBUGLOG_H
