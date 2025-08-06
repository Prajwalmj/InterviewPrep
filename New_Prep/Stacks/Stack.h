#include <limits>

struct Stack
{
    int* array;
    int topIndex;
    int capacity;
};

namespace StackConstants
{
    constexpr int MAX_SIZE = 10;
}