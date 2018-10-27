#include <iostream>
#include <vector>
#include <random>

void merge(std::vector<int>& input, std::vector<int>& output, size_t l, const size_t l_max, size_t r,
           const size_t r_max)
{
	auto out = l;
	while (l < l_max && r < r_max)
	{
		if (input[l] <= input[r])
			output[out++] = input[l++];
		else if (input[l] > input[r])
			output[out++] = input[r++];
	}
	while (l < l_max)
		output[out++] = input[l++];
	while (r < r_max)
		output[out++] = input[r++];
}

void merge_all(std::vector<int>& input, std::vector<int>& output, const size_t merge_size)
{
	for (size_t i = 0; i < input.size(); i += merge_size * 2)
	{
		const auto l_max = std::min(input.size(), i + merge_size);
		const auto r_max = std::min(input.size(), i + 2 * merge_size);
		merge(input, output, i, l_max, i + merge_size, r_max);
	}
}

std::vector<int> merge_sort(std::vector<int>& input)
{
	const auto size = input.size();
	std::vector<int> output(size);

	for (size_t merge_size = 1; merge_size < size; merge_size *= 2)
	{
		merge_all(input, output, merge_size);
		std::swap(input, output);
	}
	return input;
}

void printArray(std::vector<int>& array)
{
	for (auto i : array)
		std::cout << i << " ";
	std::cout << "\n";
}

std::vector<int> createArray(const size_t size)
{
	std::vector<int> array(size);
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = std::rand();
	}
	return array;
}

int main()
{
	size_t size;
	std::cin >> size;

	auto input(createArray(size));

	std::cout << "Given array is\n";
	printArray(input);

	input = merge_sort(input);

	std::cout << "\nSorted array is \n";
	printArray(input);
	return 0;
}
