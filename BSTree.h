#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <string>
using namespace std;

class BSTree {       
  public:
    BSTree();
    ~BSTree();
    void insert(const string &newString); //inserts node
    void remove(const string &key);  //removes string
    bool search(const string &key) const;
    string largest() const;  //searches largest value in BST
    string smallest() const;  //searches smallest value in BST
    int height(string) const;  //height of tree at given string
    void preOrder() const;  
    void postOrder() const;  
    void inOrder() const;  
    
  private:
    Node *root;
    Node* search(Node* currNode, const string& key) const;
    Node* insert(Node* currNode, const string& newString);
    Node* remove(Node* currNode, const string &key, bool deleteAnyway);
    int height(Node* currNode) const;
    Node* largest(Node* rootNode) const;
    Node* smallest(Node* rootNode) const;      
    void preOrder(Node* rootNode) const;
    void inOrder(Node* rootNode) const;
    void postOrder(Node* rootNode) const;
};

#endif // __BSTREE_H__