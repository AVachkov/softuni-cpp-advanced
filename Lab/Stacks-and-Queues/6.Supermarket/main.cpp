#include <iostream>
#include <string>
#include <sstream>
#include <queue>

int main()
{
	std::queue<std::string> customers;

	std::string line;
	while (std::getline(std::cin, line) && line != "End") {
		if (line == "Paid") {
			while (customers.size()) {
				std::cout << customers.front() << std::endl;
				customers.pop();
			}
		}
		else {
			customers.push(line);
		}
	}

	std::cout << customers.size() << " people remaining." << std::endl;

	return 0;
}