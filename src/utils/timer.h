#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    void Start();
    double GetElapsedSeconds() const;

private:
    std::chrono::steady_clock::time_point m_startTime;
};

#endif // TIMER_H