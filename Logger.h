//
// Created by Daniel Luna on 2018-12-09.
//

#ifndef MODULARCPU_LOGGER_H
#define MODULARCPU_LOGGER_H

#include <string>
#include <iostream>

#include "Timer.h"

class Logger {
public:
    void setDebug();
    void disableDebug();
    void print(const std::string message);

    void startTimer();
    void endTimer();

    std::string elapsedNanoseconds();
    std::string elapsedMilliseconds();
    std::string elapsedSeconds();

    bool debugStatus() { return m_Debug; }
private:
    bool m_Debug = false;
    Timer timer;
};


#endif //MODULARCPU_LOGGER_H
