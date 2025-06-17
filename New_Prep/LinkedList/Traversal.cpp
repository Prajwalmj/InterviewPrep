#include "List.h"
#include <iostream>

void TraverseLinkedList(struct Node* listHead)
{
    if(!listHead)
    {
        std::cout << "Linked List is empty." << std::endl;
        return;
    }

    struct Node* current = listHead;
    int length = 0;

    while(current != NULL)
    {
        length++;
        std::cout << current->data << std::endl;
        current = current->next;
    }

    std::cout << "Length of the list is: " << length << std::endl;
}

int main()
{
    //Create Linked List
    Node n1;
    n1.data = 5;

    Node n2;
    n2.data = 7;

    Node n3;
    n3.data = 9;

    //Assign next pointers
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    Node* n4 = nullptr;
    TraverseLinkedList(&n1);
    //Test for empty list case.
    TraverseLinkedList(n4);
}