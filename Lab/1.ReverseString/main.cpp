#include <iostream>
#include <string>
#include <stack>
#include <sstream>

void printStack(std::stack<char>& st)
{
    while (st.size())
    {
        std::cout << st.top();
        st.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::string input;

    std::getline(std::cin, input);
    std::istringstream iss(input);

    std::stack<char> wordInReverse;

    char c;
    while (iss.get(c))
    {
        wordInReverse.push(c);
    }

    printStack(wordInReverse);

    return 0;
}