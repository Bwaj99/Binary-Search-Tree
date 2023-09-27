#include <iostream>
#include "Node.h"
#include <string>
using namespace std;

Node::Node() {
    data = "";
    left = nullptr;
    right = nullptr;
    count = 0;
}

Node::Node(const string &str) {
    data = str;
    left = nullptr;
    right = nullptr;
    count = 0;
}