#include <iostream>
#include <vector>

int main()
{
	int dimensions;
	std::cin >> dimensions;

	std::vector<std::vector<int> > matrix(dimensions, std::vector<int>(dimensions));

	for (int r = 0; r < dimensions; r++) {
		for (int c = 0; c < dimensions; c++) {
			std::cin >> matrix[r][c];
		}
	}

	int sum = 0;
	for (int i = 0; i < dimensions; i++) {
		sum += matrix[i][i];
	}

	std::cout << sum << std::endl;

	return 0;
}