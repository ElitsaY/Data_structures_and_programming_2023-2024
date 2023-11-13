#include <iostream>

// ```c++
// struct LinkedListNode{
//     int value;
//     LinkedListNode* next;
// };
// ```

// ## Task 0

// Write apropriate constructors for the ***LinkedListNode*** class.

struct LinkedListNode{
    int value;
    LinkedListNode* next;

    LinkedListNode(int value = 0, LinkedListNode* next = nullptr)
        : value(value), next(next) {}
};

// ## Task 1

// Write a function that returns the size of a linked list. The function takes a linked list 
// node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
// ```c++
// std::size_t size(LinkedListNode*);
// ```

std::size_t size(LinkedListNode* head) {
    std::size_t sz = 0;

    while (head != nullptr) {
        ++sz;
        head = head->next;
    }

    return sz;
}

std::size_t sizeRecursive(LinkedListNode* head) {
    if (head == nullptr) {
        return 0;
    }

    return sizeRecursive(head->next) + 1;
}

// ## Task 2

// Write a function that inserts an element at the end of a linked list. 
// The function takes linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** as arguments.
// ```c++
// void push_back(LinkedListNode*&, int);
// ```

void push_back(LinkedListNode* &head, int element) {
    if (head == nullptr) {
        head = new LinkedListNode(element);

        return;
    }

    LinkedListNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = new LinkedListNode(element);
}

// ## Task 3

// Write a function that inserts an element at the beginning of a linked list. 
// The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list and an element ***int*** as an argument.
// ```c++
// void push_front(LinkedListNode*&, int);
// ```

void push_front(LinkedListNode* &head, int element) {
    head = new LinkedListNode(element, head);
}

// ## Task 4

// Write a function that inserts an element after a given node. 
// The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, a linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** as arguments.
// ```c++
// void insertAfter(LinkedListNode*, LinkedListNode*, int);
// ```

void insertAfter(LinkedListNode* node, int element) { // O(1)
    if (node == nullptr) {
        throw "Node is nullptr";
    }
    // Oneline
    // node->next = new LinkedListNode(element, node->next);
    LinkedListNode* newNode = new LinkedListNode(element, node->next);
    node->next = newNode;
}

// ## Task 5

// Write a function that inserts an element before a given node.
// The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list, a linked list node ***LinkedListNode\**** pointing to a node in the linked list and an element ***int*** as arguments.
// ```c++
// void insertBefore(LinkedListNode*&, LinkedListNode*, int);
// ```

void insertBefore(LinkedListNode* &head, LinkedListNode* node, int element) {
    if (head == nullptr || node == nullptr) {
        throw "Head is nullptr";
    }

    if (head == node) {
        push_front(head, element);
    }

    LinkedListNode* cur = head;
    while (cur->next != node) {
        cur = cur->next;
    }

    insertAfter(cur, element);
}

// ## Task 6

// Write a function that removes the first element in a linked list. 
// The function takes a linked list node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
// ```c++
// void pop_front(LinkedListNode*&);
// ```

void pop_front(LinkedListNode* &head) {
    if (head == nullptr) {
        throw "Head is nullptr";
    }

    LinkedListNode* toDel = head;
    head = head->next;
    delete toDel;
}

// ## Task 7

// Write a function that removes the last element in a linked list. 
// The function takes a linked list node ***LinkedListNode\**** pointing to the beginning 
// of a linked list as an argument.
// ```c++
// void pop_back(LinkedListNode*&);
// ```

void pop_back(LinkedListNode* &head) {
    if (head == nullptr) {
        throw "Head is nullptr";
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    LinkedListNode* prev = nullptr;
    LinkedListNode* cur = head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }

    delete cur;
    prev->next = nullptr;
}

// ## Task 8

// Write a function that removes a given node from a linked list. 
// The function takes a linked list node ***LinkedListNode\**** pointing to the 
// beginning of a linked list and a linked list node ***LinkedListNode\**** pointing to a node in the linked list as arguments.
// ```c++
// void deleteBefore(LinkedListNode*&, LinkedListNode*);
// ```

void deleteAt(LinkedListNode* &head, LinkedListNode* node) {
    if (head == nullptr || node == nullptr) {
        throw "Head is nullptr";
    }

    if (head == node) {
        pop_front(head);
    }

    LinkedListNode* cur = head;
    while (cur != nullptr && cur->next != node) {
        cur = cur->next;
    }

    if (cur == nullptr) {
        throw "Node is not in the linked list";
    }

    cur->next = node->next;
    delete node;
}

// ## Task 9

// Write a function to clear an entire linked list. The function takes a linked list
// node ***LinkedListNode\**** pointing to the beginning of a linked list as an argument.
// ```c++
// void clear(LinkedListNode*&);
// ```

void clear(LinkedListNode* &head) {
    LinkedListNode* cur = head;
    while (cur != nullptr) {
        LinkedListNode* toDel = cur;
        cur = cur->next;
        delete toDel;
    }

    head = nullptr;
}

int main() {
    

    return 0;
}