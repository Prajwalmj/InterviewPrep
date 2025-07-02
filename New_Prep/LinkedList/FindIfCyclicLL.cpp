#include <iostream>
#include "List.h"

//Note:  Cyclic => not just ciruclar LL. Cycle/Loop can be anywhere
//Floyd Cyclic Finding Algo
bool FindIfCyclic(Node* headNode)
{
    Node* slowPtr = headNode, *fastPtr = headNode;
    bool isCylcic = false;

    while(slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = (fastPtr->next)->next;

        if(slowPtr == fastPtr)
        {
            isCylcic = true;
            break;
        }
    }

    return isCylcic;
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

    std::cout << "IsCyclic: " << FindIfCyclic(node1) << "\n";

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;

    return 0;
}