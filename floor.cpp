#include <iostream>

int main()
{
    char c;
    int floor = 0;

    while(std::cin >> c)
    {
        if(c == '(')
            ++floor;
        else if(c == ')')
            --floor;
    }

    std::cout << "Floor: " << floor << std::endl;

    exit(0);
}
