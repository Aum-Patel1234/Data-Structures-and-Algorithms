#include <cstdlib>
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
class AVL {
private:
  int getHeight(TreeNode *root) const {
    if (!root)
      return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left, right) + 1;
  }
  void leftRotate(TreeNode *&node) {
    TreeNode *g = node, *p = node->right;
    g->right = p->left;
    p->left = g;
    node = p;
  }
  void rightRotate(TreeNode *&node) {
    TreeNode *g = node, *p = node->left;
    g->left = p->right;
    p->right = g;
    node = p;
  }

  // NOTE: funcs to find unbalancedSubtreeRoot
  TreeNode *unbalancedSubtreeRoot = nullptr;
  int checkBalance(TreeNode *node) {
    if (node == nullptr)
      return 0;

    int leftHeight = checkBalance(node->left);
    int rightHeight = checkBalance(node->right);

    if (!unbalancedSubtreeRoot && std::abs(leftHeight - rightHeight) > 1)
      unbalancedSubtreeRoot = node;

    return 1 + std::max(leftHeight, rightHeight);
  }
  TreeNode *findUnbalancedSubtreeRoot(TreeNode *root) {
    unbalancedSubtreeRoot = nullptr; // Reset
    checkBalance(root);
    return unbalancedSubtreeRoot;
  }

  // NOTE: func to balance tree
  TreeNode **findPtr(TreeNode **p, TreeNode *target) {
    if (!*p)
      return nullptr;
    if (*p == target)
      return p;
    TreeNode **left = findPtr(&(*p)->left, target);
    if (left)
      return left;
    return findPtr(&(*p)->right, target);
  }

  void balanceOnce() {
    TreeNode *u = findUnbalancedSubtreeRoot(root);
    if (!u)
      return;
    // get reference to the pointer that points to u
    TreeNode **uptr = findPtr(&root, u); // IMPORTANT:
    std::cout << "Address of pointer to node (uptr): " << uptr << std::endl;
    std::cout << "Address of node (*uptr): " << *uptr << std::endl;
    std::cout << "Value at node ((*uptr)->val): " << (*uptr)->val << std::endl;
    TreeNode *&node = *uptr;
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);
    if (lh > rh) {
      int llh = getHeight(node->left->left);
      int lrh = getHeight(node->left->right);
      if (llh >= lrh) {
        rightRotate(node); // LL
      } else {
        leftRotate(node->left); // LR
        rightRotate(node);
      }
    } else {
      int rlh = getHeight(node->right->left);
      int rrh = getHeight(node->right->right);
      if (rrh >= rlh) {
        leftRotate(node); // RR
      } else {
        rightRotate(node->right); // RL
        leftRotate(node);
      }
    }
  }
  // TreeNode *findParent(TreeNode *root, TreeNode *child) {
  //   if (root == nullptr || root == child)
  //     return nullptr;
  //
  //   if (root->left == child || root->right == child)
  //     return root;
  //
  //   TreeNode *leftSearch = findParent(root->left, child);
  //   if (leftSearch)
  //     return leftSearch;
  //
  //   return findParent(root->right, child);
  // }

  void deleteTree(TreeNode *node) {
    if (node == nullptr)
      return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }

public:
  TreeNode *root;
  AVL(TreeNode *root = nullptr) { this->root = root; }
  ~AVL() { deleteTree(root); }

  void makeTree(int val, int flag) {
    TreeNode *newNode = new TreeNode(val);
    if (flag)
      root->left = newNode;
    else
      root->right = newNode;
    root = newNode;
    std::cout << "Inserted: " << val << "\tDirection: " << flag << std::endl;
  }

  int getTreeHeight() const { return getHeight(root); }
  int showUnbalancedSubtreeRoot() {
    this->findUnbalancedSubtreeRoot(this->root);
    return this->unbalancedSubtreeRoot->val;
  }

  void inOrder(TreeNode *root) const {
    if (root) {
      inOrder(root->left);
      std::cout << root->val << "\t";
      inOrder(root->right);
    }
  }

  void printTree(TreeNode *root, int space = 0, int indent = 4) const {
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

  TreeNode *balanceBST(TreeNode *&node) {
    while (true) {
      TreeNode *unbalanced = findUnbalancedSubtreeRoot(node);
      if (!unbalanced)
        break;
      balanceOnce();
    }
    this->root = node; // IMPORTANT: most imp as the root is updated
    return node;
  }

  void printAdress(TreeNode *root) {
    if (root == nullptr)
      return;
    printAdress(root->left);
    std::cout << "val - " << root->val << " is stored at - " << root
              << std::endl;
    printAdress(root->right);
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

  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->left->left->left->left = new TreeNode(5);

  AVL *sol = new AVL(root);

  std::cout << "\nInorder Traversal:\n";
  sol->inOrder(sol->root);

  std::cout << "\n\nTree Structure:\n";
  sol->printTree(sol->root);

  std::cout << "Height of the Tree is - " << sol->getTreeHeight() << std::endl;
  int unbalancedSubtreeRoot = sol->showUnbalancedSubtreeRoot();
  std::cout << "unbalancedSubtreeRoot - " << unbalancedSubtreeRoot << std::endl;

  TreeNode *ptr = sol->balanceBST(sol->root); // Just for demonstration

  std::cout << "\n\nTree Structure after balancing :\n";
  sol->printTree(sol->root);
  std::cout << "\n" << sol->root->val << "Ptr val " << ptr->val << "\n";

  sol->printAdress(sol->root);

  delete sol; // Cleans the whole tree safely
  return 0;
}
