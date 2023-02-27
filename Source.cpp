#include <iostream>
#include <chrono>

struct timer
{
    void reset() { start = std::chrono::steady_clock::now(); }

    unsigned long long milliseconds_elapsed() const
    {
        const auto now = clock::now();
        using namespace std::chrono;
        return duration_cast<milliseconds>(now - start).count();
    }

    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
};
