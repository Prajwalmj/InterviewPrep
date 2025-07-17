#include "List.h"
#include <iostream>

Node* RearrangeIntoEvenOdd(Node* head)
{
    Node* temp = new Node();
    temp->next = nullptr;
    Node* head2 = temp;
    Node *p, *q = nullptr;
    p = head;

    while(p != nullptr)
    {
        std::cout << "#######################" << std::endl;
        std::cout << p->data << std::endl;
        std::cout << "#######################" << std::endl;
        if(p->data % 2 == 0)
        {
            std::cout << "Even case: " << p->data << std::endl;
            q = p;
            p = p->next;
            PrintSinglyLinkedList(head);
        }
        else
        {
            std::cout << "odd case: " << p->data << std::endl;
            if(q)
            {
                q->next = p->next;
            }
            else
            {
                q = p;
            }
            head2->next = p;
            head2 = head2->next;
            p = q->next;
            if(p)
            {
                PrintSinglyLinkedList(head);
            }
        }
    }

    std::cout << "Printing inside function" << std::endl;
    PrintSinglyLinkedList(head);
    std::cout << "Printing inside function" << std::endl;

    head2 = temp;
    head2 = head2->next;
    delete temp;
    q->next = head2;

    std::cout << "Printing second head inside function" << std::endl;
    PrintSinglyLinkedList(head2);
    std::cout << "Printing second head inside function" << std::endl;
    return head;
}

int main()
{
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();
    
    node1->data = 2;
    node2->data = 6;
    node3->data = 19;
    node4->data = 4;
    node5->data = 7;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    Node* newHead = RearrangeIntoEvenOdd(node1);

    PrintSinglyLinkedList(newHead);
    return 0;
}