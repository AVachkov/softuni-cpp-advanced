#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <climits>

int main()
{
	std::string buffer;
	std::getline(std::cin, buffer);

	std::istringstream args(buffer);

	int n, s, x;
	args >> n >> s >> x;

	std::getline(std::cin, buffer);
	std::istringstream numsIss(buffer);

	std::stack<int> nums;

	int token;
	while (n-- && numsIss >> token) {
		nums.push(token);
	}

	while (s--) {
		nums.pop();
	}

	if (nums.size() == 0) {
		std::cout << 0;
		return 0;
	}

	bool isFound = false;
	int min = INT_MAX;

	while (nums.size()) {
		int top = nums.top();
		nums.pop();

		if (x == top) {
			std::cout << "true";
			isFound = true;
			break;
		}

		if (min > top) {
			min = top;
		}
	}

	if (!isFound) {
		std::cout << min;
	}

	std::cout << std::endl;

	return 0;
}