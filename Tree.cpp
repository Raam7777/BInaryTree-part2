#include <iostream>
#include <cstdlib>

#include "Tree.hpp"

using namespace std;


ariel::Tree::Tree(){
     T_root = NULL;
}

ariel::Tree::~Tree(){
  remove_Tree(T_root);
}

void ariel::Tree::remove_Tree(node* n){
  if(n != NULL){
    if(n->left != NULL){
      remove_Tree(n->left);
    }
    if(n->right != NULL){
      remove_Tree(n->right);
    }
    delete n;
  }
}

ariel::Tree::node* ariel::Tree::createLeaf(int i){

  node* new_node = new node;
  new_node->data = i;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

void ariel::Tree::insert(int i){
  if(contains(i)){
    throw "the number exists";
  }
  insertNode(i,T_root);
}

void ariel::Tree::insertNode(int i, node* ptr){
  if(T_root == NULL){
    T_root = createLeaf(i);
  }
  else if(i < ptr->data){
    if(ptr->left != NULL){
      insertNode(i,ptr->left);
    }
    else{
      ptr->left = createLeaf(i);
    }
  }
  else if(i > ptr->data){
    if(ptr->right != NULL){
      insertNode(i,ptr->right);
    }
    else{
      ptr->right = createLeaf(i);
    }
  }
}

void ariel::Tree::print(){
   printInOrder(T_root);
}

void ariel::Tree::printInOrder(const struct node *ptr){
  if(T_root != NULL){
    if(ptr->left != NULL)
      printInOrder(ptr->left);
    cout << ptr->data << " ";
    if(ptr->right != NULL)
      printInOrder(ptr->right);
  }
  else{
    throw "The tree is empty";
  }
 }

 int ariel::Tree::findSmallest(){
    return findSmallestNode(T_root);
 }

int ariel::Tree::findSmallestNode(node* ptr){
  if(T_root == NULL){
    throw "The tree is empty";
  }

  if(ptr->left != NULL){
    return findSmallestNode(ptr->left);
  }

  return  ptr->data;
}


void ariel::Tree::remove(int i){
  if(!contains(i)){
    throw "the number does not exist";
  }
   removeNode(i,T_root);
}

void ariel::Tree::removeNode(int i, struct node *ptr){
  if(T_root != NULL){
    if(T_root->data == i){
      removeRootMatch();
    }
    else{
      if(i < ptr->data && ptr->left != NULL){
        ptr->left->data == i ? removeMatch(ptr, ptr->left, true) : removeNode(i, ptr->left);
      }
      else if(i > ptr->data && ptr->right != NULL){
        ptr->right->data == i ? removeMatch(ptr, ptr->right, true) : removeNode(i, ptr->right);
      }
    }
  }
}

void ariel::Tree::removeRootMatch(){
  if(T_root != NULL){
    node* delPtr = T_root;
    int rootData = T_root->data;
    int smallestData;

    if(T_root->left == NULL && T_root->right == NULL){
      T_root = NULL;
      delete delPtr;
    }
    else if(T_root->left == NULL && T_root->right != NULL){
      T_root = T_root->right;
      delPtr->right = NULL;
      delete delPtr;
    }
    else if(T_root->left != NULL && T_root->right == NULL){
      T_root = T_root->left;
      delPtr->left = NULL;
      delete delPtr;
    }
    else{
      smallestData = findSmallestNode(T_root->right);
      removeNode(smallestData, T_root);
      T_root->data = smallestData;
    }
  }
}


void ariel::Tree::removeMatch(node* parent, node* match, bool left){
  if(T_root != NULL){
    node* delPtr;
    int matchData = match->data;
    int smallestData;

    if(match->left == NULL && match->right == NULL){
      delPtr = match;
      left == true ? parent->left = NULL : parent->right =NULL;
      delete delPtr;
    }
    else if(match->left == NULL && match->right != NULL){
      left == true ? parent->left = match->right : parent->right = match->right;
      match->right = NULL;
      delPtr = match;
      delete delPtr;
    }
    else if(match->left != NULL && match->right == NULL){
      left == true ? parent->left = match->left : parent->right = match->left;
      match->left = NULL;
      delPtr = match;
      delete delPtr;
    }
    else{
      smallestData = findSmallestNode(match->right);
      removeNode(smallestData, match);
      match->data = smallestData;
    }
  }
}
int ariel::Tree::size(){
  return T_size(T_root);
}

int ariel::Tree::T_size(node* n){
  if(n == NULL){
    return 0;
  }
  return (T_size(n->left) + 1 + T_size(n->right));
}

bool ariel::Tree::contains(int i){
  node* current = contains_node(i,T_root);
  if(current==NULL){
    return false;
  }
  return true;
}

ariel::Tree::node* ariel::Tree::contains_node(int i, node* n){
  if(n != NULL){
    if(n->data == i){
      return n;
    }
    else{
      if(i < n->data){
        return contains_node(i,n->left);
      }
      else{
        return contains_node(i,n->right);
      }
    }
  }
  return NULL;
}

int ariel::Tree::root(){
  if(T_root==NULL){
    throw "The tree is empty";
  }
  return T_root->data;
}

int ariel::Tree::parent(int i)
{
    Node* current=contains_node(i,tree_root);
    if (current==tree_root)
    {
        throw "The root has no parent";
    }
    Node* parent=find_parent(i,tree_root);
    return parent->value;
}
 /*
 A function that receives a value and node, 
 return this node parent
*/    
 ariel::Tree:: Node* ariel::Tree::find_parent(int i, Node* n)
 {
   
     if (n == NULL)
     {
       return NULL;
     }

    if(n->left == NULL && n->right == NULL)
    {
       return NULL;
    }

    if( (n->left != NULL && n->left->value == i)|| (n->right != NULL && n->right->value == i))
    {
       return n;
    }

    if(n->value > i)
    {
       return find_parent(i,n->left);
    }

    if(n->value < i)
    {
       return find_parent(i,n->right);
    }

    return NULL;
}

int ariel::Tree::left(int i){
  node *current = contains_node(i,T_root);
  if(current->left == NULL){
    throw "to the leaf no left children";
  }
  return current->left->data;
}

int ariel::Tree::right(int i){
  node *current = contains_node(i,T_root);
  if(current->right == NULL){
    throw "to the leaf no right children";
  }
  return current->right->data;
}
