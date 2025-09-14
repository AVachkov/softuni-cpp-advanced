#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool earliestLexicographically(const std::string & current, const std::string & result)
{
	return current < result;
}

bool shortestString(const std::string & current, const std::string & result)
{
	return current.size() < result.size();
}

bool longestString(const std::string & current, const std::string & result)
{
	return current.size() > result.size();
}

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	std::vector<std::string> words;

	{
		std::istringstream iss(buffer);
		std::string word;
		while (iss >> word)
			words.push_back(word);
	}

	int option;
	std::cin >> option;

	bool (*func)(const std::string & current, const std::string & result);
	switch (option) {
		case 1:
			func = &earliestLexicographically;
			break;
		case 2:
			func = &shortestString;
			break;
		case 3:
			func = &longestString;
			break;
	}

	std::string result = words[0];

	for (int i = 1; i < words.size(); i++) {
		if (func(words[i], result))
			result = words[i];
	}

	std::cout << result << std::endl;

	return 0;
}