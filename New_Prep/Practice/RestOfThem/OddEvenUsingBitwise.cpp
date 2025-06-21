#include <iostream>

int main()
{
    int number = 0;
    std::cout << "Enter the number" << std::endl;
    std::cin >> number;

    if(number & 1)
    {
        std::cout << "Number is odd" << std::endl;
    }
    else
    {
        std::cout << "Number is even" << std::endl;
    }
    return 0;
}