#include <iostream>
#include <string>
#include <sstream>
#include <set>

int main()
{
	std::multiset<double> numbers; // also works with std::set

	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);

		double n;
		while (iss >> n)
			numbers.insert(n);
	}

	bool isFirst = true;
	for (std::multiset<double>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (!isFirst)
			std::cout << " <= ";
		else
			isFirst = false;

		std::cout << *it;
	}
	std::cout << std::endl;

	return 0;
}