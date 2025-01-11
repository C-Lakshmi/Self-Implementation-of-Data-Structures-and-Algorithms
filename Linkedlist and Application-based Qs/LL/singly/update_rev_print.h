#include <iostream>
using namespace std;
#define ll long long
#include "global.h"

void update(node* head, int index, ll newvalue){
int i=1;
node* curr=head;
while(i<index && curr!=nullptr){
curr=curr->next;
i++;
}
curr->data=newvalue;
}

node* Reverse(node* head){
node* NEXT;
node* curr=head;
node* prev=nullptr;
while(curr!=nullptr){
NEXT=curr->next;
curr->next=prev;
prev=curr;
curr=NEXT;
}
return prev;
}
node* ReverseRecur(node* prev, node* curr){
if(curr==nullptr) return prev;
node* NEXT;
NEXT=curr->next;
curr->next=prev;
return ReverseRecur(curr, NEXT);
}

node* ReverseLLRecur(node* curr){
if(curr->next==nullptr||curr==nullptr) return curr;
node* reverseHead=ReverseLLRecur(curr->next);
node* NEXT;
NEXT=curr->next;
NEXT->next=curr;
//curr->next->next=curr; more compact
curr->next=nullptr;
return reverseHead;
}
void printLL(node* head){
node* curr=head;
while(curr!=nullptr){
cout<<curr->data<<"->";
curr=curr->next;
}
cout<<"nullptr"<<endl;
}