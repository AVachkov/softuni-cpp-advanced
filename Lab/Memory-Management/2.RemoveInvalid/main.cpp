#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void * readCompany(std::istream & inputStream)
{
	std::string firstArg, secondArg;
	inputStream >> firstArg;

	if (firstArg == "end")
		return nullptr;

	int id = std::stoi(firstArg);
	inputStream >> secondArg;

	// allocate enough dynamic memory for both the id and the string + '\0'
	// buffer stores id (int) + name (C-string) in contiguous memory
	char * buffer = new char[sizeof(int) + secondArg.size() + 1]; // dont forget delete[] !!!
	char * startOfMemory = buffer;
	int * idPtr = reinterpret_cast<int *>(buffer);
	*idPtr = id;
	buffer += sizeof(int);

	for (char ch : secondArg) {
		*buffer = ch;
		buffer += sizeof(char);
	}
	*buffer = '\0';

	return startOfMemory;
}

int main()
{
	std::vector<void *> data;

	std::string firstArg;
	while (true) {
		void * newCompany = readCompany(std::cin);

		if (newCompany == nullptr) // reached "end"
			break;

		data.push_back(newCompany);
	}

	for (void * info : data) {
		int * idPtr = static_cast<int *>(info);
		if (*idPtr >= 0) {
			char * namePtr = reinterpret_cast<char *>(idPtr) + sizeof(int);
			std::cout << *idPtr << ' ' << namePtr << std::endl;
		}
	}

	// after everything we do - deallocate allocated memory (ignore CLion compiler warnings)
	for (void * element : data)
		delete[] static_cast<char *>(element);

	data.clear();

	return 0;
}