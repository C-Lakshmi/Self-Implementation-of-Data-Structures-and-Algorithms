#include <iostream>
using namespace std;
#define ll long long

int traverseANDreturnlength(Node* head){
if(head==nullptr) return 0;
int i=1;
node* curr=head;
while(curr!=nullptr){
curr=curr->next;
i++;
}
return i;  
}
int search(Node* head, ll num){
int i=1;
node* curr=head;
while(curr->data!=num && curr!=nullptr){
curr=curr->next;
i++;
}
if(curr==nullptr) return -1;
else return i;
}