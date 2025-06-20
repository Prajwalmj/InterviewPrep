#include "DLL.h"
#include <iostream>

void DeleteElementFromDLL(struct DLLNode **head, int position)
{
    struct DLLNode* p, *q;
    int k = 1;

    if(*head == NULL)
    {
        std::cout << "DLL is empty" << std::endl;
    }

    p = *head;
    if(position == 1)
    {
        *head = (*head)->next;
        if(*head) //could be single element list => after deletion, no element left.
        {
            (*head)->prev = NULL;
        }
        delete p;
    }
    else
    {
        while((p->next != NULL) && (k<position))
        {
            k++;
            p = p->next;
        }

        q = p->prev;
        q->next = p->next;

        if(q->next)
        {
            q->next->prev = q;
        }

        delete p;
    }

    std::cout << "DLL after deletion is: " << std::endl;

    struct DLLNode* temp = *head;
    while(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp  = temp->next;
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

    // DeleteElementFromDLL(&node1, 1); //Delete first element
    // DeleteElementFromDLL(&node1, 2);
    DeleteElementFromDLL(&node1, 4);
    // DeleteElementFromDLL(&node1, 5); //Delete last element

    return 0;
}

