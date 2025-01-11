#include <iostream>
using namespace std;
#define ll long long
class node{
private:
long long data;
node* next;
node(): next(nullptr) {}

node* createNode(ll num){
node* nodeptr=(node*)malloc(sizeof(node));
nodeptr->data=num;
nodeptr->next=nullptr;
return nodeptr;
}
node* createLL(ll arr[], ll length){
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
int search(node* head, ll num){
int i=1;
node* curr=head;
while(curr->data!=num && curr!=nullptr){
curr=curr->next;
i++;
}
if(curr==nullptr) return -1;
else return i;
}
void printLL(node* head){
node* curr=head;
while(curr!=nullptr){
cout<<curr->data<<"->";
curr=curr->next;
}
cout<<"nullptr"<<endl;
}
};