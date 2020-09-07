#include <iostream>

#include "tree.cpp"

using namespace std;

int main() {
  Tree<int> *tree = new Tree<int>();

  tree->add(15);
  tree->add(10);
  tree->add(5);
  tree->add(4);
  tree->add(7);
  tree->add(30);
  tree->add(20);
  tree->add(40);

  cout << "Before: ";
  tree->show(tree->get_root());  // 15 10 30 5 4 7 20 40
  cout << "\nHeight: ";
  cout << tree->height(tree->get_root());  // 3

  tree->remove(tree->get_root());  // 15

  cout << "\n\nAfter: ";
  tree->show(tree->get_root());  // 10 5 30 4 7 20 40
  cout << "\nHeight: ";
  cout << tree->height(tree->get_root());  // 2

  cout << endl;

  return 0;
}
