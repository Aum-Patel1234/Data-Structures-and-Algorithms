#include <algorithm>
#include <cstdlib>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class AVL {
private:
  int getHeight(TreeNode *node) const {
    if (node == nullptr)
      return 0;
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
  }

  void deleteTree(TreeNode *root) {
    if (root == nullptr)
      return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }

  // AVL Tree functions
  TreeNode *insert(TreeNode *root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
      return root;
    }

    if (root->val > val)
      root->left = insert(root->left, val);
    else
      root->right = insert(root->right, val);

    // std::cout << "\t val of temp - " << root->val << std::endl;
    return rotate(root);
  }

  TreeNode *rotate(TreeNode *root) {
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (std::abs(leftHeight - rightHeight) <= 1) // normal case
      return root;

    if (leftHeight > rightHeight) { // left heavy
      int leftTreeChildHeight = getHeight(root->left->left);
      int rightTreeChildHeight = getHeight(root->left->right);
      if (leftTreeChildHeight > rightTreeChildHeight) { // LL case
        return rightRotate(root);
      } else { // LR case
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    } else { // right heavy
      int leftTreeChildHeight = getHeight(root->right->left);
      int rightTreeChildHeight = getHeight(root->right->right);
      if (leftTreeChildHeight > rightTreeChildHeight) { // RL case
        root->right = rightRotate(root->right);
        return leftRotate(root);
      } else { // RR case
        return leftRotate(root);
      }
    }
  }

  TreeNode *rightRotate(TreeNode *grandParent) {
    TreeNode *parent = grandParent->left;
    grandParent->left = parent->right;
    parent->right = grandParent;
    return parent;
  }
  TreeNode *leftRotate(TreeNode *grandParent) {
    TreeNode *parent = grandParent->right;
    grandParent->right = parent->left;
    parent->left = grandParent;
    return parent;
  }

public:
  TreeNode *root;
  AVL() : root(nullptr) {}

  ~AVL() { deleteTree(this->root); }

  int treeHeight() const { return getHeight(this->root); }

  void addTreeNode(int val) { this->root = insert(this->root, val); }

  void inorder(TreeNode *node) const {
    if (node == nullptr)
      return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
  }

  void printInorder() const {
    inorder(this->root);
    std::cout << std::endl;
  }

  void printTree(TreeNode *node, int space, int height) {
    if (node == nullptr)
      return;

    int indent = 8;

    printTree(node->right, space + indent, height);

    std::cout << std::endl;
    for (int i = 0; i < space; i++)
      std::cout << " ";
    std::cout << node->val << "\n";

    printTree(node->left, space + indent, height);
  }

  void printTreeVertically(TreeNode *root) {
    if (root == nullptr) {
      std::cout << "Empty tree.\n";
      return;
    }
    int height = 0;
    TreeNode *temp = root;

    height = treeHeight();

    printTree(root, 0, height);
  }
};

int main(int argLen, char *argv[]) {
  AVL *avl = new AVL();
  for (int i = 1; i < argLen; i++) {
    int num = std::atoi(argv[i]);
    std::cout << "Inserting " << num << " in the tree.\n";
    avl->addTreeNode(num);
    avl->printTreeVertically(avl->root);
  }

  std::cout << "Inorder traversal: ";
  avl->printInorder();
  std::cout << "Height of tree: " << avl->treeHeight() << std::endl;

  // avl->printTreeVertically(avl->root);

  delete avl;
  return 0;
}
