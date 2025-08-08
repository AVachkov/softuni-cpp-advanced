#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <climits>

int getMax(std::stack<int> inputStack)
{
	int max = INT_MIN;

	while (inputStack.size()) {
		int top = inputStack.top();
		inputStack.pop();

		if (top > max)
			max = top;
	}

	return max;
}

int getMin(std::stack<int> inputStack)
{
	int min = INT_MAX;

	while (inputStack.size()) {
		int top = inputStack.top();
		inputStack.pop();

		if (min > top)
			min = top;
	}

	return min;
}

void printStack(std::stack<int> inputStack)
{
	bool isFirst = true;
	while (inputStack.size()) {
		int top = inputStack.top();
		inputStack.pop();

		if (!isFirst) {
			std::cout << ", ";
		}
		else {
			isFirst = false;
		}
		std::cout << top;
	}
	std::cout << std::endl;
}

int main()
{
	std::string nAsString;
	std::getline(std::cin, nAsString);

	std::istringstream istr(nAsString);
	int n;
	istr >> n;

	std::stack<int> numbers;

	while (n--) {
		std::string input;
		std::getline(std::cin, input);
		std::istringstream iss(input);

		char type;
		iss >> type;

		switch (type) {
			case '1':
				int x;
				iss >> x;

				numbers.push(x);
				break;
			case '2':
				if (numbers.size() > 0)
					numbers.pop();
				break;
			case '3':
				if (numbers.size() > 0)
					std::cout << getMax(numbers) << std::endl;
				break;
			case '4':
				if (numbers.size() > 0)
					std::cout << getMin(numbers) << std::endl;
				break;
			default:
				break;
		}
	}

	printStack(numbers);

	return 0;
}