#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::vector<char>> matrix(n, std::vector<char>(n)); // could use vector<string>

	for (size_t r = 0; r < n; r++) {
		for (size_t c = 0; c < n; c++) {
			std::cin >> matrix[r][c];
		}
	}

	char target;
	std::cin >> target;

	bool isFound = false;
	size_t rowFoundAt = 0, colFoundAt = 0;
	for (size_t r = 0; r < n; r++) {
		for (size_t c = 0; c < n; c++) {
			if (matrix[r][c] == target) {
				isFound = true;
				rowFoundAt = r;
				colFoundAt = c;
				break;
			}
		}
		if (isFound)
			break;
	}

	if (isFound)
		std::cout << '(' << rowFoundAt << ", " << colFoundAt << ')';
	else
		std::cout << target << " does not occur in the matrix";

	std::cout << std::endl;

	return 0;
}