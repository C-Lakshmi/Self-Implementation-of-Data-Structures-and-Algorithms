#include <iostream>
using namespace std;
#include "global.h"
#define ll long long

void insertNodeAtFirst(node** head, node* ptr){
ptr->next=*head;
*head=ptr;
}
void insertNodeAfterIndex(node* head, int index,node* newnode){
int i=1;
node* curr=head;
node* prev=nullptr;
while(i<=index){
prev=curr;
curr=curr->next;
i++;
}
newnode->next=curr;
prev->next=newnode;
}
void deleteNodeAtFirst(node** head){
*head=(*head)->next;
}

void deleteNode(node* head, int index){
int i=1;
node* curr=head;
node* prev=nullptr;
while(i<index){
prev=curr;
curr=curr->next;
i++;
}
prev->next=curr->next;
}