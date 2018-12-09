//
// Created by Daniel Luna on 2018-12-09.
//

#include "Timer.h"

void Timer::Start(){
    m_StartTime = std::chrono::high_resolution_clock::now();
    m_isRunning = true;
}

void Timer::Stop(){
    m_EndTime = std::chrono::high_resolution_clock::now();
    m_isRunning = true;
}

double Timer::elapsedNanoseconds(){
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

    if(m_isRunning)
    {
        endTime = std::chrono::high_resolution_clock::now();
    }
    else
    {
        endTime = m_EndTime;
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_StartTime).count();
}

double Timer::elapsedMilliseconds(){
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

    if(m_isRunning)
    {
        endTime = std::chrono::high_resolution_clock::now();
    }
    else
    {
        endTime = m_EndTime;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

double Timer::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}