#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
  public:
    RBT();
    void Insert(int);
    void PrintTree();
    bool Search(int);
    void RemoveNode(int);
    ~RBT();
  private:
    Node* root;
    void Insert(Node*&, Node*);
    void PrintTree(Node*, int);
    bool Search(Node*, int);
    bool RemoveNode(Node*&, Node*);
    void fixDoubleBlack(Node*);
    void fixTree(Node*);
    void deleteTree(Node*);
};

#endif
