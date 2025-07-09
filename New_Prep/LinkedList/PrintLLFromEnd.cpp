#include "List.h"
#include <iostream>

void PrintLLFromEnd(Node* head)
{
    if(head == nullptr)
    {
        return;
    }

    PrintLLFromEnd(head->next);
    std::cout << head->data << std::endl;
}

int main()
{
    Node* node21 = new Node();
    Node* node22 = new Node();
    Node* node23 = new Node();
    Node* node24 = new Node();

    node21->data = 21;
    node21->next = node22;

    node22->data = 27;
    node22->next = node23;

    node23->data = 2;
    node23->next = node24;

    node24->data = 19;
    node24->next = nullptr;

    PrintLLFromEnd(node21);
    return 0;
}