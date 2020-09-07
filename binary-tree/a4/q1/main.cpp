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

  cout << "Before (PreOrder): ";
  tree->show(tree->get_root());  // 15 10 5 4 7 30 20 40

  tree->remove(tree->get_root()->get_left()->get_left(), tree->get_root());
  // 5

  cout << "\nAfter (PreOrder): ";
  tree->show(tree->get_root());  // 15 10 30 20 40

  cout << endl;

  return 0;
}
