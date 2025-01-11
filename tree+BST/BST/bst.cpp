#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <string>

#include <climits>
#include <vector>
#include <cmath>

#include "time.h"
#include "bst.h"

using namespace std;

int main() {
    Node* root;
    BST t=BST(nullptr);
    cout<<"Binary Search Tree Implementation: "<<endl;
    root = t.insertNode(nullptr, 1);
    root = t.insertNode(root, 2);
    root = t.insertNode(root, 3);
    root = t.insertNode(root, 4);
    root = t.insertNode(root, 5);
    root = t.insertNode(root, 9);
    root = t.insertNode(root, 6);
    root = t.insertNode(root, 11);

    cout<<"Enter value to insert: ";
    int x;
    cin>>x;
    root = t.insertNode(root, x);

    cout<<"Enter value to delete: ";
    int y;
    cin>>y;
    root = t.deleteNode(root, y);
  
    cout<<"Enter value to search: ";
    int z;
    cin>>z;
    t.searchNode(root, z);

    cout<<"Traversals: preorder, inorder and postorder: "<<endl;
    t.preorderTraversal(root);
    cout<<endl;
   
    t.inorderTraversal(root);
    cout<<endl;
   
    t.postorderTraversal(root);
    cout<<endl;
  
   cout<<"Perform Efficiency comparision of my BST with STL BST? (Y/N)"<<endl;
    char c;
    cin>>c;
     if (c=='Y') timeanalysis();

    cout<<endl;
    free(root);
    return 0;
}
