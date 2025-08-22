#include <iostream>
#include <map>
#include <utility>

int main()
{
	std::map<int, int> occurrences;

	int n;
	std::cin >> n;

	while (n--) {
		int num;
		std::cin >> num;
		if (!occurrences.insert({num, 1}).second) { // key already exists
			occurrences[num]++;
		}
		// occurrences[num]++; // simpler way
	}

	for (const std::pair<const int, int>& occurrence : occurrences) {
		if (occurrence.second % 2 == 0) {
			std::cout << occurrence.first << std::endl;
			break;
		}
	}

	return 0;
}