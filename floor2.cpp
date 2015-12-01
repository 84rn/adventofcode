#include <iostream>

int main()
{
    char c;
    int floor = 0;
    int position = 1;

    while(std::cin >> c)
    {
        if(c == '(')
            ++floor;
        else if(c == ')')
            --floor;

        if(floor == -1)
            break;

        ++position;
    }

    std::cout << "Position: " << position << std::endl;

    exit(0);
}
