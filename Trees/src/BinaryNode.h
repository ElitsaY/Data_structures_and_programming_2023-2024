
struct BinaryNode{
    BinaryNode* left;
    BinaryNode* right;
    int val;

    BinaryNode(int _val, BinaryNode* _left = nullptr, BinaryNode* _right = nullptr) : 
                val(_val), left(_left), right(_right) {}
};