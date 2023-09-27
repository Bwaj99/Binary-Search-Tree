#include <iostream>
#include <limits>
#include "BSTree.h"
using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
  BSTree tree;
  int choice = menu();
  string entry;
  
  while (choice != 8) {
    if (choice == 1) {
      cout << "Enter string to insert: " << endl;
      getline(cin, entry);
      tree.insert(entry); //inserts string as value of new node in binary search tree
    } 
    else if (choice == 2) {
      cout << "Enter string to remove: " ;
      getline(cin, entry);
      tree.remove(entry);
      cout << endl; //if input is 2, removes string
    } 
    else if (choice == 3) {
      printOrders(&tree); //prints nodes if input is 3
    }
    else if (choice == 4) {
      cout << "Enter string to search for: " << endl;
      getline(cin, entry);
      if(tree.search(entry)){
        cout << "Found" << endl;
      }
      else{
        cout << "Not Found" << endl;
      } //searches for specific string within a node if inout is 4
    } 
    else if (choice == 5) {
      cout << "Smallest: " ;
          cout << tree.smallest() << endl; //outputs smallest node
    } 
    else if (choice == 6) {
      cout << "Largest: ";
      cout << tree.largest() << endl; //returns largest node
    } 
    else if (choice == 7) {
      cout << "Enter string: " << endl;
      getline(cin, entry); //user enters string to act as root
      cout << "Height of subtree rooted at " << entry << ": ";
      cout << tree.height(entry);
      cout << endl; // returns the height of the subtree rooted at the node that contains the specified string in the binary search tree
    }
    
    //fix buffer just in case non-numeric choice entered
    choice = menu();
}
return 0;
}