#include "List.h"
#include <iostream>

void SplitCircularLLIntoTwo(Node *head, Node **head1, Node **head2)
{
    //Find middle of list
    Node *slowptr = head, *fastpr = head;
    while(fastpr->next != head && fastpr->next->next != head)
    {
        slowptr = slowptr->next;
        fastpr = fastpr->next->next;
    }

    //even nodes case, move to last node
    if(fastpr->next->next == head)
    {
        fastpr = fastpr->next;
    }

    //Check for single node case
    if(head->next != head)
    {
        *head1 = head;
        *head2 = slowptr->next;
        fastpr->next = slowptr->next; //second circular list
        slowptr->next = head; //first circular list
    }
    else
    {
        *head1 = head;
        *head2 = head;
    }
}


int main()
{
    //Even number of elements in circular LL
    Node* node11 = new Node();
    Node* node12 = new Node();
    Node* node13 = new Node();
    Node* node14 = new Node();

    node11->data = 1;
    node11->next = node12;
    node12->data = 2;
    node12->next = node13;
    node13->data = 3;
    node13->next = node14;
    node14->data = 4;
    node14->next = node11;

    Node* node21 = new Node();
    Node* node22 = new Node();
    Node* node23 = new Node();
    Node* node24 = new Node();
    Node* node25 = new Node();

    //Odd number of elements in circular LL
    node21->data = 11;
    node21->next = node22;
    node22->data = 21;
    node22->next = node23;
    node23->data = 31;
    node23->next = node24;
    node24->data = 41;
    node24->next = node25;
    node25->data = 51;
    node25->next = node21;

    Node* head11 = nullptr, *head12 = nullptr;
    Node* head21 = nullptr, *head22 = nullptr;

    SplitCircularLLIntoTwo(node11, &head11, &head12);
    std::cout << "Even elements case: " << std::endl;
    std::cout << "First list is: " << std::endl;
    PrintCircularSinglyLinkedList(head11);
    std::cout << "Second list is: " << std::endl;
    PrintCircularSinglyLinkedList(head12);
    SplitCircularLLIntoTwo(node21, &head21, &head22);
    std::cout << "Even elements case: " << std::endl;
    std::cout << "First list is: " << std::endl;
    PrintCircularSinglyLinkedList(head21);
    std::cout << "Second list is: " << std::endl;
    PrintCircularSinglyLinkedList(head22);

    return 0;
}