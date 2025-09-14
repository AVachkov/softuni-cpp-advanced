#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype> // for ::tolower() and ::ispunct()

int main()
{
	std::set<std::string> words;
	{
		std::string text;
		std::getline(std::cin, text);

		for (char & ch : text) {
			if (::ispunct(ch))
				ch = ' ';
		}
		std::istringstream iss(text);
		std::string token;
		while (iss >> token)
			words.insert(token);
	}

	char letter;
	while (std::cin >> letter && letter != '.') {
		bool found = false;
		letter = static_cast<char>(::tolower(letter));
		for (std::set<std::string>::iterator it = words.begin(); it != words.end(); ++it) {
			std::string copy(it->size(), '\0');
			std::transform(it->begin(), it->end(), copy.begin(), ::tolower);

			size_t idxToLower = copy.find(static_cast<size_t>(::tolower(letter)));
			if (idxToLower != std::string::npos) {
				std::cout << *it << ' ';
				found = true;
			}
		}
		if (!found)
			std::cout << "---";
		std::cout << std::endl;
	}

	return 0;
}