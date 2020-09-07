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
  void set_left() { this->left = NULL; }
  void set_left(T value) { this->left = new TreeNode<T>(value); }

  TreeNode<T> *get_right() { return this->right; }
  void set_right() { this->right = NULL; }
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
    if (this->get_root() == NULL) {
      this->set_root(value);

      return;
    }

    TreeNode<T> *p = this->get_root(), *prev = NULL;

    while (p != NULL) {
      prev = p;

      if (p->get_value() > value) {
        p = p->get_left();
      } else if (p->get_value() < value) {
        p = p->get_right();
      } else {
        return;
      }
    }

    if (value < prev->get_value()) {
      prev->set_left(value);
    } else {
      prev->set_right(value);
    }
  }

  void show(TreeNode<T> *root) {
    cout << root->get_value() << " ";

    this->show_recursive(root);
  }

  void show_recursive(TreeNode<T> *node) {
    if (node == NULL) {
      return;
    }

    if (node->get_left() != NULL) {
      cout << node->get_left()->get_value() << " ";
    }
    if (node->get_right() != NULL) {
      cout << node->get_right()->get_value() << " ";
    }

    this->show_recursive(node->get_left());
    this->show_recursive(node->get_right());
  }

  void clear() { this->set_root(NULL); }

  TreeNode<T> *get_root() { return this->root; }
  void set_root(T value) { this->root = new TreeNode<T>(value); }
};
