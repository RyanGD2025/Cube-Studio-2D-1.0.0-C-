#include "timer.h"

Timer::Timer() {
    Start();
}

void Timer::Start() {
    m_startTime = std::chrono::steady_clock::now();
}

double Timer::GetElapsedSeconds() const {
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - m_startTime;
    return elapsed.count();
}