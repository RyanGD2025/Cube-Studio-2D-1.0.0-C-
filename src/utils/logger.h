#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    static void Init(const std::string& filename);
    static void Log(const std::string& message);
    static void Shutdown();

private:
    static std::ofstream s_LogFile;
};

#endif // LOGGER_H