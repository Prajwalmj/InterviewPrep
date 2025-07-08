#include "List.h"
#include <iostream>

Node* FindMiddleOfLL(Node *head)
{
    Node* slowptr = head, *fastptr = head;
    if(head == nullptr)
    {
        std::cout << "LL is empty" << std::endl;
        return nullptr;
    }
    
    while(fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    return slowptr;
}

int main()
{
    //Odd number of elements case
    Node* node11 = new Node();
    Node* node12 = new Node();
    Node* node13 = new Node();

    node11->data = 1;
    node11->next = node12;

    node12->data = 2;
    node12->next = node13;

    node13->data = 3;
    node13->next = nullptr;

    //Even number of elements case
    Node* node21 = new Node();
    Node* node22 = new Node();
    Node* node23 = new Node();
    Node* node24 = new Node();

    node21->data = 21;
    node21->next = node22;

    node22->data = 27;
    node22->next = node23;

    node23->data = 2;
    node23->next = node24;

    node24->data = 19;
    node24->next = nullptr;

    //single element case
    Node *node31 = new Node();
    node31->data = 100;
    node31->next = nullptr;

    Node* result1 = FindMiddleOfLL(node11);
    Node* result2 = FindMiddleOfLL(node21);
    Node* result3 = FindMiddleOfLL(node31);

    if(result1)
    {
        std::cout << "Middle node of first list is: " << result1->data << std::endl;
    }

    if(result2)
    {
        std::cout << "Middle node of first list is: " << result2->data << std::endl;
    }

    if(result3)
    {
        std::cout << "Middle node of first list is: " << result3->data << std::endl;
    }

    return 0;
}