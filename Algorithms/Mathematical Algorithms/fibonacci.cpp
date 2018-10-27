#include <iostream>

uint64_t fibonacci(const int fib)
{
	if (fib <= 2)
		return 1;
	uint64_t prev = 1, cur = 1;
	for(auto i = 2; i < fib; ++i)
	{
		const auto tmp = cur;
		cur += prev;
		prev = tmp;
	}
	return cur;
}

int main()
{
	int i;

	std::cout << "Fibonacci: ";
	std::cin >> i;

	std::cout << static_cast<const uint64_t>(fibonacci(i)) << std::endl;
}