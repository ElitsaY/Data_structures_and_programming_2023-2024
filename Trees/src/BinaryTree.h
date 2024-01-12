#pragma once

#include <vector>

struct BinaryNode{
    BinaryNode* left;
    BinaryNode* right;
    int val;

    BinaryNode(int _val, BinaryNode* _left = nullptr, BinaryNode* _right = nullptr) : 
                val(_val), left(_left), right(_right) {}
};

BinaryNode* lowestCommonAncestor(BinaryNode* root, BinaryNode* node1, BinaryNode* node2);
std::vector<int> rightSideView(BinaryNode* root);
void flatten(BinaryNode* &root);
