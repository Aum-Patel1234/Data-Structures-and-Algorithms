#include <iostream>
#include <math.h>
#include <random>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
private:
  int getHeight(TreeNode *root) {
    if (!root)
      return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left, right) + 1;
  }
  void leftRotate(TreeNode *node) {}
  void rightRotate(TreeNode *node) {}

  void deleteTree(TreeNode *node) {
    if (node == nullptr)
      return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }

public:
  TreeNode *root;
  Solution(TreeNode *root = nullptr) { this->root = root; }
  ~Solution() { deleteTree(root); }

  void makeTree(int val, int flag) {
    TreeNode *newNode = new TreeNode(val);
    if (flag)
      root->left = newNode;
    else
      root->right = newNode;
    root = newNode;
    std::cout << "Inserted: " << val << "\tDirection: " << flag << std::endl;
  }

  void inOrder(TreeNode *root) {
    if (root) {
      inOrder(root->left);
      std::cout << root->val << "\t";
      inOrder(root->right);
    }
  }

  void printTree(TreeNode *root, int space = 0, int indent = 4) {
    if (!root)
      return;

    space += indent;

    printTree(root->right, space);

    std::cout << std::endl;
    for (int i = indent; i < space; i++)
      std::cout << ' ';
    std::cout << root->val << std::endl;

    printTree(root->left, space);
  }

  TreeNode *balanceBST(TreeNode *root) {
    int height = getHeight(root);
    return root;
  }
};

int main(int argc, char *argv[]) {
  // std::cout << argc << "\n" << argv[0] << std::endl;
  // Solution *sol = new Solution();
  // std::random_device rd;
  // std::mt19937 generator(rd());
  // std::uniform_int_distribution<> std_dist(0, 1);
  //
  // for (int i = 1; i < argc; i++) {
  //   int randomNum = std_dist(generator);
  //   sol->makeTree(std::stoi(argv[i]), randomNum);
  // }
  // sol->inOrder(sol->root);
  // std::cout << std::endl << std::endl;
  // sol->printTree(sol->root);
  // sol->balanceBST(sol->root);
  //
  // delete sol;
  // return 0;

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  Solution *sol = new Solution(root);

  std::cout << "\nInorder Traversal:\n";
  sol->inOrder(sol->root);

  std::cout << "\n\nTree Structure:\n";
  sol->printTree(sol->root);

  sol->balanceBST(sol->root); // Just for demonstration

  delete sol; // Cleans the whole tree safely
  return 0;
}
