#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	std::vector<double> order;
	std::map<double, int> valuesCount;

	std::istringstream iss(buffer);
	double token;
	while (iss >> token) {
		std::pair<std::map<double, int>::iterator, bool> insertResult = valuesCount.insert({token, 1});
		if (insertResult.second == true) { // number doesnt exist
			order.push_back(token);
		}
		else { // the number already exists
			std::map<double, int>::iterator iteratorPointingAtExistingElement = insertResult.first;
			(*iteratorPointingAtExistingElement).second++;
		}
	}

	for (const double& n : order) {
		std::cout << n << " - " << valuesCount[n] << " times" << std::endl;
	}

	return 0;
}