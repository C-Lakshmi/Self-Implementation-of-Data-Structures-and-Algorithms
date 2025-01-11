#include <bits/stdc++.h>
#include "global.h"
#include "create.h"
#include "insert&delete.h"
#include "traverse_search.h"
#include "update_rev_print.h"
using namespace std;
#define ll long long

int main(){
//EXAMPLE:
/*CONSIDER a MUSIC PLAYLIST with songs numbered from 1 to 10.
Based on the user preference, songs are inserted or deleted or re-ordered from the playlist.
Circular linkedlist will also enable playing the music playlist in a continuous loop.
OR 
for circular route navigation
*/
ll num1=6,num2=7;
int index=3;
ll findnum=7;
ll newvalue=9;
ll a[]={1,2,3,4,5};
length=5;
node* head=createcircularLL(a,5); //creates the 1st node
node* newNode= createNode(num1); 
insertNodeAtFirst(&head,newNode); //1 1 2 3 4 5
printLL(head);
newNode=createNode(num2);
insertNodeAfterIndex(head,index,length,newNode); //Say 1st node=index 1=> inserting after nth node // 1 1 2 7 3 4 5
printLL(head);
deleteNodeAtFirst(&head); //1 2 7 3 4 5
printLL(head);
deleteNode(head,index-1,length); //delete nth node //1 7 3 4 5
printLL(head);
int searchindex=search(head,findnum); // returns index=-1 if data not found, else returns the index where it is found
cout<<searchindex<<endl; //2
cout<<length<<endl;
update(head,index,length,newvalue); //1 7 9 4 5
printLL(head); //correctly prints 1 7 9 4 5
return 0;
}