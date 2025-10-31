#include "logger.h"
#include <iostream>

std::ofstream Logger::s_LogFile;

void Logger::Init(const std::string& filename) {
    s_LogFile.open(filename, std::ios::out | std::ios::app);
    if(!s_LogFile.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void Logger::Log(const std::string& message) {
    if(s_LogFile.is_open()) {
        s_LogFile << message << std::endl;
    }
}

void Logger::Shutdown() {
    if(s_LogFile.is_open()) {
        s_LogFile.close();
    }
}