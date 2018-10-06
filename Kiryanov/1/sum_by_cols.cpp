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

int main()
{
	const size_t max_size = 100;
	int** f = new int*[max_size];
	for (int i = 0; i < max_size; i++)
		f[i] = new int[max_size];
	for (int i = 0; i < max_size; i++)
		for (int j = 0; j < max_size; j++)
			f[i][j] = rand() - rand();
	Timer* t = new Timer[1];
	int counter = 0;
	for (int i = 0; i < max_size; i++)
		for (int j = 0; j < max_size; j++)
			counter += f[j][i];
	delete[] t;
	for (int i = 0; i < max_size; i++)
		delete[] f[i];
	return 0;
}