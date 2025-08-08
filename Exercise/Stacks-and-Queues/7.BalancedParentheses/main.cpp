#include <iostream>
#include <string>
#include <stack>

bool isBalanced(const std::string& expression)
{
	std::stack<char> openBrackets;

	for (char c : expression) {
		switch (c) {
			case '(':
			case '[':
			case '{':
				openBrackets.push(c);
				break;
			case ')':
			case ']':
			case '}': {
				if (openBrackets.size() == 0)
					return false;

				const char top = openBrackets.top();
				openBrackets.pop();

				if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}'))
					return false;
				break;
			}
		}
	}

	return openBrackets.size() == 0;
}

int main()
{
	std::string expression;
	std::getline(std::cin, expression);

	std::cout << (isBalanced(expression) ? "YES" : "NO") << std::endl;

	return 0;
}