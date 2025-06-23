#include <iostream>
#include <set>

int main()
{
    int arr[7] = {1, 2, 5, 4, 2, 5, 4};
    std::set<int> arrayElements, duplicateElements;

    int size = sizeof(arr)/sizeof(int);

    std::cout << "The array size is: " << std::endl;
    for(int i = 0; i < size; i++)
    {
        if(arrayElements.find(arr[i]) != arrayElements.end())
        {
            duplicateElements.insert(arr[i]);
        }
        else
        {
            arrayElements.insert(arr[i]);
        }
    }

    std::cout << "Duplicate elements are: " << std::endl;

    for(auto &ele : duplicateElements)
    {
        std::cout << ele << std::endl;
    }
    return 0;
}