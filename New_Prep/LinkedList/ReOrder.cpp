#include <iostream>
#include "List.h"

//Could have been done better by splitting into functions?
Node* ReOrder(Node* head)
{
    //Find middle element.
    if(!head)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    else if(!(head->next) || !(head->next->next))
    {
        std::cout << "List has only one or two elements" << std::endl;
        return head;
    }

    Node* fastptr = head, *slowptr = head;
    while(fastptr && fastptr->next && fastptr->next->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    //Reverse second half
    Node *head2 = slowptr->next;
    Node* prev = nullptr, *current = head2, *second = nullptr;
    slowptr->next = nullptr; //break 1st list from second list

    while(current)
    {
        second = current->next;
        current->next = prev;
        prev = current;
        current = second;
    }
    head2 = prev; //Change second list head after reversing.

    Node *newNode = new Node();
    newNode->next = nullptr;
    Node *temp = newNode;
    while(head && head2)
    {
        temp->next = head;
        temp = temp->next;
        head = head->next;

        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    if(head)
    {
        temp->next = head;
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
    Node* node1 = new Node();
    node1->data = 1;

    Node* node2 = new Node();
    node2->data = 2;
    Node* node3 = new Node();
    node3->data = 3;
    Node* node4 = new Node();
    node4->data = 4;
    // Node* node5 = new Node();
    // node5->data = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    // node5->next = nullptr;

    Node* result = ReOrder(node1);

    if(result)
    {
        std::cout << "List after reordering is: " << std::endl;
        PrintSinglyLinkedList(result);
    }
    else
    {
        std::cout << "Resulting list is null" << std::endl;
    }

    return 0;
}