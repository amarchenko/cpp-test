#include <iostream>
#include <memory>
#include <queue>

using namespace std;

struct TreeNode {
  TreeNode() : value(0), left(nullptr), right(nullptr) {}
  TreeNode(const int& v) : value(v), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    delete this->left;
    delete this->right;
  }

  int value;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* InsertNode(TreeNode* tree_node, int value) {
  if (!tree_node)
    return new TreeNode(value);
  else if (tree_node->value > value)
    tree_node->left = InsertNode(tree_node->left, value);
  else
    tree_node->right = InsertNode(tree_node->right, value);
  return tree_node;
}

void PrintByLevelOrder(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode*> current_level, next_level;
  current_level.push(root);

  while (!current_level.empty()) {
    TreeNode *curr_node = current_level.front();
    current_level.pop();
    if (curr_node) {
      std::cout << curr_node->value << " ";
      next_level.push(curr_node->left);
      next_level.push(curr_node->right);
    }
    if (current_level.empty()) {
      std::cout << std::endl;
      swap(current_level, next_level);
    }
  }
}

// Lowest Common Ancestor
TreeNode* FindLCA(TreeNode* node, int value1, int value2) {
  if (!node) return nullptr;
  if (node->value == value1 || node->value == value2) return node;

  TreeNode* left_lca = FindLCA(node->left, value1, value2);
  TreeNode* right_lca = FindLCA(node->right, value1, value2);

  if (left_lca && right_lca) return node;

  return (left_lca != nullptr) ? left_lca : right_lca;
}

bool ValidateBST(TreeNode* root) {
  if (!root) return true;

  if ((root->left && root->left->value > root->value) ||
      (root->right && root->right->value < root->value)) {
    return false;
  }

  return ValidateBST(root->left) && ValidateBST(root->right);
}

int main() {
  unique_ptr<TreeNode> root(new TreeNode(4));
  InsertNode(root.get(), 2);
  InsertNode(root.get(), 1);
  InsertNode(root.get(), 3);
  InsertNode(root.get(), 5);
  InsertNode(root.get(), 0);
  InsertNode(root.get(), 6);
  InsertNode(root.get(), 8);

  PrintByLevelOrder(root.get());
  cout << "LCA: " << FindLCA(root.get(), 4, 5)->value << endl;
  cout << "Is BST? " << ValidateBST(root.get()) <<endl;

  return 0;
}
