#include <iostream>
#include "BSTree.h"
#include <string>
using namespace std;

//default constructor
BSTree::BSTree() { 
    root = nullptr;
}

//destructor 
BSTree::~BSTree() {
    delete root;
}

//mutators
void BSTree::insert(const string &newString){ //inserts item into BST
  root = insert(root, newString);
}
 
void BSTree::remove(const string &key){ //removes item from BST
  root = remove(root, key, false);
}

//Accessors 

bool BSTree::search(const string& key) const { //searches for string in BST and returns true if found
	return search(root, key);
}


string BSTree::largest() const { //returns largest value in BST
    Node* largestValNode = largest(root);
    if (largestValNode == nullptr) {
        return ""; //return empty string is tree is empty
    }
    return largestValNode-> data;
}


string BSTree::smallest() const { //return smallest value in BST
    Node* smallestValNode = smallest(root);
    if (smallestValNode == nullptr) {
        return "";
    }
    return smallestValNode-> data;
}

 
int BSTree::height(string key) const{ //return height of tree at given string
  Node* searchedNode = search(root, key);
  return height(searchedNode);
}


void BSTree::preOrder() const { //recursively traverses BST from root, left, right and prints value of each node
    preOrder(root);
    cout << endl;
}

void BSTree::inOrder() const { //recursively traverses BST from left, root, right and prints value of each node
    inOrder(root);
    cout << endl;
}

void BSTree::postOrder() const { //recursively traverses BST in left, right, root and prints value of each node 
    postOrder(root);
    cout << endl;
}

Node* BSTree::insert(Node* currNode, const string &newString){ //used to insert a new node with a given string value into a binary search tree.
  if (currNode == nullptr){ 
    currNode = new Node;
    currNode -> data = newString;
    currNode -> left = nullptr;
    currNode -> right = nullptr;
    currNode -> count = 1;
    return currNode;
  }
  if (newString < currNode -> data){
    currNode -> left = insert(currNode -> left, newString);
  }
  else if (newString > currNode -> data){ 
    currNode -> right = insert(currNode -> right, newString);
  }
  else { 
    currNode -> count =  currNode -> count + 1;
  }
  return currNode;
}


Node* BSTree::remove(Node* currNode, const string &key, bool deleteAnyway){ //used to remove a node with a given key value from a binary search tree
  if (currNode == nullptr){ //checks if the heap is empty
    return currNode;
  }
  if (key < currNode -> data){ 
    currNode -> left = remove(currNode -> left, key, false);
  }
  else if (key > currNode -> data){
    currNode -> right = remove(currNode -> right, key, false);
  }
  else{ 
    if (!deleteAnyway && currNode -> count > 1){
      currNode -> count =  currNode -> count - 1;
    }
    else{
                 
      if (currNode -> left == nullptr && currNode -> right == nullptr){ 
        delete currNode;
        currNode = nullptr;
      }  
      else if(currNode -> left != nullptr){ 
        Node* maxNode = largest(currNode -> left);
        currNode -> data = maxNode -> data;
        currNode -> count = maxNode -> count;
        currNode -> left = remove(currNode -> left, maxNode -> data, true);
      }
      else { 
        Node* minNode = smallest(currNode -> right);
        currNode -> data = minNode -> data;
        currNode -> count = minNode -> count;
        currNode -> right = remove(currNode -> right, minNode -> data, true);
      }
    }
  }
  return currNode;
}


Node* BSTree::search(Node* currNode, const string &key) const { //used to search for node with a given key value in BST. If node is found, returns a pointer to that node
  if(currNode != nullptr) { 
      if(key == currNode->data) { 
          return currNode;
      }
      else {
          if(key < currNode->data) { 
              return search(currNode->left, key);
          }
          else { 
              return search(currNode->right, key);
          }
      }
  }
  else { 
      return 0;
  }
}


Node* BSTree::largest(Node* rootNode) const {//used to find the node with the largest value in a given subtree of a BST. If the subtree is empty, returns nullptr
    if (rootNode == nullptr) {
        return nullptr;
    }
    Node* currNode = rootNode;
    while (currNode-> right != nullptr) { 
        currNode = currNode -> right;
    }
    return currNode;
}


Node* BSTree::smallest(Node* rootNode) const {//used to find the node with the smallest value in a given subtree of a binary search tree
    if (rootNode == nullptr) {
        return nullptr;
    }
    Node* currNode = rootNode;
    while (currNode -> left != nullptr) { 
        currNode = currNode -> left;
    }
    return currNode;
}


int BSTree::height(Node* currNode) const { //recursively calculates the height of the left and right subtrees of the current node 
    if (currNode == nullptr) { //checks if heap is empty
        return -1;
    }
    int leftHeight = height(currNode -> left); 
    int rightHeight = height(currNode -> right); 
    if (leftHeight > rightHeight) { 
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}


void BSTree::preOrder(Node* rootNode) const { //recursive function that performs pre-order traversal
    if (rootNode == nullptr) {
        return;
    }
		cout << rootNode -> data << '(' << rootNode -> count << "), ";
    preOrder(rootNode -> left);
    preOrder(rootNode -> right);
}

void BSTree::inOrder(Node* rootNode) const { //recursive function that performs in order traversal
    if (rootNode == nullptr) {
        return;
    }
    inOrder(rootNode-> left);
		cout << rootNode -> data << '(' << rootNode -> count << "), ";
    inOrder(rootNode-> right);
}

void BSTree::postOrder(Node* rootNode) const { //recursive function that performs post-order traversal
    if (rootNode == nullptr) {
        return;
    }
    postOrder(rootNode -> left);
    postOrder(rootNode -> right);
		cout << rootNode -> data << '(' << rootNode -> count << "), ";
}

