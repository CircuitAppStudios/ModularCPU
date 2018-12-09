//
// Created by Daniel Luna on 2018-12-09.
//

#include "Logger.h"

void Logger::setDebug(){
    m_Debug = true;
}

void Logger::disableDebug(){
    m_Debug = false;
}

void Logger::print(const std::string message){
    if(m_Debug) {
        std::cout << message << std::endl;
    }
}

void Logger::startTimer(){
    if(m_Debug){
        timer.Start();
    }
}

void Logger::endTimer(){
    if(m_Debug){
        timer.Stop();
    }
}

std::string Logger::elapsedNanoseconds(){
    return std::to_string(timer.elapsedNanoseconds());
}

std::string Logger::elapsedMilliseconds(){
    return std::to_string(timer.elapsedMilliseconds());
}
std::string Logger::elapsedSeconds(){
    return std::to_string(timer.elapsedSeconds());
}