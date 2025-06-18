#include "List.h"
#include <iostream>

namespace
{
    constexpr int BEGINNNING_POSITION = 1;
}

void DeleteElementLinkedList(struct Node** headNode, int position)
{
    if(*headNode == NULL)
    {
        std::cout << "LL is empty." << std::endl;
        return;
    }

    struct Node *p, *q;
    int k = 1; 

    p = *headNode;
    if(position == BEGINNNING_POSITION)
    {
        *headNode = (*headNode)->next;
        delete p;
    }
    else
    {
        while((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }

    std::cout << "Linked List after deletion " << std::endl;
    struct Node *temp = *headNode; 
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();
    Node *node5 = new Node();

    node1->data = 17;
    node1->next = node2;

    node2->data = 1;
    node2->next = node3;

    node3->data = 5;
    node3->next = node4;

    node4->data = 29;
    node4->next = node5;

    node5->data = 3;
    node5->next = NULL;

    // DeleteElementLinkedList(&node1, 1); //deletion in beginning
    // DeleteElementLinkedList(&node1, 4); //deletion in middle
    DeleteElementLinkedList(&node1, 5); //deletion at end

    return 0;
}