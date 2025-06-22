#include "List.h"
#include <iostream>

void DeleteCLLAtBeginning(struct Node** headNode)
{
    if(*headNode == NULL)
    {
        std::cout << "CLL is empty. Nothing to delete." << std::endl;
        return;
    }

    struct Node* temp = *headNode;
    struct Node* current = *headNode;
    do
    {
        current = current->next;
    }while(current->next != *headNode);

    current->next = (*headNode)->next;
    *headNode = (*headNode)->next;

    delete temp;

    std::cout << "CLL after deletion at beginning is: " << std::endl;
    struct Node* currentTemp = *headNode;
    do
    {
        std::cout << currentTemp->data << std::endl;
        currentTemp = currentTemp->next;
    }
    while(currentTemp != *headNode);
}

int main()
{
    Node* node1 = new Node();
    node1->data = 1;

    //Not good, don't mix stack and heap allocation for node creations
    //Will create issues when deleting/freeing memory
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

    DeleteCLLAtBeginning(&node1);

    return 0;
}