#include "List.h"
#include <iostream>

void DeleteCLLAtEnd(struct Node** headNode)
{
    if(*headNode == NULL)
    {
        std::cout << "CLL is empty. Nothing to delete." << std::endl;
        return;
    }

    struct Node* p, *q;
    p = *headNode;
    do
    {
        q = p;
        p = p->next;
    }while(p->next != *headNode);

    q->next = *headNode;
    delete p;

    std::cout << "CLL after deletion at end is: " << std::endl;
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

    Node* node2 = new Node();
    node2->data = 6;
    Node* node3 = new Node();
    node3->data = 19;
    Node* node4 = new Node();
    node4->data = 4;
    Node* node5 = new Node();
    node5->data = 7;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node1;

    DeleteCLLAtEnd(&node1);
    return 0;
}
