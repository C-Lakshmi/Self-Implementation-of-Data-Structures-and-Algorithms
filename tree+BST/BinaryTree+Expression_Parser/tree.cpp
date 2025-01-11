#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <queue>
#include <climits>
#include <vector>
#include <cmath>
#include "parser.h"
#include "tree.h"
using namespace std;

int main(){
Node* root;
    Tree t=Tree(nullptr);
    cout<<"Binary Tree Implementation: "<<endl;
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

while(1){
        //Expression Evaluation
        cout<<"Welcome to Expression Parser program:"<<endl;
        cout<<endl;
        cout<<"Enter your expression (LHS) without spaces containing single digits, + , * , / , - : "<<endl;
        string str;
        cin>>str;
        int n;
        
        cout<<"Enter RHS: ";
        cin>>n;
        int value=evaluateExpression(str);
        if (n==value) cout<<"LHS=RHS. It follows BODMAS. RHS is correct."<<endl;
        else cout<<"LHS is not equal to RHS. It does not follow BODMAS."<<endl<<"Correct value is: "<<value<<endl;
        
        cout<<"Try for another expression: (Y/N) ";
        char cb;
        cin>>cb;
        if (cb=='N') break;
    }

    free(root);
    return 0;
}