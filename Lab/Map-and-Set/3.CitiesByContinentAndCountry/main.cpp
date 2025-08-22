#include <iostream>
#include <map>
#include <set>
#include <utility>

int main()
{
	std::map<std::string, // continent
		std::map<std::string, // country
			std::set<std::string> // city
				>> data;

	int n;
	std::cin >> n;

	while (n--) {
		std::string continent, country, city;
		std::cin >> continent >> country >> city;

		data[continent][country].insert(city);
	}

	for (const std::pair<const std::string, std::map<std::string, std::set<std::string>>>& continentCountriesPair : data) {
		std::cout << continentCountriesPair.first << ':' << std::endl;

		for (const std::pair<const std::string, std::set<std::string>>& countriesCitiesPair : continentCountriesPair.second) {
			std::cout << '\t' << countriesCitiesPair.first << " -> ";

			bool isFirst = true;
			for (const std::string& city : countriesCitiesPair.second) {
				if (!isFirst)
					std::cout << ", ";
				else
					isFirst = false;

				std::cout << city;
			}
			std::cout << std::endl;
		}
	}

	return 0;
}