#include "BinaryTree.h"

//Получавате двоично наредено дърво (BST) и два върха от дървото, върнете техният Lowest Common Ancestor (първият им общо родител)
//Примери:
/*
        6
      /    \
     2       8
    / \     / \
   0   4   7   9
      / \
     3   5
*/

//Lowest Common Ancestor - LCA
//LCA(3, 5) = 4
//LCA(4, 7) = 6
//LCA(0, 3 ) = 2
BinaryNode* lowestCommonAncestor(BinaryNode* root, BinaryNode* node1, BinaryNode* node2){
    throw "Unimplemented";
}


//Дадено ви е двоично дърво, представете си, че стоите от дясната му страна,
//върнете стойностите на върховете, които виждате, подредени от върха към дъното
//Пример:
/*
       7 <--
    /     \ 
   3       5 <--
  / \     / \
 1   2   4   3 <--
        / \
       2   1 <--
*/
//Резултатът от функцията rightSideView - трябва да е {7, 5, 3, 1} 
std::vector<int> rightSideView(BinaryNode* root){
	throw "Unimplemented";
}

void flatten(BinaryNode* &root){
    throw "Unimplemented";
}


