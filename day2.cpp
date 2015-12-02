#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

class Present
{
public:
   std::vector<size_t> vsize;
   size_t area;
   size_t slack;
};

std::istream& operator>>(std::istream& s, Present& p)
{
    std::string data;
    if(!std::getline(s, data))
        return s;

    std::stringstream stream(data);
    char c;
    size_t n1, n2, n3;

    stream >> n1 >> c >> n2 >> c >> n3;

    p.vsize.push_back(n1);
    p.vsize.push_back(n2);
    p.vsize.push_back(n3);

    std::sort(p.vsize.begin(), p.vsize.end());

    p.area = (2 * n1 * n2) + (2 * n2 * n3) + (2 * n1 * n3);
    p.slack = p.vsize[0] * p.vsize[1];

    return s;
};

size_t sum_presents(size_t init, Present& p)
{
    return init + p.area + p.slack;
}
    
int main()
{
    Present p;
    std::vector<Present> vp;

    while(std::cin >> p)
        vp.push_back(p);    

    std::cout << "Area of " << vp.size() << " presents: " << std::accumulate(vp.begin(), vp.end(), 0, sum_presents) << std::endl;

    exit(0);
}

