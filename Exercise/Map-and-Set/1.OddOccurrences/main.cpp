#include <iostream>
#include <sstream>
#include <algorithm> // for std::transform and std::find
#include <cctype> // for ::tolower
#include <set>

int main()
{
	std::set<std::string> words;

	std::string buffer;
	std::getline(std::cin, buffer);

	std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

	std::istringstream iss(buffer);

	std::string word;
	while (iss >> word) {
		std::set<std::string>::iterator outcome = words.find(word);
		if (outcome == words.end()) { // word not found
			words.insert(word);
		}
		else {
			words.erase(outcome);
		}
	}

	std::istringstream reuse(buffer);
	bool isFirst = true;
	while (reuse >> word) {
		std::set<std::string>::iterator it = words.find(word);
		if (it != words.end()) {
			if (!isFirst)
				std::cout << ", ";
			else
				isFirst = false;

			std::cout << word;
			words.erase(it);
		}
	}

	std::cout << std::endl;

	return 0;
}
