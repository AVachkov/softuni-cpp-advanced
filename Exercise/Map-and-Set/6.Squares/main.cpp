#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
	std::multiset<int> numbers;
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);

		double n;
		while (iss >> n) {
			double temp = std::sqrt(n);
			if (temp == (int)temp)
				numbers.insert(n);
		}
	}

	for (std::multiset<int>::const_reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	return 0;
}