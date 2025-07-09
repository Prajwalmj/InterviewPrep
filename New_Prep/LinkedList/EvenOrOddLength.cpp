#include "List.h"

void EvenOrOddLength(Node* head)
{
    Node* slowptr = head, *fastptr = head;

    while(fastptr && fastptr->next)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    if(!fastptr)
    {
        std::cout << "List length is even" << std::endl;
    }
    else
    {
        std::cout << "List length is odd" << std::endl;
    }
}

int main()
{
    //Odd number of elements case
    Node* node11 = new Node();
    Node* node12 = new Node();
    Node* node13 = new Node();

    node11->data = 1;
    node11->next = node12;

    node12->data = 2;
    node12->next = node13;

    node13->data = 3;
    node13->next = nullptr;

    //Even number of elements case
    Node* node21 = new Node();
    Node* node22 = new Node();
    Node* node23 = new Node();
    Node* node24 = new Node();

    node21->data = 21;
    node21->next = node22;

    node22->data = 27;
    node22->next = node23;

    node23->data = 2;
    node23->next = node24;

    node24->data = 19;
    node24->next = nullptr;

    std::cout << "First list: " << std::endl;
    EvenOrOddLength(node11);
    std::cout << "Second list: " << std::endl;
    EvenOrOddLength(node21);

    return 0;
}