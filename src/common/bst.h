#include <iostream>

namespace bst {

struct Node
{
    Node(int value = 0) : m_value(value), m_left(0), m_right(0) {}
    int m_value;
    Node* m_left;
    Node* m_right;
};

class BST
{
public:
    BST(int value = 0)
    {
        m_root = new Node(value);
    }
    ~BST();

    void addValue(int value);
    void printTree();

private:
    void insertNode(Node* treeNode, Node* newNode);
    Node* m_root;
};

void BST::addValue(int value)
{
    Node* newNode = new Node(value);
    insertNode(m_root, newNode);
}

void BST::insertNode(Node* treeNode, Node* newNode)
{
    if (treeNode == 0)
        treeNode = newNode;
    else if (treeNode->m_value > newNode->m_value)
        insertNode(treeNode->m_left, newNode);
    else
        insertNode(treeNode->m_right, newNode);
}

void BST::printTree()
{
    std::cout << "Root: " << m_root->m_value << std::endl;
    std::cout << "Left: " << m_root->m_left->m_value << std::endl;
    std::cout << "Right: " << m_root->m_right->m_value << std::endl;
}

int test()
{
    BST* tree = new BST(7);
    tree->addValue(3);
    tree->addValue(45);
    
    //tree->printTree();
    return 1;
}

}