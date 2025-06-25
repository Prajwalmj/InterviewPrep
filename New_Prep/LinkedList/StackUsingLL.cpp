#include "List.h"
#include <iostream>

//Same as insertion at beginning of LL
void Push(struct Node** headNode, int value)
{
    struct Node* newNode = new Node();
    newNode->data = value;
    newNode->next = *headNode;
    *headNode = newNode;
}

//Same as deletion at beginning of LL
void Pop(struct Node** headNode)
{
    if(*headNode == NULL)
    {
        std::cout << "LL/Stack is empty. Nothing to delete" << std::endl;
        return;
    }

    struct Node* tempNode = *headNode;
    *headNode = (*headNode)->next;
    delete tempNode;
}

int main()
{
    Node *node1 = NULL;

    Push(&node1, 17);
    Push(&node1, 1);
    Push(&node1, 5);
    Push(&node1, 29);
    Push(&node1, 3);
    Push(&node1, 100);
    Push(&node1, 200);

    PrintSinglyLinkedList(node1);

    Pop(&node1);
    PrintSinglyLinkedList(node1);

    Pop(&node1);
    PrintSinglyLinkedList(node1);

    return 0;
}