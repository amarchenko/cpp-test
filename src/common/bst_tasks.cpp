#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <vector>

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

void InorderIterative(TreeNode* root) {
  unique_ptr< stack<TreeNode*> > st(new stack<TreeNode*>());
  TreeNode* current = root;

  while(current || !st->empty()) {
    if (current) {
      st->push(current);
      current = current->left;
    } else {
      current = st->top();
      st->pop();
      cout << "Value: " << current->value << endl;
      current = current->right;
    }
  }
}

void PreorderIterative(TreeNode* root) {
  unique_ptr< stack<TreeNode*> > st(new stack<TreeNode*>());
  TreeNode* current = root;

  while(current || !st->empty()) {
    if (current) {
      cout << "Value: " << current->value << endl;
      st->push(current);
      current = current->left;
    } else {
      current = st->top();
      st->pop();
      current = current->right;
    }
  }
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

int KthSmallestValue(TreeNode* root, int& k) {
  if (root->left) {
    KthSmallestValue(root->left, k);
  }
  --k;
  if (k == 0) {
    return root->value;
  }
  if (root->right) {
    KthSmallestValue(root->right, k);
  }
  return -1;
}

void Serialize(TreeNode* root, vector<int>& result) {
  if (!root) {
    return;
  }
  result.push_back(root->value);
  Serialize(root->left, result);
  Serialize(root->right, result);
}

TreeNode* DeserializeHelper(const vector<int>& input, int& index,
                            int min, int max) {
  TreeNode* root = nullptr;
  if (index == input.size()) {
    return root;
  } else if (min < input[index] && input[index] < max) {
    root = new TreeNode(input[index]);
    ++index;
    root->left = DeserializeHelper(input, index, min, root->value);
    root->right = DeserializeHelper(input, index, root->value, max);
  }
  return root;
}

TreeNode* Deserialize(const vector<int>& input) {
  int i = 0;
  return DeserializeHelper(input, i, INT_MIN, INT_MAX);
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

  // cout << "InorderIterative : " << endl;
  // InorderIterative(root.get());
  // cout << "PreorderIterative : " << endl;
  // PreorderIterative(root.get());
  int k = 3;
  cout << k << " smallest value: " << KthSmallestValue(root.get(), k) << endl;

  cout << "Serializing..." << endl;
  vector<int> ser;
  Serialize(root.get(), ser);
  for (auto& s : ser) {
    cout << s << " ";

  }
  cout << endl;

  TreeNode* des_root = nullptr;
  des_root = Deserialize(ser);
  PrintByLevelOrder(des_root);

  return 0;
}
