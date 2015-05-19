#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <queue>

namespace bst {

struct Node {
    Node(int value = 0) : value(value), left(0), right(0) {}
    int value;
    Node* left;
    Node* right;
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
    else if (treeNode->value > value)
        treeNode->left = InsertNode(treeNode->left, value);
    else
        treeNode->right = InsertNode(treeNode->right, value);
    return treeNode;
}

void BST::PrintTree(Node* node) {
    if (node) {
        std::cout << "Node value: " << node->value << std::endl;
        std::cout << "Going left ";
        PrintTree(node->left);
        std::cout << "Going Right ";
        PrintTree(node->right);
    }
}

static int CountNodesInRange(const int& begin, const int& end, Node* node) {
    if (!node) return 0;
    if (node->value < begin) return CountNodesInRange(begin, end, node->right);
    if (node->value > end) return CountNodesInRange(begin, end, node->left);
    if (node->value >= begin && node->value) {
        return CountNodesInRange(begin, end, node->right) +
            CountNodesInRange(begin, end, node->left) +
            1;
    }
}

void AssignQueue(std::queue<Node*>& dest, std::queue<Node*>& src) {
    while (!src.empty()) {
        Node* node = src.front();
        dest.push(node);
        src.pop();
    }
}

void PrintTreeByLevel(Node* root) {
    if (!root) return;
    std::queue<Node*> current_level, next_level;
    current_level.push(root);
    Node* current_node;
    while (!current_level.empty()) {
        current_node = current_level.front();
        current_level.pop();
        std::cout << current_node->value << " ";

        if (current_node->left) next_level.push(current_node->left);
        if (current_node->right) next_level.push(current_node->right);

        if (current_level.empty()) {
            std::cout << std::endl;
            AssignQueue(current_level, next_level);
        }
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

    PrintTreeByLevel(tree->GetRoot());

    return 1;
}

}

#endif // BST_H_ */
