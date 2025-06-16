#include <iostream>

// Not efficient way of solving, just implemented for understanding
int Fibonacci(int n)
{
    //base case
    if(n <= 1)
    {
        return n;
    }

    return (Fibonacci(n-1) + Fibonacci(n-2));
}

int main()
{
    int noOfTerms = 0;
    std::cout << "Enter the number of terms: " << std::endl;
    std::cin >> noOfTerms;

    std::cout << "The Fibonacci series is: " << std::endl;

    for(int i=0; i<=noOfTerms; i++)
    {
        std::cout << Fibonacci(i) << std::endl;
    }

    return 0;
}