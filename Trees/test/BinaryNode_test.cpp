#include "catch2/catch_all.hpp"
#include "BinaryTree.h"

//LOWEST COMMON ANCESTOR
/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("lowest common ancestor(nullptr), returns nullptr", "[solution]"){
    CHECK(lowestCommonAncestor(nullptr, nullptr, nullptr) == nullptr);
}

TEST_CASE("lowest common ancestor(SampleBinaryTree, 3, 5), returns 4", "[solution]"){
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;
    BinaryNode* p = n6;
    BinaryNode* q = n7;

    CHECK(lowestCommonAncestor(root, p, q) == n5);

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}


/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("lowest common ancestor(SampleBinaryTree, 4, 5), returns 4", "[solution]"){
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;
    BinaryNode* p = n5;
    BinaryNode* q = n7;

    CHECK(lowestCommonAncestor(root, p, q) == n5);

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}

/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("lowest common ancestor(SampleBinaryTree, 0, 9), returns 6", "[solution]"){
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;
    BinaryNode* p = n4;
    BinaryNode* q = n9;

    CHECK(lowestCommonAncestor(root, p, q) == n1);

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}

/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("lowest common ancestor(SampleBinaryTree, 0, 4), returns 2", "[solution]"){
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;
    BinaryNode* p = n4;
    BinaryNode* q = n5;

    CHECK(lowestCommonAncestor(root, p, q) == n2);

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}

/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("lowest common ancestor(SampleBinaryTree, 0, 5), returns 2", "[solution]"){
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;
    BinaryNode* p = n4;
    BinaryNode* q = n7;

    CHECK(lowestCommonAncestor(root, p, q) == n2);

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}

// RIGHT SIDE VIEW

/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("rightSideView(SampleBinaryTree), returns 6 8 9 5", "[solution]") {
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;

    std::vector<int> actual = rightSideView(root);
    std::vector<int> expected = std::vector<int>{6,8,9,5};
    REQUIRE(actual.size() == expected.size());
    for (int i = 0; i < expected.size(); ++i) {
        CHECK(actual[i] == expected[i]);
    }

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}

// FLATTEN

/*
         6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

TEST_CASE("flatten(SampleBinaryTree), returns 6 8 9 5", "[solution]") {
    //Sample Binary Search Tree
    BinaryNode* n9 = new BinaryNode(9);
    BinaryNode* n8 = new BinaryNode(7);
    BinaryNode* n7 = new BinaryNode(5);
    BinaryNode* n6 = new BinaryNode(3);
    BinaryNode* n5 = new BinaryNode(4, n6, n7);
    BinaryNode* n4 = new BinaryNode(0);
    BinaryNode* n3 = new BinaryNode(8, n8, n9);
    BinaryNode* n2 = new BinaryNode(2, n4, n5);
    BinaryNode* n1 = new BinaryNode(6, n2, n3);

    BinaryNode* root = n1;

    std::vector<int> expected = std::vector<int>{0,2,3,4,5,6,7,8,9};
    flatten(root);

    for (int i = 0; i < expected.size(); ++i) {
        REQUIRE(root != nullptr);
        CHECK(root->val == expected[i]);
    }

    delete n4;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n5;
    delete n3;
    delete n2;
    delete n1;
}