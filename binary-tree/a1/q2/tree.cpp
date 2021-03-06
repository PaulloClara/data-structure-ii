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

  void show_pre_order(TreeNode<T> *node) {
    if (node == NULL) {
      cout << "<>";

      return;
    }

    cout << node->get_value();
    cout << "<";
    this->show_pre_order(node->get_left());
    cout << ">";
    this->show_pre_order(node->get_right());
  }

  void show_in_order(TreeNode<T> *node) {
    if (node == NULL) {
      cout << "<>";

      return;
    };

    cout << "<";
    this->show_in_order(node->get_left());
    cout << node->get_value();
    cout << ">";
    this->show_in_order(node->get_right());
  }

  void show_pos_order(TreeNode<T> *node) {
    if (node == NULL) {
      cout << "<>";

      return;
    };

    cout << "<";
    this->show_pos_order(node->get_left());
    cout << ">";
    this->show_pos_order(node->get_right());
    cout << node->get_value();
  }

  void clear() { this->set_root(NULL); }

  TreeNode<T> *get_root() { return this->root; }
  void set_root(T value) { this->root = new TreeNode<T>(value); }
};
