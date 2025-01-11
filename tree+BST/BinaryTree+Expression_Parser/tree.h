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
using namespace std;

class Node {
    public:
    int val;
    struct Node *left, *right;
    Node(): left(nullptr), right(nullptr) {}
};

class Tree {
private: Node* root;
public:
Tree(Node* Root) {
    root=Root;
}
Node* createNode(int item) {
    Node* temp = new Node;
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout<<root->val<<" ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}

Node* insertNode(Node* node, int value) {
    if(root==nullptr){
       //creates a new node
       root =new Node();
       root->val=value;
       return root ;
    }
    else{
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* tempq = q.front();
            q.pop();
            if(tempq->left==nullptr){
                tempq->left = new Node();
                tempq->left->val=value;
                break;
            }
            else{
                q.push(tempq->left);
            }
            if(tempq->right==nullptr){
                tempq->right=new Node();
                tempq->right->val=value;
                break;
            }
            else{
                q.push(tempq->right);
            }
        }
        return root;
    }
}

bool searchNode(Node* root, int key) {
    if (root == nullptr) return false;

    //for level order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->val == key) {
            return true;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    return false;
}

Node* DeepestNode(Node* root) {
    queue<Node*> q;
    q.push(root);
    Node* deepest = nullptr;

    while (!q.empty()) {
        deepest = q.front();
        q.pop();

        if (deepest->left != nullptr) {
            q.push(deepest->left);
        }
        if (deepest->right != nullptr) {
            q.push(deepest->right);
        }
    }
    return deepest;
}

//delete the deepest node and 
void deleteDeepestNode(Node* root, Node* deepestNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == deepestNode) {
            current->left = nullptr;
            delete deepestNode;
            return;
        } else if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right == deepestNode) {
            current->right = nullptr;
            delete deepestNode;
            return;
        } else if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    //tree has only one node
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }

    //level order traversal to find the node to delete and deepest node
    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* deepestNode = nullptr;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // we mark the node containing key
        if (current->val == key) {
            keyNode = current;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    if (keyNode != nullptr) {
        //we find the deepest/rightmost leaf node
        deepestNode = DeepestNode(root);
        
        //replacing keyNode value with deepest node value
        keyNode->val = deepestNode->val;
        
        //now we delete the deepest node
        deleteDeepestNode(root, deepestNode);
    }

    return root;
}
};