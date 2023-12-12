#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

struct BST {
    int val;
    BST* left;
    BST* right;

    BST(int val, BST* left = nullptr, BST* right = nullptr)
        : val(val), left(left), right() {}
};

BST*& find(BST* &root, int element) {
    if (root == nullptr || root->val == element) {
        return root;
    }

    if (element < root->val) {
        return find(root->left, element);
    }
    return find(root->right, element);
}

void insert(BST* &root, int element) {
    find(root, element) = new BST(element);
}

void erase(BST* &root, int element) {
    BST* &toErase = find(root, element);
    if (toErase == nullptr) {
        return;
    }

    if (toErase->left == nullptr) {
        BST* toDelete = toErase;
        toErase = toErase->right;
        delete toDelete;
    } else if (toErase->right == nullptr) {
        BST* toDelete = toErase;
        toErase = toErase->left;
        delete toDelete;
    } else { // 2 children
        BST* succParent = toErase;
        BST* succ = toErase->left;
        while (succ->right != nullptr) {
            succParent = succ;
            succ = succ->right;
        }

        if (succParent != toErase) {
            succParent->right = succ->left;
        } else {  // Here the toErase->left is the largest so we reatach it's children to us (toErase)
            toErase->left = succ->left;
        }
 
        toErase->val = succ->val;

        delete succ;
    }
}

// Get the size of a BST
std::size_t size(const BST* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + size(root->left) + size(root->right);
}

// Delete all nodes from the BST
void freeBST(BST* &root) {
    if (root == nullptr) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    delete root;
    root = nullptr;
}

// Printing sorted
void printInorder(BST* root) {
    if (root == nullptr) {
        return;
    }

    printInorder(root->left);
    std::cout << root->val << ' ';
    printInorder(root->right);
}

// Usefull for debugging
void printLevels(BST* root) {
    std::queue<BST*> q;
    q.push(root);
    int rem = 1;

    while (!q.empty()) {
        std::cout << q.front()->val << ' ';
        
        if (q.front()->left) {
            q.push(q.front()->left);
        }
        if (q.front()->right) {
            q.push(q.front()->right);
        }

        q.pop();
        --rem;

        if (rem == 0) {
            rem = q.size();
            std::cout << '\n';
        }
    }
}

// Basically inorder traversal to check if elements are in sorted order
bool isValidBST(const BST* root, int &last) {
    if (root == nullptr) {
        return true;
    }

    if (!isValidBST(root->left, last) || root->val < last) {
        return false;
    }

    last = root->val;

    return  isValidBST(root->right, last);
}

// Overload the operators to keep track of memory management
std::size_t allocations = 0, deallocations = 0;

void * operator new(std::size_t size) {
    ++allocations;
    void * p = malloc(size);
    return p;
}
 
void operator delete(void * p) {
    ++deallocations;
    free(p);
}

BST* testInitializer() {
    BST* root = nullptr;

    insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    return root;
}

bool test() {
    for (int bitset = 0; bitset < 128; ++bitset) {
        BST* root = testInitializer();
        int last = INT_MIN;

        // Erase selected bits
        std::size_t erasedCnt = 0;
        for (int bit = 0; bit < 7; ++bit) {
            if (bitset & (1<<bit)) {
                erase(root, bit + 1);
                ++erasedCnt;
            }
        }

        // Check if size is correct and if it is valid BST
        if (size(root) != 7 - erasedCnt || !isValidBST(root, last)) {
            freeBST(root);
            return false;
        }

        // Check if the remaining bits are the right ones
        for (int bit = 0; bit < 7; ++bit) {
            if ((bitset & (1<<bit)) == 0) {
                BST* found = find(root, bit + 1);
                if (found == nullptr || found->val != bit + 1) {
                    freeBST(root);
                    return false;
                }
            }
        }

        // Free memory
        freeBST(root);
    }

    // Check if we have memory leak
    return allocations == deallocations;
}

int main() {
    std::cout << (test() ? "Passed all tests\n" : "Tests failed\n");

    return 0;
}