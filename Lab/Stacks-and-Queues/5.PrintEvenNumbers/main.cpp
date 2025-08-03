#include <iostream>
#include <string>
#include <sstream>
#include <queue>

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	std::istringstream iss(buffer);

	std::queue<int> nums;

	int n;
	while (iss >> n) {
		nums.push(n);
	}

	bool isFirst = true;
	while (nums.size()) {
		if (nums.front() % 2 == 0) {
			if (isFirst)
				isFirst = false;
			else
				std::cout << ", ";

			std::cout << nums.front();
		}
		nums.pop();
	}

	std::cout << std::endl;

	return 0;
}