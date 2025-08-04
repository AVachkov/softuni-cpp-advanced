#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector> // for the math approach

int main_b() // queue approach
{
	std::string firstLine;
	std::getline(std::cin, firstLine);

	std::string secondLine;
	std::getline(std::cin, secondLine);

	std::istringstream converter(secondLine);

	int n;
	converter >> n;

	std::istringstream iss(firstLine);
	std::queue<std::string> children;

	std::string kid;
	while (iss >> kid) {
		children.push(kid);
	}

	while (children.size() != 1) {
		int copy = n;

		while (true) {
			std::string frontKid = children.front();
			if (copy == 1) {
				std::cout << "Removed " << frontKid << std::endl;
				children.pop();
				break;
			}
			children.pop();
			children.push(frontKid);
			copy--;
		}
	}

	std::cout << "Last is " << children.front() << std::endl;

	return 0;
}

int main() // math approach
{
	std::string firstLine;
	std::getline(std::cin, firstLine);

	int n;
	std::cin >> n;

	std::vector<std::string> players;

	std::istringstream iss(firstLine);
	std::string kid;
	while (iss >> kid) {
		players.push_back(kid);
	}

	size_t loserIdx = 0;
	while (players.size() > 1) {
		loserIdx = (loserIdx + n - 1) % players.size();
		std::string& name = players[loserIdx];

		std::cout << "Removed " << name << std::endl;
		players.erase(players.begin() + loserIdx);
	}

	std::cout << "Last is " << players[0] << std::endl;

	return 0;
}

/*
Alva James William
2
*/

/*
Lucas Jacob Noah Logan Ethan
10
*/