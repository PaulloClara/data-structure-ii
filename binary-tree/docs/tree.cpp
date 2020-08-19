#include <iostream>

using namespace std;

template <class T>
class TreeNode {
 private:
  T value;
  TreeNode<T> *left, *right;

 public:
  TreeNode() { this->left = this->right = NULL; }

  TreeNode(T value, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL) {
    this->set_value(value);

    this->left = left;
    this->right = right;
  }

  T get_value() { return this->value; }
  void set_value(T value) { this->value = value; }

  TreeNode<T> *get_left() { return this->left; }
  void set_left(T value) { this->left = new TreeNode<T>(value); }

  TreeNode<T> *get_right() { return this->right; }
  void set_right(T value) { this->right = new TreeNode<T>(value); }
};

template <class T>
class Tree {
 private:
  TreeNode<T> *root;

 public:
  Tree() { this->root = NULL; }

  ~Tree() { clear(); }

  void add(T value) {
    TreeNode<T> *p = this->root, *prev = NULL;

    while (p != NULL) {
      prev = p;

      if (value < p->get_value()) {
        p = p->get_left();
      } else {
        p = p->get_right();
      }
    }

    if (this->root == NULL) {
      this->set_root(value);
    } else if (value < prev->get_value()) {
      prev->set_left(value);
    } else {
      prev->set_right(value);
    }
  }

  void show(TreeNode<T> *node) {
    if (this->root == NULL) {
      cout << "\n <VOID>" << endl;
    } else {
      if (node != NULL) {
        cout << "<" << node->get_value();

        this->show(node->get_left());
        this->show(node->get_right());

        cout << ">";
      } else {
        cout << "<>";
      }
    }
  }

  void clear() { this->set_root(NULL); }

  TreeNode<T> *get_root() { return this->root; }
  void set_root(T value) { this->root = new TreeNode<T>(value); }
};
