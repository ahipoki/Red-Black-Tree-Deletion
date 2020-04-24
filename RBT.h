#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
  public:
    RBT();
    void Insert(int);
    void PrintTree();
    ~RBT();
  private:
    Node* root;
    void Insert(Node*&, Node*);
    void PrintTree(Node*, int);
    void fixTree(Node*);
    void deleteTree(Node*);
};

#endif
