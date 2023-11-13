# Topic 6
## Singly Linked lists

```c++
struct LinkedListNode{
    int value;
    LinkedListNode* next;
};
```

## Task 0

Write apropriate constructors for the ***LinkedListNode*** class.

## Task 1

Write a function that returns the size of a linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
```c++
std::size_t size(LinkedListNode*);
```

## Task 2

Write a function that inserts an element at the end of a linked list. The function takes linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** as arguments.
```c++
void push_back(LinkedListNode*&, int);
```

## Task 3

Write a function that inserts an element at the beginning of a linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** as an argument.
```c++
void push_front(LinkedListNode*&, int);
```

## Task 4

Write a function that inserts an element after a given node. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, a linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** as arguments.
```c++
void insertAfter(LinkedListNode*, LinkedListNode*, int);
```

## Task 5

Write a function that inserts an element before a given node. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, a linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** as arguments.
```c++
void insertBefore(LinkedListNode*&, LinkedListNode*, int);
```

## Task 6

Write a function that removes the first element in a linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
```c++
void pop_front(LinkedListNode*&);
```

## Task 7

Write a function that removes the last element in a linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
```c++
void pop_back(LinkedListNode*&);
```

## Task 8

Write a function that removes a given node from a linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and a linked list node ***LinkedListNode\**** pointing to a node in the linked list as arguments.
```c++
void deleteAt(LinkedListNode*, LinkedListNode*);
```

## Task 9

Write a function to clear an entire linked list. The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
```c++
void clear(LinkedListNode*&);
```