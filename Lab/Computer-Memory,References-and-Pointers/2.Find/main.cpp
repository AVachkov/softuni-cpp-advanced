#include <iostream>
#include <string>

int main()
{
	char buffer[10000];
	char * nextData = buffer;

	int companiesCount = 0;

	std::string name;
	int id;

	while (std::cin >> name && name != "end") {
		companiesCount++;
		std::cin >> id;

		int * idAddress = (int *)nextData;
		*idAddress = id;

		nextData += sizeof(int);

		for (int i = 0; i < name.size(); i++) {
			*nextData = name[i];
			nextData++;
		}
		*nextData = '\0';
		nextData++;
	}

	int target;
	std::cin >> target;

	bool isFound = false;
	int * idPtr = (int *)buffer;
	for (int i = 0; i < companiesCount; i++) {
		std::string name;
		char * namePtr = (char *)idPtr + sizeof(int);
		while (*namePtr != '\0') {
			name += *namePtr;
			namePtr += sizeof(char);
		}

		if (*idPtr == target) {
			std::cout << name << ' ' << *idPtr << std::endl;
			isFound = true;
			break;
		}
		char * temp = namePtr;
		temp += sizeof(char);
		idPtr = (int *)temp;
	}

	if (!isFound)
		std::cout << "[not found]" << std::endl;

	return 0;
}