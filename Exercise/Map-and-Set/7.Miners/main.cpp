#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
	std::unordered_map<std::string, size_t> resources;
	std::vector<std::string> order;

	std::string resource;
	size_t quantity;
	while (std::cin >> resource && resource != "stop") {
		std::cin >> quantity;
		std::pair<std::unordered_map<std::string, size_t>::iterator, bool> insertRes = resources.insert(std::pair<std::string, size_t>(resource, quantity));

		if (!insertRes.second) // if the resource exists
			insertRes.first->second += quantity;
		else
			order.push_back(insertRes.first->first);
	}

	for (const std::string & current : order)
		std::cout << current << " -> " << resources[current] << std::endl;

	return 0;
}