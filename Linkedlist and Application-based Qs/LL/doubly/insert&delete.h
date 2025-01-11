#include <iostream>
using namespace std;
#include "global.h"
#define ll long long

void insertNodeAtFirst(node** head, node* ptr){
ptr->next=*head;
(*head)->prev=ptr;
*head=ptr;
}
void insertNodeAfterIndex(node* head, int index,node* newnode){
int i=1;
node* curr=head;
//node* prev=nullptr;
while(i<=index && curr!=nullptr){
//prev=curr;
curr=curr->next;
i++;
}
newnode->next=curr;
newnode->prev=curr->prev;
(curr->prev)->next=newnode;
curr->prev=newnode;
}

void deleteNodeAtFirst(node** head){
*head=(*head)->next;
(*head)->prev=nullptr;
}

void deleteNode(node* head, int index){
int i=1;
node* curr=head;
//node* prev=NULL;
while(i<index && curr!=nullptr){
//prev=curr;
curr=curr->next;
i++;
}
(curr->prev)->next=curr->next;
(curr->next)->prev=curr->prev;
}
