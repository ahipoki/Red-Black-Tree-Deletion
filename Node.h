#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
  public:
    Node(int);
    //Constructor
    int getKey();
    //Get key value
    void setKey(int);
    //Set key value
    Node* getLeft();
    //Get left node
    void setLeft(Node*);
    //Set left node
    Node* getRight();
    //Get right node
    void setRight(Node*);
    //Set right node
    Node* getParent();
    //Get parent node
    void setParent(Node*);
    //Set parent node
    Node* getUncle();
    //Get uncle node
    Node* getSibling();
    //Get sibling node
    void toggleColor();
    //Change color of node
    void rotateLeft();
    //Rotate left
    void rotateRight();
    //Rotate right
    bool isRed();
    //Check color of node
    ~Node();
    //Destructor
  private:
    Node* Left;
    //Left node
    Node* Right;
    //Right node
    Node* Parent;
    //Parent node
    int key;
    //Key value
    bool isred;
    //Color of node
};

#endif
