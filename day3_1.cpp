#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    size_t numOfHouses = 1;
    std::vector<std::pair<int, int>> coords;
    int x = 0, y = 0;
    char c;

    coords.push_back(std::make_pair(0, 0));

    while(std::cin >> c)
    {
        switch(c)
        {
            case '^': ++y; 
                      break;
            case 'v': --y;
                      break;
            case '>': ++x;
                      break;
            case '<': --x;
                      break;
        }

        auto pair = std::make_pair(x, y);

        if(std::find(coords.begin(), coords.end(), pair) == coords.end())
        {
            ++numOfHouses;
            coords.push_back(pair);
        }
    }

    std::cout << "Num of houses: " << numOfHouses << std::endl;
    
    exit(0);
}

