// #include <iostream>
// #include <map>
// #include <utility>
// #include <sstream>
//
// int main()
// {
// 	std::map<std::string, std::pair<std::string, std::string> > locations;
// 	// using std::string for coordinates for precise floating point number
//
// 	std::string line;
// 	while (std::getline(std::cin, line) && line != ".") {
// 		std::istringstream inputStream(line);
//
// 		std::string name, latitude, longitude;
// 		std::getline(inputStream, name, ',');
// 		std::getline(inputStream, latitude, ',');
// 		std::getline(inputStream, longitude);
//
// 		locations.insert(std::pair<std::string, std::pair<std::string, std::string> >(name, std::pair<std::string, std::string>(latitude, longitude)));
//
// 		// can't do this because if you enter a location twice it will override the first entered coordinates with the second ones
// 		// locations[name].first = latitude;
// 		// locations[name].second = longitude;
// 	}
//
// 	while (std::getline(std::cin, line) && line != ".") {
// 		// search by name
// 		bool isNameFound = false;
// 		auto it = locations.find(line);
// 		if (it != locations.end()) {
// 			std::cout << it->first << ',' << it->second.first << ',' << it->second.second << std::endl;
// 			isNameFound = true;
// 		}
//
// 		// search by coordinates
// 		if (!isNameFound) {
// 			std::istringstream tempIss(line);
// 			std::string x, y;
// 			tempIss >> x >> y;
// 			for (const std::pair<const std::string, std::pair<std::string, std::string> > & kvp : locations) {
// 				if (kvp.second.first == x && kvp.second.second == y) {
// 					std::cout << kvp.first << ',' << kvp.second.first << ',' << kvp.second.second << std::endl;
// 					// continue searching for other places with the same coordinates
// 				}
// 			}
// 		}
// 	}
//
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

std::vector<std::string> names;
std::vector<std::string> coordinates;

void printLocation(std::size_t locationIndex)
{
	std::cout << names[locationIndex] << ',' << coordinates[locationIndex] << std::endl;
}

void doLocation(const std::string& name)
{
	std::vector<std::string>::iterator itFound = std::find(names.begin(), names.end(), name);
	if (itFound == names.end())
		return;

	printLocation(itFound - names.begin());
}

void doCoordinates(const std::string& coords)
{
	std::istringstream istr(coords);
	std::string latitude, longitude;
	istr >> latitude >> longitude;
	std::string findCoords = latitude + "," + longitude;

	std::vector<std::string>::iterator itCur = coordinates.begin();
	while ((itCur = std::find(itCur, coordinates.end(), findCoords)) != coordinates.end()) {
		printLocation(itCur - coordinates.begin());
		++itCur;
	}
}

int main()
{
	while (true) {
		std::string data;
		std::getline(std::cin, data);
		if (data == ".")
			break;

		std::istringstream row(data);
		std::string name, coords;

		std::getline(row, name, ',');
		std::getline(row, coords);

		names.push_back(name);
		coordinates.push_back(coords);
	}

	while (true) {
		std::string data;
		std::getline(std::cin, data);
		if (data == ".")
			break;

		if (!data.empty() && std::isalpha(static_cast<unsigned char>(data[0]))) {
			doLocation(data);
		} else {
			doCoordinates(data);
		}
	}

	return 0;
}