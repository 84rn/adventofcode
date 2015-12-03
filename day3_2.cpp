#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct coord
{
    int x;
    int y;

    coord() : x(0), y(0) {}
};

int main()
{
    size_t numOfHouses = 1;
    std::vector<std::pair<int, int>> santa;
    coord csanta[2];
    size_t i = 0;
    coord* pcsanta = &csanta[0];
    char c;

    santa.push_back(std::make_pair(0, 0));

    while(std::cin >> c)
    {
        switch(c)
        {
            case '^': ++(pcsanta->y); 
                      break;
            case 'v': --(pcsanta->y);
                      break;
            case '>': ++(pcsanta->x);
                      break;
            case '<': --(pcsanta->x);
                      break;
        }

        auto pair = std::make_pair(pcsanta->x, pcsanta->y);

        if(std::find(santa.begin(), santa.end(), pair) == santa.end())
        {
            ++numOfHouses;
            santa.push_back(pair);
        }

        ++i;
        i = i % 2;
        pcsanta = &csanta[i];
    }

    std::cout << "Num of houses: " << numOfHouses << std::endl;
    
    exit(0);
}

