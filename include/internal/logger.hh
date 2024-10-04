#if defined(DEBUG)
#include <iostream>
#endif

class Logger {
public:
#ifdef DEBUG
    static void log(const std::string& message) {
        std::cout << message << std::endl;
    }
#endif
};
