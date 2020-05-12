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

void RBT::Insert(Node* &h, Node* n){
  if (root == NULL){
    root = n;
    return;
  }
  if (n->getKey() < h->getKey()){
    if (h->getLeft()){
      Node* t = h->getLeft();
      Insert(t, n);
      return;
    }
    else{
      h->setLeft(n);
    }
  }
  else{
    if (h->getRight()){
      Node* t = h->getRight();
      Insert(t, n);
      return;
    }
    else{
      h->setRight(n);
    }
  }
  n->setParent(h);
  if (!n->isRed()){
    n->toggleColor();
  }
}

bool RBT::Search(int in){//Enter a number and return whether it is in the tree
  return Search(root, in);
}

bool RBT::Search(Node* h, int d){
  if (!h){
    return false;
  }
  if (h->getKey() == d){
    return true;
  }
  if (d < h->getKey()){
    if (h->getLeft() == NULL){
      return false;
    }
    return Search(h->getLeft(), d);
  }
  else{
    if (h->getRight() == NULL){
      return false;
    }
    return Search(h->getRight(), d);
  }
}

void RBT::RemoveNode(int in){//Remove a particular number. Update the tree.
  if (RemoveNode(root, in)){
    cout<<"Node deleted"<<endl;
  }
}

bool RBT::RemoveNode(Node* &h, int n){
  if (h == NULL){
    cout<<"Empty tree or node not found."<<endl;
    return false;
  }
  if (n < h->getKey()){
    Node* temp = h->getLeft();
    return RemoveNode(temp, n);
  }
  if (n > h->getKey()){
    Node* temp = h->getRight();
    return RemoveNode(temp, n);
  }
  Node* child = NULL;
  if (h->getLeft() != NULL && h->getRight() != NULL){
    child = h->getRight();
    while (child->getLeft()){
      child = child->getLeft();
    }
    h->setKey(child->getKey());
    RemoveNode(child, child->getKey());
  }
  else if (h->getLeft() != NULL || h->getRight() != NULL){
    child = (h->getRight() == NULL ? h->getLeft() : h->getRight());
    bool bothAreBlack = (!child->isRed() && !h->isRed());
    if (root == NULL){
      h->setKey(child->getKey());
      h->setRight(NULL);
      h->setLeft(NULL);
      delete child;
    }
    else{
      if (h == h->getParent()->getLeft()){
        h->getParent()->setLeft(child);
      }
      else{
        h->getParent()->setRight(child);
      }
      delete h;
      child->setParent(h->getParent());
      if (bothAreBlack){
        fixDBlack(child);
      }
      else{
        if (child->isRed()){
          child->toggleColor();
        }
      }
    }
    else{
      if (root == h){
        root = NULL;
        delete h;
      }
      else{
        if (!h->isRed()){
          fixDBlack(h);
        }
        else{
          if (h->getSibling() != NULL && !h->getSibling()->isRed()){
            h->getSibling()->toggleColor();
          }
      if (h->getParent()->getLeft() == h){
        h->getParent()->setLeft(NULL);
      }
      else{
        h->getParent()->setRight(NULL);
      }
      delete h;
    }
  }
  return true;
}
void RBT::fixTree(Node* n){
  if (n == NULL){
    return;
  }
  if (n->getParent() == NULL){
    if (n->isRed()){
      n->toggleColor();
    }
  }
  else if (!n->getParent()->isRed()){
    
  }
  else if (n->getUncle() && n->getUncle()->isRed()){
    n->getParent()->toggleColor();
    n->getUncle()->toggleColor();
    if (!n->getParent()->getParent()->isRed()){
      n->getParent()->getParent()->toggleColor();
    }
    fixTree(n->getParent()->getParent());
  }
  else{
    Node* p = n->getParent();
    Node* g = p->getParent();
    if (n == p->getRight() && p == g->getRight()){
      p->rotateLeft();
      n = n->getLeft();
    }
    else if (n == p->getLeft() && p == g->getRight()){
      p->rotateRight();
      n = n->getRight();
    }
    p = n->getParent();
    g = p->getParent();
    if (n == p->getLeft()){
      g->rotateRight();
    }
    else{
      g->rotateLeft();
    }
    if (g == root){
      root = p;
    }
    p->toggleColor();
    g->toggleColor();
  }
}

void RBT::PrintTree(){
  PrintTree(root, 0);
}

void RBT::PrintTree(Node* h, int d){
  if (!h){
    return;
  }
  PrintTree(h->getLeft(), d+1);
  for (int i = 0; i < d; i++){
    cout<<"    ";
  }
  cout<<(h->isRed() ? "\033[1;31m" : "\033[1;30m")<<h->getKey()<<"\033[0m"<<endl;
  PrintTree(h->getRight(), d+1);
}

RBT::~RBT(){
  deleteTree(root);
}

void RBT::deleteTree(Node* n){
  if (!n){
    return;
  }
  deleteTree(n->getLeft());
  deleteTree(n->getRight());
  delete n;
}
