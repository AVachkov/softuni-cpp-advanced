#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string buffer;
    std::getline(std::cin, buffer);

    std::stack<size_t> openBracketsIdx;

    for (size_t i = 0; i < buffer.size(); i++)
    {
        switch (buffer[i]) {
            case '(':
                openBracketsIdx.push(i);
                break;
            case ')':
                size_t lastOpen = openBracketsIdx.top();
                openBracketsIdx.pop();

                std::string substr = buffer.substr(lastOpen, i - lastOpen + 1);
                std::cout << substr << std::endl;
                break;
        }
    }

    return 0;
}