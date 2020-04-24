#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int k){
  key = k;
  Right = NULL;
  Left = NULL;
  Parent = NULL;
  isred = false;
}

int Node::getKey(){
  return key;
}

void Node::setKey(int k){
  key = k;
}

Node* Node::getLeft(){
  return Left;
}

void Node::setLeft(Node* n){
  Left = n;
}

Node* Node::getRight(){
  return Right;
}

void Node::setRight(Node* n){
  Right = n;
}

Node* Node::getParent(){
  return Parent;
}

void Node::setParent(Node* n){
  Parent = n;
}

void Node::toggleColor(){
  isred = !isred;
}

bool Node::isRed(){
  return isred;
}

void Node::rotateLeft(){
  if (Right == NULL){
    return;
  }
  Node* r = Right;
  Node* p = Parent;
  Right = Right->getLeft();
  r->setLeft(this);
  Parent = r;
  if (Right != NULL){
    Right->setParent(this);
  }
  if (p != NULL){
    if (this == p->getLeft()){
      p->setLeft(r);
    }
    else{
      p->setRight(r);
    }
  }
  r->setParent(p);
}

void Node::rotateRight(){
  if (Left == NULL){
    return;
  }
  Node* l = Left;
  Node* p = Parent;
  Left = Left->getRight();
  l->setRight(this);
  Parent = l;
  if (Left != NULL){
    Left->setParent(this);
  }
  if (p != NULL){
    if (this == p->getLeft()){
      p->setLeft(l);
    }
    else{
      p->setRight(l);
    }
  }
  l->setParent(p);
}

Node* Node::getSibling(){
  if (Parent == NULL){
    return NULL;
  }
  if (this == Parent->getLeft()){
    return Parent->getRight();
  }
  return Parent->getLeft();
}

Node* Node::getUncle(){
  if (Parent == NULL){
    return NULL;
  }
  return Parent->getSibling();
}

Node::~Node(){
  
}
