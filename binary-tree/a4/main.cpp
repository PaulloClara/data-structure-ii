#include <iostream>

#include "tree.cpp"

using namespace std;

int main() {
  Tree<char> *tree = new Tree<char>();

  tree->add_recursive('F');
  tree->add('B');
  tree->add_recursive('A');
  tree->add('D');
  tree->add_recursive('C');
  tree->add('E');
  tree->add('G');
  tree->add_recursive('I');
  tree->add_recursive('H');

  tree->show(tree->get_root());

  cout << endl;

  return 0;
}
