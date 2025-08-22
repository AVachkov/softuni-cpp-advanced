#include <iostream>
#include <string>
#include <sstream>
#include <set>

int main()
{
	std::set<double, std::greater<double>> nums;
	{
		std::string buffer;
		std::getline(std::cin, buffer);

		std::istringstream iss(buffer);

		double token;
		while (iss >> token) {
			nums.insert(token);
		}
	}
	std::set<double>::iterator it = nums.begin();
	int counter = 0;
	while (it != nums.end() && counter < 3) {
		std::cout << *it << ' ' << std::flush;
		++it;
		counter++;
	}
	std::cout << std::endl;

	// another way of solving the exercise is by using reverse_iterator
	return 0;
}