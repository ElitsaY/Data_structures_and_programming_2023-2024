# Topic 6
## Singly Linked lists

```c++
struct LinkedListNode{
    int value;
    LinkedListNode* next;
}
```

## Task 0

Write apropriate constructors for the ***LinkedListNode*** class.

## Task 1

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list that returns it's size.
```c++
std::size_t size(LinkedListNode*);
```

## Task 2

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** that puts the element at the end of the linked list.
```c++
void push_back(LinkedListNode*, int);
```

## Task 3

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** that puts the element at the beginning of the linked list.
```c++
void push_front(LinkedListNode*, int);
```

## Task 4

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** that inserts the element after the given node.
```c++
void insertAfter(LinkedListNode*, LinkedListNode*, int);
```

## Task 5

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** that inserts the element before the given node.
```c++
void insertBefore(LinkedListNode*, LinkedListNode*, int);
```

## Task 6

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list that removes the first element in the linked list.
```c++
void pop_front(LinkedListNode*);
```

## Task 7

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list that removes the last element in the linked list.
```c++
void pop_back(LinkedListNode*);
```

## Task 8

Write a function taking linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and linked list node ***LinkedListNode\**** pointing to a node in the linked list that removes the given node from the linked list.
```c++
void insertBefore(LinkedListNode*, LinkedListNode*, int);
```