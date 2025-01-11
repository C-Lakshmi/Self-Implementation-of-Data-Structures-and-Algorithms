#include <iostream>
using namespace std;
#define ll long long

int traverseANDreturnlength(node* head){
if(head==nullptr) return 0;
if(head->next==head) return 1;
int i=1;
node* curr=head->next;
while(curr!=head){
curr=curr->next;
i++;
}
return i;  
}
int search(node* head, ll num){
int i=2;
if(head->data==num) return 1;
node* curr=head->next;
while(curr->data!=num && curr!=head){
curr=curr->next;
i++;
}
if(curr==head) return -1;
else return i;
}