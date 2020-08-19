#include <iostream>

#include "tree.cpp"

using namespace std;

int main() {
  Tree<int>* tree = new Tree<int>();

  tree->add(13);
  tree->add(10);
  tree->add(12);
  tree->add(2);
  tree->add(25);
  tree->add(31);
  tree->add(20);
  tree->add(29);

  tree->show(tree->get_root());

  cout << endl;

  return 0;
}
