List.h -> Singly Linked List
DLL.h  -> Doubly Linked LIst

# Singly Linked List**

ADT
1. Traversal
2. Insertion
3. Deletion

## Insertion
- double pointer to a function (same as pass by reference)
- beginning => one pointer enough.
- middle/end => use two pointers.

## Deletion
- double pointer to a funciton
- beginning => one pointer enough.
- middle/end => use two pointers

# Doubly Linked List

## Insertion
- need single temp pointer as nodes can be accessed in both direcitons.

## Deletion
- need two temp pointers, for middle or last element deletion.

# Circular Linked List

- Focus on operations at beginning and end for insertion, deletion. Because rest cases are similar to SLL.
- Use do while for easier implementation


## Deletion
- At end requires 2 pointers

# Problems

## StackUsingLL
- PUSH => Insertion at beginning of list
- POP => Deletion from beginning of list

## For queue, similary
Enqueue => Insertion at end of list
Dequeue => Deletion from beginning of list

## PrintLLFromEnd 
- Use Recursion

## EvenOrOddLength
- Check whether given singly LL length is even or odd
- Use fastptr(2x) slowptr logic, similar to finding middle of LL

## SplitCircularLLIntoTwo
- Given a circular LL, split it into two equal pars. If no of nodes in list are odd, make first list one node extra than second list.