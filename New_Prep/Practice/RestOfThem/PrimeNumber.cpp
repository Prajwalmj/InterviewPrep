#include <iostream>

bool IsPrime(int number)
{
    bool isPrime = true;
    for(int i = 2; i<=(number/2); i++)
    {
        if((number%i) == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int main()
{
    int n;
    std::cout << "Enter input number: " << std::endl;
    std::cin >> n;
    
    std::cout << "Is Prime: " << IsPrime(n) << std::endl;
    return 0;
}