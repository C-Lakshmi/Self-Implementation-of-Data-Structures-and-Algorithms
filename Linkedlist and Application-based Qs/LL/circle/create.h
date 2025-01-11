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
node* createcircularLL(ll arr[], ll length){
node* head=createNode(arr[0]);
node* currentNode=head;
for(int i=1;i<length;i++){
node* ptr=(node*)malloc(sizeof(node));
currentNode->next=ptr;
ptr->data=arr[i];
currentNode=currentNode->next;
}
currentNode->next=head;
return head;
}