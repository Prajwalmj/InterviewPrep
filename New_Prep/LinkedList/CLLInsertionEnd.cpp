#include "List.h"
#include <iostream>

void InsertIntoEndCLL(struct Node** headNode, int data)
{
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->next = newNode;

    if(!(*headNode))
    {
        std::cout << "CLL is empty. Insering new node ..." << std::endl;
        *headNode = newNode;
    }
    else
    {
        struct Node* temp = *headNode;
        do
        {
            temp = temp->next;
        }
        while(temp->next != *headNode);

        newNode->next = *headNode;
        temp->next = newNode;
    }

    std::cout << "CLL after insertion is: " << std::endl;
    struct Node* current = *headNode;
    do
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    while(current != *headNode);

}

int main()
{   
    Node* node1 = new Node();
    node1->data = 1;

    Node node2;
    node2.data = 6;
    Node node3;
    node3.data = 19;
    Node node4;
    node4.data = 4;
    Node node5;
    node5.data = 7;

    node1->next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = node1;

    InsertIntoEndCLL(&node1, 29);
    // Node* anotherNode1 = new Node(); //Empty list case
    // anotherNode1 = NULL;
    // InsertIntoEndCLL(&anotherNode1, 29);
    return 0;
}