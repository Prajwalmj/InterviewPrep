#include <cinttypes>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

void getDigits(uint64_t a, std::vector<uint64_t>& digitsOutput)
{
    while(a)
    {
        uint64_t reminder = a%10;
        a = a/10;
        digitsOutput.push_back(reminder);
    }
}

uint64_t combineDigits(const std::vector<uint64_t>& digits)
{
    for(auto i : digits)
    {
        std::cout << i;
    }
    std::cout << std::endl;
    uint64_t result = 0;
    size_t length = digits.size();

    for(size_t i = 0; i < length; i++)
    {
        result = (result * 10) + digits[i];
        std::cout << "Result is: " << result << std::endl;
    }
    return result;
}

uint64_t descedingOrder(uint64_t a)
{
    std::vector<uint64_t> digits;
    getDigits(a, digits);
    std::sort(digits.begin(), digits.end(), std::greater<uint64_t>());

    return combineDigits(digits);
}

int main()
{
    std::cout << descedingOrder(2211088459476314232);
    return 0;
}