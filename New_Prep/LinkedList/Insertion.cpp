#include "List.h"
#include <iostream>

namespace
{
    constexpr int BEGINNNING_POSITION = 1;
}

void InsertIntoLinkedList(struct Node** headNode, int element, int position)
{
    struct Node* newNode = new Node();
    newNode->data = element;
    struct Node* p, *q;
    int k = 1;

    p = *headNode;
    //beginning case
    if(position == BEGINNNING_POSITION)
    {
        newNode->next = p;
        *headNode = newNode;
    }
    else
    {
        while((p != NULL) && (k < position))    //any case(includes at the end)
        {
            std::cout << "position : " << k << std::endl;
            k++;
            q = p;
            p = p->next;
        }
        newNode->next = p;
        q->next = newNode;

        std::cout << "Printing linked list after insertion: " << std::endl;
        struct Node *temp = *headNode;
        while(temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }    
}

int main()
{
    Node* node1 = new Node();
    node1->data = 1;

    Node node2;
    node2.data = 6;
    Node node3;
    node3.data = 19;
    Node node4;
    node4.data = 4;
    Node node5;
    node5.data = 7;

    node1->next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    InsertIntoLinkedList(&node1, 20, 4);
    // InsertIntoLinkedList(&node1, 20, 6); //Insert at the end.

    delete node1;

    return 0;
}