#include "List.h"
#include <iostream>

Node* ReverseListInPair(Node* head)
{
    if(!head)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }

    Node* current = head, *second = nullptr;

    while(current && current->next)
    {
        if(second)
        {
            second->next->next = current->next;
        }
        second = current->next;
        current->next = second->next;
        second->next = current;

        if(current == head)
        {
            head = second;
        }
        current = current->next;
    }

    return head;
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
    node5->next = nullptr;

    std::cout << "Before :::" << std::endl;
    PrintSinglyLinkedList(node1);
    Node* result = ReverseListInPair(node1);
    
    if(result)
    {
        std::cout << "After :::" << std::endl;
        PrintSinglyLinkedList(result);
    }
    else
    {
        std::cout << "List is null" << std::endl;
    }

    return 0;
}