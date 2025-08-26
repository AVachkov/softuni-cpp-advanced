#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void methodA(std::vector<std::vector<int> >& matrix)
{
	int num = 1;
	for (int c = 0; c < matrix[0].size(); c++) {
		for (int r = 0; r < matrix.size(); r++) {
			matrix[r][c] = num++;
		}
	}
}

void methodB(std::vector<std::vector<int> >& matrix)
{
	int num = 1;
	for (int col = 0; col < matrix[0].size(); col++) {
		if (col % 2 == 0) {
			// even column - top to bottom
			for (int row = 0; row < matrix.size(); row++)
				matrix[row][col] = num++;
		}
		else {
			// odd column - bottom to top
			for	(int row = matrix.size() - 1; row >= 0; row--)
				matrix[row][col] = num++;
		}
	}
}

int main()
{
	int N;
	char method;
	{
		std::string firstArgAsStr;
		std::cin >> firstArgAsStr;
		firstArgAsStr.pop_back();
		std::istringstream tempIss(firstArgAsStr);
		tempIss >> N;
	}
	std::cin >> method;

	std::vector<std::vector<int> > matrix(N, std::vector<int>(N));

	switch (method) {
		case 'A':
			methodA(matrix);
			break;
		case 'B':
			methodB(matrix);
			break;
	}

	for (int r = 0; r < matrix.size(); r++) {
		for (int c = 0; c < matrix[r].size(); c++) {
			std::cout << matrix[r][c] << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}