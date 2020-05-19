#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

RBT::RBT(){//Constructor
  root = NULL;//Root is NULL
}

void RBT::Insert(int in){//Public Insert function
  Node* n = new Node(in);//Node n is a new node with in
  Insert(root, n);//Call private Insert function with root and n nodes
  fixTree(n);//Fixtree with node n
}

void RBT::Insert(Node* &h, Node* n){//Private Insert function
  if (root == NULL){//If root is NULL
    root = n;//Root is now n
    return;//Return
  }
  if (n->getKey() < h->getKey()){//If node n's key value is less than node h's key value
    if (h->getLeft()){//If node h's left node
      Node* t = h->getLeft();//Node t is now equal to h's left node
      Insert(t, n);//Call private Insert function with nodes t and n
      return;//Return
    }
    else{//Anything else
      h->setLeft(n);//Set h's left node to n
    }
  }
  else{//Anything else
    if (h->getRight()){//If h's right node
      Node* t = h->getRight();//Node t is now h's right node
      Insert(t, n);//Call private Insert function with nodes t and n
      return;//Return
    }
    else{//Anything else
      h->setRight(n);//Set h's right node to n
    }
  }
  n->setParent(h);//Set n's parent node to h
  if (!n->isRed()){//If node n's color is black
    n->toggleColor();//Change node n's color
  }
}

bool RBT::Search(int in){//Public Searc function
  return Search(root, in);//Return private Search function with root and in
}

bool RBT::Search(Node* h, int d){//Private Search function
  if (!h){//If not node h
    return false;//Return false
  }
  if (h->getKey() == d){//If h's key value equals d
    return true;//Return true
  }
  if (d < h->getKey()){//If d is less than h's key value
    if (h->getLeft() == NULL){//If h's left node is NULL
      return false;//Return false
    }
    return Search(h->getLeft(), d);//Return private Search function with h's left node and d
  }
  else{//Anything else
    if (h->getRight() == NULL){//If h's right node is NULL
      return false;//Return false
    }
    return Search(h->getRight(), d);//Return private Search function with h's right node and d
  }
}

bool RBT::RemoveNode(int in){//Public RemoveNode function
  return RemoveNode(root, in);
}

bool RBT::RemoveNode(Node* &h, int n){//Private RemoveNode function
  if (h == NULL) {//If h is NULL
    return false;//Return false
  }
  if (n < h->getKey()) {//If n is less than h's key value
    Node* temp = h->getLeft();//Node temp is h's left node
    return RemoveNode(temp, n);//Return private RemoveNode function with temp and n
  }
  if (n > h->getKey()){//If n is greater than h's key value
    Node* temp = h->getRight();//Node temp is h's right node
    return RemoveNode(temp, n);//Return private RemoveNode function with temp and n
  }
  Node* child = NULL;//Node child is NULL
  if (h->getLeft() != NULL && h->getRight() != NULL){//If h's left node is not NULL and h's right node is not NULL
    child = h->getRight();//Child equals h's right node
    while (child->getLeft()){//While child's left node
      child = child->getLeft();//Child equals child's left node
    }
    h->setKey(child->getKey());//Set h's key value to child's key value
    RemoveNode(child, child->getKey());//Call private RemoveNode function with child and child's key value
  }
  else if (h->getLeft() != NULL || h->getRight() != NULL){//Else if h's left node is not NULL or h's right node is not NULL
    child = (h->getRight() == NULL ? h->getLeft() : h->getRight());//If h's right node is NULL, set child to h's left node, otherwise set it to h's right node
    bool bothAreBlack = (!child->isRed() && !h->isRed());//If child and h nodes are black
    if (root == h){//If root equals h
      h->setKey(child->getKey());//Set h's key value to child's key value
      h->setRight(NULL);//Set h's right node to NULL
      h->setLeft(NULL);//Set h's left node to NULL
      delete child;//Delete child
    }
    else{//Anything else
      if (h == h->getParent()->getLeft()){//If h equals h's parent's left node
      	h->getParent()->setLeft(child);//Set h's parent's left node to child
      }
      else{//Anything else
        h->getParent()->setRight(child);//Set h's parent's right node to child
      }
      delete h;//Delete h
      child->setParent(h->getParent());//Set child's parent node to h's parent node
      if (bothAreBlack){//If both are black
      	fixDoubleBlack(child);//Call fixDoubleBlack with child
      } 
      else{//Anything else
        if (child->isRed()){//If child is red
	  child->toggleColor();//Change child node's color
	}
      }
    }
  }
  else{//Anything else
    if (root == h){//If root is h
      root = NULL;//Root is NULL
      delete h;//Delete h
    } 
    else{//Anything else
      if (!h->isRed()){//If h is black
      	fixDoubleBlack(h);//Fix double black with h
      }
      else{//Anything else
      	if (h->getSibling() != NULL && !h->getSibling()->isRed()){//If h's sibling node is not NULL and h's sibling node is black
          h->getSibling()->toggleColor();//Change h's sibling node's color
        }
      }
      if (h->getParent()->getLeft() == h){//If h's parent's left node is h
        h->getParent()->setLeft(NULL);//Set h's parent's left node to NULL
      }
      else{//Anything else
        h->getParent()->setRight(NULL);//Set h's parent's right node to NULL
      }
      delete h;//Delete h
    }
  }
  return true;//Return true
}

void RBT::fixDoubleBlack(Node* n){//Fix double black
  if (root == n){//If root is n
    return;//Return
  }
  Node* sibling = n->getSibling();//Sibling node is n's sibling node
  Node* parent = n->getParent();//Parent node is n's parent node
  if (sibling == NULL){//If sibling is NULL
    fixDoubleBlack(parent);//Call fixDoubleBlack with parent
  }
  else{//Anything else
    if (sibling->isRed()){//If sibling is red
      if (!parent->isRed()){//If parent is black
        parent->toggleColor();//Change parent node's color
      }
      sibling->toggleColor();//Change sibling's color
      if (sibling == parent->getLeft()){//If sibling is parent's left node
        rotateRight(parent);//Rotate right with parent
      }
      else{//Anything else
        rotateLeft(parent);//Rotate left with parent
      }
      fixDoubleBlack(n);//Fix double black with n
    }
    else{//Anything else
      if ((sibling->getLeft() && sibling->getLeft()->isRed()) || (sibling->getRight() && sibling->getRight()->isRed())){//If sibling's left node and sibling's left node is red or sibling's right node and sibling's right node is red
        if (sibling->getLeft() && sibling->getLeft()->isRed()){//If sibling's left node and sibling's left node is red
          if (sibling->getParent()->getLeft() == sibling){//If sibling's parent's left node is sibling
            if (sibling->getLeft()->isRed() != sibling->isRed()){//If sibling's left node is red does not equal sibling is red
              sibling->getLeft()->toggleColor();//Change sibling's left node's color
            }
            if (sibling->isRed() != sibling->getParent()->isRed()){//If sibling is red does not equal sibling's parent is red
              sibling->toggleColor();//Change sibling's color
            }
            rotateRight(parent);//Rotate right with parent
          }
          else{//Anything else
            if (sibling->getLeft()->isRed() != sibling->getParent()->isRed()){//If sibling's left node is red does not equal sibling's parent is red
              sibling->getLeft()->toggleColor();//Change sibling's left node's color
            }
            rotateRight(sibling);//Rotate right with sibling
            rotateLeft(parent);//Rotate left with parent
          }
        }
        else{//Anything else
          if (sibling->getParent()->getLeft() == sibling){//If sibling's parent's left node is sibling
            if (sibling->getRight()->isRed() != sibling->getParent()->isRed()){//If sibling's right node is red does not equal sibling's parent is red
              sibling->getRight()->toggleColor();//Change sibling's right node's color
            }
	    rotateLeft(sibling);//Rotate left with sibling
	    rotateRight(parent);//Rotate right with parent
          }
          else {//Anything else
	    if (sibling->getRight()->isRed() != sibling->isRed()){//If sibling's right node is red does not equal sibling is red
              sibling->getRight()->toggleColor();//Change sibling's right node's color
            }
	    if (sibling->isRed() != sibling->getParent()->isRed()){//If sibling is red does not equal sibling's parent is  red
              sibling->toggleColor();//Change sibling's color
            }
	    rotateLeft(parent);//Rotate left with parent
	  }
	}
        if (parent->isRed()){//If parent is red
          parent->toggleColor();//Change parent's color
        }
      } 
      else{//Anything else
      	if (!sibling->isRed()){//If sibling is black
          sibling->toggleColor();//Change sibling's color
        }
	if (!parent->isRed()){//If parent is black
	  fixDoubleBlack(parent);//Fix double black with parent
	}
      else{//Anything else
      	parent -> toggleColor();//Change parent's color
      }
    }
  }
}
}

void RBT::fixTree(Node* n){//Fix tree
  if (n == NULL){//If n is NULL
    return;//Return
  }
  if (n->getParent() == NULL){//If n's parent node is NULL
    if (n->isRed()){//If n is red
      n->toggleColor();//Change n's color
    }
  }
  else if (!n->getParent()->isRed()){//Else if n's parent is black
    //Do nothing here
  }
  else if (n->getUncle() && n->getUncle()->isRed()){//Else if it's n's uncle and n's uncle is red
    n->getParent()->toggleColor();//Change n's parent's color
    n->getUncle()->toggleColor();//Change n's uncle's color
    if (!n->getParent()->getParent()->isRed()){//If n's grandparent is black
      n->getParent()->getParent()->toggleColor();//Change n's grandparent's color
    }
    fixTree(n->getParent()->getParent());//Fix tree with n's grandparent
  }
  else{//Anything else
    Node* p = n->getParent();//Node p is n's parent
    Node* g = p->getParent();//Node g is p's parent
    if (n == p->getRight() && p == g->getRight()){//If n equals p's right node and p equals g's right node
      p->rotateLeft();//p->rotate left
      n = n->getLeft();//N is n's left node
    }
    else if (n == p->getLeft() && p == g->getRight()){//Else if n equals p's left node and p equals g's right node
      p->rotateRight();//p->rotate right
      n = n->getRight();//N is n's right node
    }
    p = n->getParent();//P is n's parent node
    g = p->getParent();//G is p's parent node
    if (n == p->getLeft()){//If n equals p's left node
      g->rotateRight();//g->rotate right
    }
    else{//Anything else
      g->rotateLeft();//g->rotate left
    }
    if (g == root){//If g equals root
      root = p;//Root is p
    }
    p->toggleColor();//Change p's color
    g->toggleColor();//Change g's color
  }
}

void RBT::PrintTree(){//Public PrintTree function
  PrintTree(root, 0);//Call private PrintTree function
}

void RBT::PrintTree(Node* h, int d){//Private PrintTree function
  if (!h){//If not h
    return;//Return
  }
  PrintTree(h->getLeft(), d+1);//Call private PrintTree function with h's left node and d+1
  for (int i = 0; i < d; i++){//For loop looping through until d
    cout<<"    ";//Print out spaces
  }
  cout<<(h->isRed() ? "\033[1;31m" : "\033[1;30m")<<h->getKey()<<"\033[0m"<<endl;//If h is red, print the node in red, if it's black, print it in black
  PrintTree(h->getRight(), d+1);//Private PrintTree function with h's right node and d+1
}

void RBT::deleteTree(Node* n){//Delete tree
  if (!n){//If not n
    return;//Return
  }
  deleteTree(n->getLeft());//Delete left side
  deleteTree(n->getRight());//Delete right side
  delete n;//Delete root
}

void RBT::rotateLeft(Node* h){
  Node* newp = h->getRight();
  Node* p = h->getParent();
  if (h == root){
    root = newp;
  }
  h->setRight(newp->getLeft());
  newp->setLeft(h);
  h->setParent(newp);
  if (h->getRight() != NULL){
    h->getRight()->setParent(h);
  }
  if (p != NULL){
    if (h == p->getLeft()){
      p->setLeft(newp);
    }
    else{
      p->setRight(newp);
    }
  }
  newp->setParent(p);
}

void RBT::rotateRight(Node* h){
  Node* newp = h->getLeft();
  Node* p = h->getParent();
  if (h == root){
    root = newp;
  }
  h->setLeft(newp->getRight());
  newp->setRight(h);
  h->setParent(newp);
  if (h->getLeft() != NULL){
    h->getLeft()->setParent(h);
  }
  if (p != NULL){
    if (h == p->getLeft()){
      p->setLeft(newp);
    }
    else{
      p->setRight(newp);
    }
  }
  newp->setParent(p);
}

RBT::~RBT(){//Destructor
  deleteTree(root);//Call deleteTree
}
