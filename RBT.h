#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
  public:
    RBT();//Constructor
    void Insert(int);//Public Insert
    void PrintTree();//Public PrintTree
    bool Search(int);//Public Searc
    void RemoveNode(int);//Public RemoveNode
    ~RBT();//Destructor
  private:
    Node* root;//Root node
    void Insert(Node*&, Node*);//Private Insert
    void PrintTree(Node*, int);//Private PrintTree
    bool Search(Node*, int);//Private Search
    bool RemoveNode(Node*&, Node*);//Private RemoveNode
    void fixDoubleBlack(Node*);//Fix double black
    void fixTree(Node*);//Fix tree
    void deleteTree(Node*);//Delete tree
};

#endif
