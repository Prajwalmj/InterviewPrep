#include "DLL.h"
#include <iostream>

namespace
{
    constexpr int BEGINNNING_POSITION = 1;
}

void InsertIntoDLL(struct DLLNode** headNode, int data, int position)
{
    struct DLLNode *newNode = new DLLNode();
    newNode->data = data;
    if(position == BEGINNNING_POSITION)
    {
        if(*headNode)
        {
            newNode->next = *headNode;
            newNode->prev = NULL;
            (*headNode)->prev = newNode;
            *headNode = newNode;
        }
        else
        {
            std::cout << "LinkedList is empty" << std::endl;
        }
    }
    else
    {
        struct DLLNode *tempNode = *headNode;
        int k = 1;
        while((tempNode->next != NULL) && (k < (position - 1)))
        {
            k++;
            tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        newNode->prev = tempNode;
        if(!(tempNode->next == NULL)) //if inserting at last position => can't access next node
        {
            tempNode->next->prev = newNode;
        }
        tempNode->next = newNode;
    }

    std::cout << "Printing doubly linked list after insertion: " << std::endl;
    struct DLLNode *temp = *headNode;
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    
}

int main()
{
    DLLNode* node1 = new DLLNode();
    DLLNode* node2 = new DLLNode();
    DLLNode* node3 = new DLLNode();
    DLLNode* node4 = new DLLNode();
    DLLNode* node5 = new DLLNode();

    node1->data = 10;
    node1->prev = NULL;
    node1->next = node2;

    node2->data = 15;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 7;
    node3->prev = node2;
    node3->next = node4;

    node4->data = 1;
    node4->prev = node3;
    node4->next = node5;

    node5->data = 9;
    node5->prev = node4;
    node5->next = NULL;

    // InsertIntoDLL(&node1, 5, 1);
    // InsertIntoDLL(&node1, 5, 2);
    InsertIntoDLL(&node1, 5, 3);
    // InsertIntoDLL(&node1, 5, 6);
}