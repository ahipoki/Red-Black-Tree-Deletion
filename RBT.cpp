#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

RBT::RBT(){
  root = NULL;
}

void RBT::Insert(int in){
  Node* n = new Node(in);
  Insert(root, n);
  fixTree(n);
}
