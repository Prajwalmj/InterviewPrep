#include <iostream>
#include "List.h"

Node* FindCycleBeginningIfCyclic(Node *headNode)
{
    bool isCyclic = false;
    Node* slowPtr = headNode, *fastPtr = headNode;

    while(slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
        {
            isCyclic = true;
            break;  
        }
    }

    if(isCyclic)
    {   
        slowPtr = headNode;

        while(slowPtr != fastPtr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }
    else
    {
        slowPtr = nullptr;
    }

    return slowPtr;
}

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();
    Node *node5 = new Node();
    Node *node6 = new Node();
    Node *node7 = new Node();
    Node *node8 = new Node();

    node1->data = 17;
    node1->next = node2;

    node2->data = 1;
    node2->next = node3;

    node3->data = 5;
    node3->next = node4;

    node4->data = 29;
    node4->next = node5;

    node5->data = 3;
    node5->next = node6;

    node6->data = 10;
    node6->next = node7;

    node7->data = 22;
    node7->next = node8;

    node8->data = 14;
    node8->next = nullptr;

    Node* loopBeginNode = FindCycleBeginningIfCyclic(node1);

    if(loopBeginNode)
    {
        std::cout << "Loop Begin Node data is: " << loopBeginNode->data << std::endl;
    }
    else
    {
        std::cout << "Cycle not found or list is empty" << std::endl;
    }

    return 0;
}