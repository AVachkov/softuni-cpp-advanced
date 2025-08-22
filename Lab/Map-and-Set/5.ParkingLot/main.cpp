#include <iostream>
#include <string>
#include <sstream>
#include <set>

int main()
{
	std::set<std::string> cars;

	std::string input;
	while (std::getline(std::cin, input) && input != "END") {
		std::istringstream iss(input);

		std::string direction, plateNumber;
		iss >> direction >> plateNumber;

		direction.pop_back();

		std::set<std::string>::iterator it = cars.insert(plateNumber).first; // insert returns iterator (.first) and bool (.second)
		if (direction == "OUT")
			cars.erase(it);
	}

	if (cars.size() == 0) {
		std::cout << "Parking Lot is Empty" << std::endl;
	}
	else {
		for (const std::string& plate : cars) {
			std::cout << plate << std::endl;
		}
	}
	return 0;
}