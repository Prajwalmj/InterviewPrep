#include "List.h"
#include <iostream>

Node* MergeTwoListsOneByOne(Node* head1, Node *head2)
{
    bool bothAreEmpty = (!head1 && !head2);
    bool isOnlyOneEmpty = (!head1 || !head2);

    if(bothAreEmpty)
    {
        return nullptr;
    }
    else if(isOnlyOneEmpty)
    {
        return (!head1 ? head2 : head1);
    }

    Node* newNode = new Node();
    newNode->next = nullptr;

    Node* temp = newNode;

    while(head1 && head2)
    {
        //Copy from first list
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;

        //Copyy from second list
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    if(head1)
    {
        temp->next = head1;
    }
    else if(head2)
    {
        temp->next = head2;
    }

    temp = newNode->next;
    delete newNode;

    return temp;
}

int main()
{

    //Odd number of elements case
    Node* node11 = new Node();
    Node* node12 = new Node();
    Node* node13 = new Node();

    node11->data = 11;
    node11->next = node12;

    node12->data = 25;
    node12->next = node13;

    node13->data = 31;
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

    node23->data = 29;
    node23->next = node24;

    node24->data = 32;
    node24->next = nullptr;

    Node* result = MergeTwoListsOneByOne(node21, node11);

    if(result)
    {
        std::cout << "Resulting list is: " << std::endl;
        PrintSinglyLinkedList(result);
    }
    else
    {
        std::cout << "Result list is null" << std::endl;
    }

    return 0;
}