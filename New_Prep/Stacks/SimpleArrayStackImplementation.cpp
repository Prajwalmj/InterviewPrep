#include "Stack.h"
#include <iostream>


//This is simple array based implementation => limitation => fixed size
Stack* CreateStack()
{
    Stack* newStack = new Stack();
    newStack->topIndex = -1;    
    newStack->capacity = StackConstants::MAX_SIZE;
    newStack->array = new int[StackConstants::MAX_SIZE];

    return newStack;
}

//Need to delete heap allocated array first, then heap allocated stack
void DeleteStack(Stack* tempStack)
{
    if(tempStack)
    {
        if(tempStack->array)
        {
            delete[] tempStack->array;
        }
        delete tempStack;
    }
}

bool IsStackFull(Stack* tempStack)
{
    return (tempStack->topIndex == StackConstants::MAX_SIZE) - 1;
}

bool IsStackEmpty(Stack* tempStack)
{
    return (tempStack->topIndex == -1);
}

void Push(Stack* tempStack, int pushElement)
{
    if(!IsStackFull(tempStack))
    {
        tempStack->array[++tempStack->topIndex] = pushElement;
    }
    else
    {
        std::cout << "Given stack is full. Cannot push the element into it." << std::endl;
    }
}

int Pop(Stack* tempStack)
{
    if(!IsStackEmpty(tempStack))
    {
        return tempStack->array[tempStack->topIndex--];
    }
    else
    {
        std::cout << "Given stack is empty. Hence returning least possible integer." << std::endl;
        return std::numeric_limits<int>::min();
    }
}

//Add peek function to get top element
//

int main()
{

    //Add some test code to test funtionality
    return 0;
}