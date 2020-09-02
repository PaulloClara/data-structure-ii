#include <time.h>

#include <iostream>

using namespace std;

template <class T>
class TreeNode {
 private:
  T value;
  TreeNode<T> *left, *right;
  bool successor;

 public:
  TreeNode() {
    this->left = NULL;
    this->right = NULL;

    this->successor = false;
  }

  TreeNode(T v, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL, bool s = false) {
    this->set_value(v);

    this->left = l;
    this->right = r;

    this->successor = s;
  }

  T get_value() { return this->value; }
  void set_value(T value) { this->value = value; }

  TreeNode<T> *get_left() { return this->left; }
  void set_left(T value) { this->left = new TreeNode<T>(value); }

  TreeNode<T> *get_right() { return this->right; }
  void set_right(T value) {
    this->right = new TreeNode<T>(value);
    this->successor = false;
  }

  bool is_successor() { return this->successor; }
  void set_successor(TreeNode<T> *successor) {
    this->right = successor;
    this->successor = true;
  }
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

    TreeNode<T> *temp_node = this->get_root(), *node = NULL;

    while (temp_node != NULL) {
      node = temp_node;

      if (temp_node->get_value() > value) {
        temp_node = temp_node->get_left();
      } else if (!temp_node->is_successor()) {
        temp_node = temp_node->get_right();
      } else {
        break;
      }
    }

    if (node->get_value() > value) {
      node->set_left(value);
      node->get_left()->set_successor(node);
    } else if (node->is_successor()) {
      temp_node = node->get_right();

      node->set_right(value);
      node->get_right()->set_successor(temp_node);
    } else {
      node->set_right(value);
    }
  }

  void show_pre_order(TreeNode<T> *root) {
    TreeNode<T> *node = root;

    while (node != NULL) {
      cout << " " << node->get_value();

      if (node->get_left() != NULL) {
        node = node->get_left();
      } else if (node->get_right() != NULL) {
        if (node->is_successor()) {
          node = node->get_right()->get_right();
        } else {
          node = node->get_right();
        }
      }
    }
  }

  void clear() { this->set_root(NULL); }

  TreeNode<T> *get_root() { return this->root; }
  void set_root(T value) { this->root = new TreeNode<T>(value); }
};

int main() {
  Tree<char> *tree = new Tree<char>();
  int loop = 140000;
  clock_t counter;

  tree->add('F');
  tree->add('B');
  tree->add('A');
  tree->add('D');
  tree->add('C');
  tree->add('E');
  tree->add('G');
  tree->add('I');
  tree->add('H');

  counter = clock();

  while (loop) {
    cout << "\nPreOrder:\n\t";
    tree->show_pre_order(tree->get_root());

    loop--;
  }

  cout << "\n\nClock:\n\t" << (clock() - counter) / 140000 << "\n\n";

  return 0;
}

// 7
// 10
// 5
