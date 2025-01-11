#include <iostream>
#include "global.h"
using namespace std;
#define ll long long

node* createNode(ll num){
node* nodeptr=(node*)malloc(sizeof(node));
nodeptr->data=num;
nodeptr->next=nullptr;
return nodeptr;
}
//Recursive implementation
node* createSinglyLLrecursive(ll arr[],ll i, ll length){
if(i==length) return nullptr;
node* ptr=(node*)malloc(sizeof(node));
if (ptr == nullptr) {
        cerr << "Memory allocation failed" << endl;
        exit(1);
    }
ptr->data=arr[i];
ptr->next=createSinglyLLrecursive(arr,i+1,length);
return ptr;
}
//Iterative implementation
node* createSinglyLLiterative(ll arr[], ll length){
    node* head=createNode(arr[0]);
    node* currentNode=head;
for(int i=1;i<length;i++){
node* ptr=(node*)malloc(sizeof(node));
currentNode->next=ptr;
ptr->data=arr[i];
currentNode=currentNode->next;
}
currentNode->next=nullptr;
return head;
}