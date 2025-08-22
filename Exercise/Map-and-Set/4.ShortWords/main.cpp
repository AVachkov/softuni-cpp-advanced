#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <map>
#include <utility>

int main()
{
	std::map<std::string, size_t> wordsLen;

	{
		std::string line;
		std::getline(std::cin, line);

		std::transform(line.begin(), line.end(), line.begin(), ::tolower);

		std::istringstream iss(line);

		std::string word;
		while (iss >> word)
			wordsLen.insert(std::pair<std::string, int>(word, word.size()));
	}

	bool isFirst = true;
	for (std::map<std::string, size_t>::iterator it = wordsLen.begin(); it != wordsLen.end(); ++it) {
		if (it->second < 5) {
			if (!isFirst)
				std::cout << ", ";
			else
				isFirst = false;

			std::cout << it->first;
		}
	}
	std::cout << std::endl;

	return 0;
}