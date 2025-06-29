#include <iostream>
#include "List.h"


//Naive/Brute Force approach - Solution 1
// struct Node* FindNthNodeFromEnd(struct Node* head, int n)
// {
//     struct Node* temp = head;
//     int length = 0;
//     while(temp != NULL)
//     {
//         length++;
//         temp = temp->next;
//     }

//     struct Node* nthNode = nullptr;
//     if(n > length)
//     {
//         std::cout << "N is greater than length of the list" << std::endl;
//     }
//     else
//     {
//         int nodePosition = length - n + 1;
//         int count = 0;
//         while(count < nodePosition)
//         {
//             if(nthNode == NULL)
//             {
//                 nthNode = head;
//             }
//             else
//             {
//                 nthNode = nthNode->next;
//             }
//             count++;
//         }

//     }
//     return nthNode;
// }

//Better/efficient solution - Solution 2
struct Node* FindNthNodeFromEnd(struct Node* head, int n)
{

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

    struct Node* nthNode = FindNthNodeFromEnd(node1, 4);
    std::cout << "Data of last 4th node is: " << nthNode->data << std::endl;
    return 0;
}