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
  void set_left(TreeNode<T> *node) { this->left = node; }

  TreeNode<T> *get_right() { return this->right; }
  void set_right(T value) { this->right = new TreeNode<T>(value); }
  void set_right(TreeNode<T> *node) { this->right = node; }
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

  void remove(TreeNode<T> *node) {
    TreeNode<T> *subnode_root, *subnode, *before_node, *temp;

    if (node->get_left() == NULL) {
      subnode_root = node->get_right();
      subnode = node->get_left();
    } else {
      subnode_root = node->get_left();
      subnode = node->get_right();
    }

    if (node == this->get_root()) {
      this->set_root(subnode_root);
    } else {
      temp = this->get_root();

      while (temp != NULL && temp != node) {
        before_node = temp;

        if (temp->get_value() > node->get_value()) {
          temp = temp->get_left();
        } else {
          temp = temp->get_right();
        }
      }

      if (before_node->get_value() > subnode_root->get_value()) {
        before_node->set_left(subnode_root);
      } else {
        before_node->set_right(subnode_root);
      }
    }

    while (subnode_root->get_right() != NULL) {
      subnode_root = subnode_root->get_right();
    }

    subnode_root->set_right(subnode);

    delete node;
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

  int height(TreeNode<T> *root) {
    int bigger = 0;

    this->height_recursive(root, 0, &bigger);

    return bigger;
  }

  void height_recursive(TreeNode<T> *node, int current, int *bigger) {
    if (node == NULL) {
      return;
    }

    if (node->get_left() == NULL && node->get_right() == NULL) {
      if (current > *bigger) {
        *bigger = current;
      }

      return;
    }

    this->height_recursive(node->get_left(), current + 1, bigger);
    this->height_recursive(node->get_right(), current + 1, bigger);
  }

  void clear() { this->set_root(NULL); }

  TreeNode<T> *get_root() { return this->root; }
  void set_root(T value) { this->root = new TreeNode<T>(value); }
  void set_root(TreeNode<T> *node) { this->root = node; }
};
