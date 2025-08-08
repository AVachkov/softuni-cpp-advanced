#include <iostream>
#include <queue>
#include <climits>

int main()
{
	int n, s, x;
	std::cin >> n >> s >> x;

	std::queue<int> nums;

	while (n--) {
		int current;
		std::cin >> current;
		nums.push(current);
	}

	while (s--) {
		nums.pop();
	}

	if (nums.size() == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}

	int min = INT_MAX;
	while (nums.size()) {
		int front = nums.front();
		nums.pop();

		if (front == x) {
			std::cout << "true" << std::endl;
			return 0;
		}

		if (min > front) {
			min = front;
		}
	}

	std::cout << min << std::endl;

	return 0;
}