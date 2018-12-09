//
// Created by Daniel Luna on 2018-12-09.
//

#ifndef MODULARCPU_TIMER_H
#define MODULARCPU_TIMER_H

#include <chrono>

class Timer{
public:
    void Start();
    void Stop();
    double elapsedNanoseconds();
    double elapsedMilliseconds();
    double elapsedSeconds();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
    bool m_isRunning = false;
};

#endif //MODULARCPU_TIMER_H
