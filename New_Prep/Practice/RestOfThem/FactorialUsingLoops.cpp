#include <iostream>

int Factorial(int n)
{
    int result = 1;
    if((n == 0) || (n==1))
    {
        result = 1;
    }
    else
    {
        for(int i=n; i>1; i--)
        {
            result = result*i;
        }
    }
    return result;
}

int main()
{
    int number;
    std::cout << "Enter the number" << std::endl;
    std::cin >> number;

    std::cout << "Factorial is: " << Factorial(number) << std::endl;
    return 0;
}