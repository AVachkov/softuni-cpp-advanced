#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

int main_1() // with set and vector
{
	std::set<std::string> names;
	std::vector<std::string> order;

	int n;
	std::cin >> n;

	while (n--) {
		std::string name;
		std::cin >> name;
		std::pair<std::set<std::string>::iterator, bool> insertResult = names.insert(name);

		if (insertResult.second) // successful insertion
			order.push_back(name);
	}

	for (const std::string& name : order)
		std::cout << name << std::endl;

	return 0;
}

int main() // only with vector
{
	std::vector<std::string> names;

	int n;
	std::cin >> n;

	while (n--) {
		std::string name;
		std::cin >> name;

		std::vector<std::string>::iterator it = std::find(names.begin(), names.end(), name);

		if (it == names.end()) { // the name doesn't exist
			names.push_back(name);
		}
	}

	for (const std::string& name : names)
		std::cout << name << std::endl;
}