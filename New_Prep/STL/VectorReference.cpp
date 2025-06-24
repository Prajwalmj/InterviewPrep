#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};

    std::cout << "Vector before change: " << std::endl;
    for(auto it=vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    for(auto &ele: vec)
    {
        ele++;
    }

    std::cout << "Vector after change: " << std::endl;
    for(auto it=vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}