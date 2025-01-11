#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "global.h"
#include "create.h"
#include "insert&delete.h"
#include "traverse_search.h"
#include "update_rev_print.h"
using namespace std;
#define ll long long

void myLLOperations(){
//EXAMPLE:
/*CONSIDER TRAFFIC SIGNALS numbered from 1 to 10 on 3 or 5 different routes from Mumbai to Pune
Doubly Linkedlists help in controlling/redirecting both to and fro traffic in the most efficient manner, 
especially useful for one-way routes
Based on the signals that have less traffic, or newer shortcuts or flyovers added, signals are inserted or deleted from the route
Linkedlists are used in route/traffic navigation.
*/
ll num1=6,num2=7;
int index=3;
ll findnum=7;
ll newvalue=9;

ll a[]={1,2,3,4,5};
node* head=createDoublyLL(a,0,5,nullptr); //creates the 1st node
printLL(head);

node* newNode= createNode(num1); 
insertNodeAtFirst(&head,newNode); //1 1 2 3 4 5
printLL(head);

newNode=createNode(num2);
insertNodeAfterIndex(head,index,newNode); //Say 1st node=index 1=> inserting after nth node // 1 1 2 7 3 4 5
printLL(head);

deleteNodeAtFirst(&head); //1 2 7 3 4 5
printLL(head);

deleteNode(head,index-1); //delete nth node //1 7 3 4 5
printLL(head);

int searchindex=search(head,findnum); // returns index=-1 if data not found, else returns the index where it is found
cout<<searchindex<<endl; //2
update(head,index,newvalue); //1 7 9 4 5
printLL(head); //correctly prints 1 7 9 4 5

}
void STLOperations() {
    ll num1 = 6, num2 = 7;
    int index = 3;
    ll findnum = 7;
    ll newvalue = 9;

    list<ll> lst = {1, 2, 3, 4, 5};
    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;
    lst.push_front(num1); //insertNodeAtFirst  // 6 1 2 3 4 5
    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;
    auto it = lst.begin();
    advance(it, index); //it points to (index)th element starting from beginning- 0 based indexing 
    lst.insert(it, num2); //insertNodeAfterIndex  // 6 1 2 7 3 4 5
    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;

    lst.pop_front(); //deleteNodeAtFirst // 1 2 7 3 4 5
    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;
    it = lst.begin();
    advance(it, index-2); //deletes (index-1)th node= beginning el+ (index-2)th position
    lst.erase(it); //delete nth node // 1 7 3 4 5
    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;

    it = find(lst.begin(), lst.end(), findnum);
    int searchindex = distance(lst.begin(), it);
    if (it != lst.end()) {
        cout << searchindex + 1 << endl; // change from 0 to 1 based indexing
    } else {
        cout << "-1" << endl;
    }

    it = lst.begin();
    advance(it, index - 1);
    *it = newvalue; //update

    for (auto x : lst) cout << x << "<->";
    cout <<"nullptr"<< endl;

}


int main() {
    // Measure time for custom linked list operations
    clock_t start = clock();
    myLLOperations();
    clock_t end = clock();
    double duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
    cout << "Time taken for my doubly linked list operations: " << duration << " seconds" << endl;

    // Measure time for STL linked list operations
    start = clock();
    STLOperations();
    end = clock();
    duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
    cout << "Time taken for STL doubly linked list operations: " << duration << " seconds" << endl;

    return 0;
}
