#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int k){
  key = k;
  //Key
  Right = NULL;
  Left = NULL;
  Parent = NULL;
  //Right, left, and parent are set to NULL
  isred = false;
  //isred set to false
}

int Node::getKey(){//Get key
  return key;
  //Return key
}

void Node::setKey(int k){//Set key
  key = k;
  //key = k
}

Node* Node::getLeft(){//Get left
  return Left;
  //Return left
}

void Node::setLeft(Node* n){//Set left
  Left = n;
  //Left = n
}

Node* Node::getRight(){//Get right
  return Right;
  //Return right
}

void Node::setRight(Node* n){//Set right
  Right = n;
  //Right = n
}

Node* Node::getParent(){//Get parent
  return Parent;
  //Return parent
}

void Node::setParent(Node* n){//Set parent
  Parent = n;
  //Parent = n
}

void Node::toggleColor(){//Toggle color
  isred = !isred;
  //Change color of node
  //If red, become black
  //If black, become red
}

bool Node::isRed(){//Check node's color
  return isred;
  //Return node's color
}

void Node::rotateLeft(){//Rotate left
  if (Right == NULL){//If there's no node to the right
    return;
    //Return
  }
  Node* r = Right;
  //Node r equals right node
  Node* p = Parent;
  //Node p equals parent node
  Right = Right->getLeft();
  //Right node is now the value of the right node's left node
  r->setLeft(this);
  //Set r node's left node to this
  Parent = r;
  //Parent node is now r's value
  if (Right != NULL){//If there is a right node
    Right->setParent(this);
    //Set right node's parent node to this
  }
  if (p != NULL){//If there is a p node
    if (this == p->getLeft()){//If this equals p's left node
      p->setLeft(r);
      //Set p's left node to r
    }
    else{//Anything else
      p->setRight(r);
      //Set p's right node to r
    }
  }
  r->setParent(p);
  //Set r's parent node to p
}

void Node::rotateRight(){//Rotate right
  if (Left == NULL){//If there is no left node
    return;
    //Return
  }
  Node* l = Left;
  //Node l equals left node
  Node* p = Parent;
  //Node p equals parent node
  Left = Left->getRight();
  //Left node now equals left node's right node
  l->setRight(this);
  //Set l's right node to this
  Parent = l;
  //Parent node now equals l
  if (Left != NULL){//If there is a left node
    Left->setParent(this);
    //Set left node's parent node to this
  }
  if (p != NULL){//If there is a p node
    if (this == p->getLeft()){//If this equals p's left node
      p->setLeft(l);
      //Set p's left node to l
    }
    else{//Anything else
      p->setRight(l);
      //Set p's right node to l
    }
  }
  l->setParent(p);
  //Set l's parent node to p
}

Node* Node::getSibling(){//Get sibling
  if (Parent == NULL){//If there is no parent node
    return NULL;
    //Return NULL
  }
  if (this == Parent->getLeft()){//If this equals parent's left node
    return Parent->getRight();
    //Return parent's right node
  }
  return Parent->getLeft();
  //Otherwise, return parent's left node
}

Node* Node::getUncle(){//Get uncle
  if (Parent == NULL){//If there is no parent node
    return NULL;
    //Return NULL
  }
  return Parent->getSibling();
  //Otherwise, return parent's sibling
}

Node::~Node(){//Destructor
  
}
