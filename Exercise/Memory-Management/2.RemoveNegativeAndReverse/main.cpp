#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	int * const numbers = new int[buffer.size() / 2]; // keep the original pointer (const address) to delete[]

	std::istringstream iss(buffer);
	int idx = 0;
	while (iss >> numbers[idx])
		idx++;

	const int numbersSize = idx;
	int * const result = new int[numbersSize]; // the array could be the same size as "numbers" and also can be 0

	int resultSize = 0;
	int order = 0;
	for (int cnt = numbersSize - 1; cnt >= 0; cnt--) {
		if (numbers[cnt] >= 0) {
			result[order++] = numbers[cnt];
			resultSize++;
		}
	}

	if (resultSize == 0) {
		std::cout << "empty" << std::endl;
	}
	else {
		for (int i = 0; i < resultSize; i++) {
			std::cout << result[i] << ' ';
		}
		std::cout << std::endl;
	}

	delete[] numbers;
	delete[] result;

	return 0;
}