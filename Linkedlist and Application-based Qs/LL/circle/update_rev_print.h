#include <iostream>
using namespace std;
#define ll long long
#include "global.h"

void update(node* head, int index, int length, ll newvalue){
int i=1;
node* curr=head;
while(i<index%length){
curr=curr->next;
i++;
}
curr->data=newvalue;
}

void printLL(node* head){
node* curr=head;
cout<<curr->data<<"->";
curr=curr->next;
while(curr!=head){
cout<<curr->data<<"->";
curr=curr->next;
}
cout<<endl;
}