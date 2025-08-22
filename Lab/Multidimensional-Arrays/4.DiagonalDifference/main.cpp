#include <iostream>
#include <vector>
#include <cmath>

[[noreturn]] int main()
{
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

	for (size_t r = 0; r < n; r++)
		for (size_t c = 0; c < n; c++)
			std::cin >> matrix[r][c];

	int primaryDiag = 0, secondaryDiag = 0;

	for (int i = 0; i < n; i++) {
		primaryDiag += matrix[i][i];
		secondaryDiag += matrix[i][n - i - 1];
	}


	std::cout << std::abs(primaryDiag - secondaryDiag) << std::endl;

	return 0;
}