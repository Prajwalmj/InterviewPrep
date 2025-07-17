#include "List.h"
#include <iostream>

Node* RearrangeIntoEvenOdd(Node* head)
{
    if(!head)
    {
        std::cout << "LL is empty" << std::endl;
        return nullptr;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;    
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    
    Node* current = head;

    while(current)
    {
        //Detach node early like this, so easier to link it to even or odd list
        Node* nxt = current->next;
        current->next = nullptr;

        if(current->data %2 == 0)
        {
            if(!evenHead)
            {
                evenHead = evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if(!oddHead)
            {
                oddHead = oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }

        current = nxt;
    }

    if(evenHead)
    {
        evenTail->next = oddHead;
        return evenHead;
    }
    else
    {
        return oddHead;
    }
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