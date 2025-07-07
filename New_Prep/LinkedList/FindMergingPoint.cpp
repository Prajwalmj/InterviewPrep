#include "List.h"
#include <iostream>
#include <numeric>

Node* FindMergingPointTwoLL(Node* head1, Node* head2)
{
    Node* temp1 = head1, *temp2 = head2;
    int length1 = 0, length2 = 0;

    //Find lenght of LL1
    while(temp1 != nullptr)
    {
        temp1 = temp1->next;
        length1++;
    }

    //Find lenght of LL2
    while(temp2 != nullptr)
    {
        temp2 = temp2->next;
        length2++;
    }

    int difference = std::abs(length1 - length2);
    temp1 = head1;
    temp2 = head2;

    //Move longer list temp point by difference to have same starting point
    if(length1 > length2)
    {
        while(temp1 && difference)
        {
            difference--;
            temp1 = temp1->next;
        }
    }
    else if(length2 > length1)
    {
        while(temp2 && difference)
        {
            difference--;
            temp2 = temp2->next;
        }
    }

    bool mergeFound = false;
    while(temp1 && temp2)
    {
        if(temp1 == temp2)
        {
            mergeFound = true;
            break;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(!mergeFound)
    {
        temp1 = nullptr;
    }

    return temp1;
    
}

int main()
{
    //First LL
    Node* node11 = new Node();
    Node* node12 = new Node();
    Node* node13 = new Node();
    Node* node14 = new Node();

    node11->data = 9;
    node11->next = node12;

    node12->data = 5;
    node12->next = node13;

    node13->data = 7;
    node13->next = node14;

    node14->data = 7;
    node14->next = nullptr;

    //Second LL
    Node* node21 = new Node();
    Node* node22 = new Node();
    Node* node23 = new Node();

    node21->data = 2;
    node21->next = node22;

    node22->data = 10;
    node22->next = node23;

    node23->data = 6;
    node23->next = node13;

    Node* result = FindMergingPointTwoLL(node11, node21);
    if(result)
    {
        std::cout << "Merging point node value is: " << result->data << std::endl;
    }
    else
    {
        std::cout << "There is no merging point between two lists. " << std::endl;
    }
    return 0;
}