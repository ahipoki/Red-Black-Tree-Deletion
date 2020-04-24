#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
  public:
    Node(int);
    int getKey();
    void setKey(int);
    Node* getLeft();
    void setLeft(Node*);
    Node* getRight();
    void setRight(Node*);
    Node* getParent();
    void setParent(Node*);
    Node* getUncle();
    Node* getSibling();
    void toggleColor();
    void rotateLeft();
    void rotateRight();
    bool isRed();
    ~Node();
  private:
    Node* Left;
    Node* Right;
    Node* Parent;
    int key;
    bool isred;
};

#endif
