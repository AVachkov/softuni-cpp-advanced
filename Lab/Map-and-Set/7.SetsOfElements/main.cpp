#include <iostream>
#include <set>
#include <algorithm>
#include <utility>

int main()
{
	std::set<int> first, second;

	int n, m;
	std::cin >> n >> m;

	while (n--) {
		int number;
		std::cin >> number;
		first.insert(number);
	}

	while (m--) {
		int number;
		std::cin >> number;
		second.insert(number);
	}

	for (const int& num : first) {
		std::set<int>::iterator isFound = second.find(num);

		if (isFound != second.end()) {
			std::cout << num << ' ';
		}
	}
	std::cout << std::endl;

	return 0;
}