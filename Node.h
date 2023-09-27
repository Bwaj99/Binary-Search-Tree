#ifndef _NODE_H_
#define _NODE_H_
#include <string>
using namespace std;

class Node {
public:
  string data; 
  int count; // stores frequency count of data

  //pointer to left and right childs
  Node* left; 
  Node* right;
  Node();
  Node(const string &str); //constructor to initialize
};

#endif