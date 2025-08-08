#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <climits>

int main()
{
	int food;
	std::queue<int> orders;

	{
		std::string firstLine;
		std::getline(std::cin, firstLine);

		std::istringstream converter(firstLine);
		converter >> food;
	}

	{
		std::string secondLine;
		std::getline(std::cin, secondLine);

		std::istringstream iss(secondLine);

		int order;
		while (iss >> order) {
			orders.push(order);
		}
	}

	int biggestOrder = INT_MIN;

	while (food >= 0 && orders.size()) {
		int currentOrder = orders.front();

		if (biggestOrder < currentOrder) {
			biggestOrder = currentOrder;
		}

		int diff = food - currentOrder;
		if (diff >= 0) { // order can be done
			food -= currentOrder;
			orders.pop();
		}
		else
			break;
	}

	std::cout << biggestOrder << std::endl;

	if (orders.size() == 0) {
		std::cout << "Orders complete";
	}
	else {
		std::cout << "Orders left: ";
		while (orders.size()) {
			std::cout << orders.front() << ' ';
			orders.pop();
		}
	}
	std::cout << std::endl;

	return 0;
}