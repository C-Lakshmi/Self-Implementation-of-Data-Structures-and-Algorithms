#include <iostream>
#include "global.h"
using namespace std;
#define ll long long

node* createNode(ll num){
node* nodeptr=(node*)malloc(sizeof(node));
nodeptr->data=num;
nodeptr->next=nullptr;
nodeptr->prev=nullptr;
return nodeptr;
}
node* createDoublyLL(ll arr[],ll i, ll length,node* Prev){
if(i==length) return nullptr;
node* ptr=(node*)malloc(sizeof(node));
ptr->data=arr[i];
ptr->prev=Prev;
ptr->next=createDoublyLL(arr,i+1,length,ptr);
return ptr;
}