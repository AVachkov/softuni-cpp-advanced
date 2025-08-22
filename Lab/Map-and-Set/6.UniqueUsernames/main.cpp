#include <iostream>
#include <set>
#include <string>

int main()
{
	std::set<std::string> usernames;

	int n;
	std::cin >> n;

	while (n--) {
		std::string username;
		std::cin >> username;

		usernames.insert(username);
	}

	for (const std::string& username : usernames) {
		std::cout << username << std::endl;
	}

	return 0;
}