#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	int * numbers = new int[buffer.size() / 2 + 1]; // delete[] !!!

	int counter = 0;
	std::istringstream iss(buffer);
	while (iss >> numbers[counter])
		counter++;

	const int numbersSize = counter;
	int * const gauss = new int[numbersSize / 2 + numbersSize % 2]; // delete[] !!!

	int gaussCnt = 0;
	for ( ; gaussCnt < numbersSize / 2; gaussCnt++)
		gauss[gaussCnt] = numbers[gaussCnt] + numbers[(numbersSize - 1) - gaussCnt];

	if (numbersSize % 2) {
		gauss[gaussCnt] = numbers[numbersSize / 2];
		gaussCnt++;
	}

	for (int curr = 0; curr < gaussCnt; curr++)
		std::cout << gauss[curr] << ' ';
	std::cout << std::endl;

	delete[] numbers;
	delete[] gauss;

	// second variant: without second "gauss" array
	// directly printing the sums

	return 0;
}