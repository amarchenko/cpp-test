#ifndef BST_H_
#define BST_H_

#include <iostream>

namespace bst {

struct Node {
    Node(int value = 0) : value_(value), left_(0), right_(0) {}
    int value_;
    Node* left_;
    Node* right_;
};

class BST {
public:
    BST(int value = 0) {
        root_ = new Node(value);
    }
    ~BST();

    Node* GetRoot();
    void AddValue(int value);
    void PrintTree(Node* node);

private:
    Node* InsertNode(Node* treeNode, int value);
    Node* root_;
};

Node* BST::GetRoot() {
    return root_;
}

void BST::AddValue(int value) {
    InsertNode(root_, value);
}

Node* BST::InsertNode(Node* treeNode, int value) {
    if (!treeNode)
        return new Node(value);
    else if (treeNode->value_ > value)
        treeNode->left_ = InsertNode(treeNode->left_, value);
    else
        treeNode->right_ = InsertNode(treeNode->right_, value);
    return treeNode;
}

void BST::PrintTree(Node* node) {
    if (node) {
        std::cout << "Node value: " << node->value_ << std::endl;
        std::cout << "Going left ";
        PrintTree(node->left_);
        std::cout << "Going Right ";
        PrintTree(node->right_);
    }
}

static int CountNodesInRange(const int& begin, const int& end, Node* node) {
    if (!node) return 0;
    if (node->value_ < begin) return CountNodesInRange(begin, end, node->right_);
    if (node->value_ > end) return CountNodesInRange(begin, end, node->left_);
    if (node->value_ >= begin && node->value_) {
        return CountNodesInRange(begin, end, node->right_) +
            CountNodesInRange(begin, end, node->left_) +
            1;
    }
}

int test() {
    BST* tree = new BST(7);
    tree->AddValue(3);
    tree->AddValue(8);
    tree->AddValue(15);
    tree->AddValue(20);

    //tree->PrintTree(tree->GetRoot());
    
    std::cout << "Nodes in range [7;15] -> " <<
        CountNodesInRange(7, 15, tree->GetRoot()) <<
        std::endl;

    return 1;
}

}

#endif // BST_H_ */