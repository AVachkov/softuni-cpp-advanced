#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);

    std::stack<int> nums;
    std::stack<char> operations;

    int number;
    while (iss >> number)
    {
        nums.push(number);

        char op;
        if (iss >> op)
            operations.push(op);
        else
            break;
    }

    int sum = 0;
    while (operations.size())
    {
        char op = operations.top();
        operations.pop();

        int arg = nums.top();
        nums.pop();

        switch (op)
        {
        case '+':
            sum += arg;
            break;
        case '-':
            sum -= arg;
            break;
        }
    }

    if (nums.size())
    {
        sum += nums.top();
        nums.pop();
    }

    std::cout << sum << std::endl;

    return 0;
}