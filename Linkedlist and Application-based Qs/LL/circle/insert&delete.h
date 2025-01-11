#include <iostream>
using namespace std;
#include "global.h"
#define ll long long

void insertNodeAtFirst(node** head, node* ptr){
if (*head == nullptr) {
        ptr->next=ptr; 
        *head = ptr;
}
node* curr=(*head)->next;
while(curr->next!=*head){
curr=curr->next;
}
curr->next=ptr;
ptr->next=*head;
*head=ptr;
length++;
}
void insertNodeAfterIndex(node* head, int index, int length, node* newnode){
int i=1;
node* curr=head;
node* prev=nullptr;
while(i<=index%length){
prev=curr;
curr=curr->next;
i++;
}
newnode->next=curr;
prev->next=newnode;
length++;
}

void deleteNodeAtFirst(node** head){
node* curr=(*head)->next;
while(curr->next!=*head){
curr=curr->next;
}
curr->next=(*head)->next;
*head=(*head)->next;
length--;
}

void deleteNode(node* head, int index, int length){
int i=1;
node* curr=head;
node* prev=nullptr;
while(i<index%length){
prev=curr;
curr=curr->next;
i++;
}
prev->next=curr->next;
length--;
}