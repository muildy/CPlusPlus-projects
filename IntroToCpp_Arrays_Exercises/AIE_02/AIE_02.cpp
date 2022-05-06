
#include <iostream>

int MinValue(const int* arr, int count);
int MaxValue(const int* arr, int count);
int CountOccurencesOfValue(const int* arr, int count, int search);


int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 10;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };

	// In C++, an array is simply a pointer to the first value
	// when passing an array through a function parameter, we loose the length information
	// therefore we need to pass the array size in as well

	// implement the above methods
	// so that the expected output is printed to the console

	std::cout << "Expected: 10 - Got: " << MinValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 50 - Got: " << MaxValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 2 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 10) << std::endl;
	std::cout << "Expected: 0 - Got: " << CountOccurencesOfValue(numbers, NUM_NUMBERS, 8) << std::endl;

	return 0;
}


int MinValue(const int* arr, int count)
{
	int min = arr[0];
	// TODO: loop through the array, return the smallest value
	for (int i = 0; i < count; ++i) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

int MaxValue(const int* arr, int count)
{
	int max = arr[0];
	// TODO: loop through the array, return the largest value
	for (int i = 0; i < count; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int CountOccurencesOfValue(const int* arr, int count, int search)
{
	int result = 0;
	// TODO: loop through the array, return the amount of times search appears
	for (int i = 0; i < count; i++) {
		if (search == arr[i]) {
			result++;
		}
	}
	return result;
}

