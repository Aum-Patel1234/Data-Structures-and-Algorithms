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
  struct TreeNode *curr;

  int getHeight(TreeNode *root) {
    if (!root)
      return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left, right) + 1;
  }
  void leftRotate(TreeNode *node) {}
  void rightRotate(TreeNode *node) {}

public:
  struct TreeNode *root;

  Solution() {
    this->curr = new TreeNode(0);
    this->root = this->curr;
  }
  ~Solution() {
    delete this->curr;
    delete this->root;
  }

  void makeTree(int val, int flag) {
    TreeNode *newNode = new TreeNode(val);
    if (flag)
      curr->left = newNode;
    else
      curr->right = newNode;
    curr = newNode;
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

    if (root->left)
      std::cout << "Left - " << root->left->val << std::endl;
    if (root->right)
      std::cout << "Right - " << root->right->val << std::endl;

    printTree(root->left);
    printTree(root->right);
  }

  TreeNode *balanceBST(TreeNode *root) {
    int height = getHeight(root);
    return root;
  }
};

int main(int argc, char *argv[]) {
  // std::cout << argc << "\n" << argv[0] << std::endl;
  Solution *sol = new Solution();
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> std_dist(0, 1);

  for (int i = 1; i < argc; i++) {
    int randomNum = std_dist(generator);
    sol->makeTree(std::stoi(argv[i]), randomNum);
  }
  sol->inOrder(sol->root);
  std::cout << std::endl << std::endl;
  sol->printTree(sol->root);
  sol->balanceBST(sol->root);

  delete sol;
  return 0;
}
