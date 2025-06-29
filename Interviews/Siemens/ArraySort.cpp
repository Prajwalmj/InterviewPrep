//Problem statememt:
// Input: {1, 2, 0, 4, 3, 0, 5, 0}
// Output: {1, 2, 3, 4, 5, 0, 0, 0}

//No need for generic output, just give correct output for this input/requirement
-
#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 8> inputArr = {1, 2, 0, 4, 3, 0, 5, 0};
    std::array<int, 8> result{};
    
    std::cout << "After declaration: " << std::endl;
    for(size_t i=0; i<result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    std::sort(inputArr.begin(), inputArr.end());

    //naive approach
    // size_t zeroCount = 0;

    // for(size_t i=0; i<inputArr.size(); i++)
    // {
    //     if(inputArr[i] == 0)
    //     {
    //         zeroCount++;
    //     }
    // }

    //using stl
    size_t zeroCount = std::count(inputArr.begin(), inputArr.end(), 0);

    std::cout << "ZeroCount: " << zeroCount << std::endl; 

    int j = 0;
    for(size_t i=(inputArr.size() - 1);  j<zeroCount; i--)
    {
        j++;
        result[i] = 0;
    }

    for(size_t i=zeroCount, j=0; i<inputArr.size(); i++, j++)
    {
        result[j] = inputArr[i];
    }

    std::cout << "Array after soring" << std::endl;
    for(size_t i=0; i<result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
    
    return 0;
}