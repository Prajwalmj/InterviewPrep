#include "List.h"
#include <iostream>

void ReverseSinglyLinkedList(struct Node** headNode)
{
    if(*headNode == NULL)
    {
        std::cout << "Given linked list is empty. Aboring reverse operation ..." << std::endl;
        return;
    }

    struct Node* current = *headNode, *next, *prev = NULL;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headNode = prev;

    std::cout << "Linked List after reversal is: " << std::endl;

    struct Node* temp = *headNode;
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
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
    node5->next = NULL;

    ReverseSinglyLinkedList(&node1);

    return 0;
}