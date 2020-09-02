#include <iostream>

#include "tree.cpp"

using namespace std;

int main() {
  Tree<char> *tree = new Tree<char>();

  tree->add('F');
  tree->add('B');
  tree->add('A');
  tree->add('D');
  tree->add('C');
  tree->add('E');
  tree->add('G');
  tree->add('I');
  tree->add('H');

  cout << "PreOrder:\n\t";
  tree->show_pre_order(tree->get_root());

  cout << endl;

  return 0;
}
