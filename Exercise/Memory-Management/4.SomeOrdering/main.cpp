#include <iostream>

const size_t maxCharBuffer = 1000;

int main()
{
	char * const buffer = new char[maxCharBuffer];

	int idx = 0;
	char ch;
	while (std::cin.get(ch) && ch != '\n') {
		buffer[idx] = ch;
		idx++;
	}

	// we are not allowed to use STL
	// thus we will use C functions ::tolower() and ::toupper()

	const int size = idx;

	for (int i = 0; i < size; i++) {
		std::cout << static_cast<char>(::tolower(buffer[i]));
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << static_cast<char>(::toupper(buffer[i]));
	}
	std::cout << std::endl;

	delete[] buffer;

	return 0;
}