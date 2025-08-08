#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
	std::stack<int> sequence;
	int rackCapacity;

	{
		std::string buffer;
		std::getline(std::cin, buffer);

		std::istringstream iss(buffer);

		int n;
		while (iss >> n)
			sequence.push(n);
	}

	std::cin >> rackCapacity;

	int sum = 0, neededRacks = 0;

	while (sequence.size()) {
		int top = sequence.top();
		sequence.pop();

		sum += top;
		if (sum == rackCapacity) {
			neededRacks++;
			sum = 0;
		}
		else if (sum > rackCapacity) {
			neededRacks++;
			sum = top;
		}
	}

	if (sum > 0)
		neededRacks++;

	std::cout << neededRacks << std::endl;

	return 0;
}