#include <chrono>
#include <iostream>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};

int main() {
	volatile int sum = 0, arr[999][999];
	Timer timemime;
    for (int j = 0; j < 2; ++j)
		for (int i = 0; i < 3; ++i)
			sum += arr[i][j];
	return 0;
}