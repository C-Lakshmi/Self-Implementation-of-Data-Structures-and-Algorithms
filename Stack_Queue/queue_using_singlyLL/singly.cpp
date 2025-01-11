#include <iostream>
#include "global.h"
#include "create.h"
#include "insert&delete.h"
#include "traverse_search.h"
#include "update_rev_print.h"
using namespace std;
#define ll long long

//IMPLEMENTATION OF STACK USING LL
class QueueWithLL{
private: node * q;
int front;
int back;
public: 
QueueWithLL(): q(nullptr), front(-1), back(0) {}

bool isEmpty(void){
    return q==nullptr;
}

void enqueue(ll n) {
node* NewNode=createNode(n);
insertNodeAfterIndex(q,back,NewNode);
front=0;
back++;
}

ll dequeue(void){
    if (isEmpty()) return -1;
  ll data= deleteNode(q,front);
  back--;
  return data;
}

void print(void){
    printLL(q);
}
};

int main() {
QueueWithLL o;
 o.enqueue(5); 
    o.enqueue(4);
    o.print();  
    o.enqueue(3); 
    o.print();  
    ll dequeued_num = o.dequeue();
    cout << "Dequeued: " << dequeued_num << endl;
    o.print(); 
    o.enqueue(5); 
    o.print();
    dequeued_num = o.dequeue();
    cout << "Dequeued: " << dequeued_num << endl;
    o.print();
    
return 0;
}