#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
  public:
    RBT();
    void Insert(int);
    void PrintTree();
    void Search(int);
    void RemoveNode(int);
    ~RBT();
  private:
    Node* root;
    void Insert(Node*&, Node*);
    void PrintTree(Node*, int);
    void Search(Node*, int);
    void RemoveNode(Node*&, Node*);
    void fixTree(Node*);
    void deleteTree(Node*);
};

#endif
