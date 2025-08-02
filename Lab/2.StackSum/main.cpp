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

    int num;
    while (iss >> num)
    {
        nums.push(num);
    }

    std::string input;
    while (std::getline(std::cin, input) && input != "end")
    {
        std::istringstream args(input);

        std::string cmd;
        args >> cmd;

        if (cmd == "add")
        {
            int a, b;

            args >> a >> b;

            nums.push(a);
            nums.push(b);
        }
        else if (cmd == "remove")
        {
            int a;
            args >> a;

            if (a <= nums.size())
            {
                for (int i = 0; i < a; i++)
                {
                    nums.pop();
                }
            }
        }
    }

    int sum = 0;
    while (nums.size())
    {
        sum += nums.top();
        nums.pop();
    }

    std::cout << sum << std::endl;

    return 0;
}