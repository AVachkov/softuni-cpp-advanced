#include <iostream>
#include <string>

// Returns:
// nullptr if the string was parsed successfully
// pointer to the first invalid character if the string cannot be parsed
const char * intTryParse(const char * str, int * numberOut)
{
	*numberOut = 0;
	while (*str != '\0') { // every string ends at '\0'
		int digit  = *str - '0';

		if (digit < 0 || digit > 9)
			return str;

		*numberOut *= 10;
		*numberOut += digit;

		str++;
	}

	return nullptr;
}

int main()
{
	std::string strA, strB;
	std::cin >> strA >> strB;

	int a, b;

	const char* ptrA = intTryParse(strA.c_str(), &a);
	const char* ptrB = intTryParse(strB.c_str(), &b);

	if (ptrA == nullptr && ptrB == nullptr) {
		std::cout << a + b << std::endl;
	}
	else {
		if (ptrA == nullptr)
			std::cout << a << std::endl;
		else
			std::cout << "[error] " << strA << std::endl;

		if (ptrB == nullptr)
			std::cout << b << std::endl;
		else
			std::cout << "[error] " << strB << std::endl;
	}

	return 0;
}