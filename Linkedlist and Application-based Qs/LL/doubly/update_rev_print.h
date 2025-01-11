#include <iostream>
using namespace std;
#define ll long long
#include "global.h"

void update(node* head, int index, ll newvalue){
int i=1;
node* curr=head;
while(i<index){
curr=curr->next;
i++;
}
curr->data=newvalue;
}


void printLL(node* head){
node* curr=head;
while(curr!=nullptr){
cout<<curr->data<<"<->";
curr=curr->next;
}
cout<<"nullptr"<<endl;
}