#include <iostream>

struct Node
{
    int data;
    struct Node* next;
};

void PrintSinglyLinkedList(struct Node* headNode)
{   
    std::cout << "Printing list elements: " << std::endl;
    struct Node* temp = headNode;
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}