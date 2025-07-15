#include "List.h"
#include <iostream>

Node* CreateCircularList(int size)
{
    Node* temp = new Node();
    temp->data = 1;
    Node* head = temp;

    for(int i = 2; i <= size; i++)
    {
        temp->next = new Node();
        temp = temp->next;
        temp->data = i;
    }

    temp->next = head; //Make it circular LL
    return head;
}

Node* FindJosephusCircleSolution(int size, int eliminateCount, Node* head)
{
    Node *q, *p = head;
    while(head->next != head)
    {
        int tempCount = eliminateCount;
        while(--tempCount)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;

        if(head == p)
        {
            head = p->next;
        }
        std::cout << "Eliminating : " << p->data << std::endl;
        delete p;
        p = q->next;
    }

    return head;
}

int main()
{
    Node* headNode = CreateCircularList(5);
    PrintCircularSinglyLinkedList(headNode);

    Node* solution = FindJosephusCircleSolution(5, 2, headNode);
    std::cout << "Answer is: " << solution->data << std::endl;
    return 0;
}