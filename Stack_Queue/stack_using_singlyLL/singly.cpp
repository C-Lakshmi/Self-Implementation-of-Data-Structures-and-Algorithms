#include <iostream>
#include "global.h"
#include "create.h"
#include "insert&delete.h"
#include "traverse_search.h"
#include "update_rev_print.h"
using namespace std;
#define ll long long

//IMPLEMENTATION OF STACK USING LL
class StackWithLL{
private: node *stack;
int index;
public: 
StackWithLL(): stack(nullptr), index(0) {}
bool isEmpty(void){
    return stack==nullptr;
}
void push(ll n) {
node* NewNode=createNode(n);
insertNodeAfterIndex(stack,index,NewNode);
++index;
}
ll pop(void){
    if (index <= 0) {
            cout << "Stack underflow!" << endl;
            return -1; // Or handle it via an exception
        }
  ll data= deleteNode(stack,index-1);
  --index;
  return data;
}
ll top(void){
    if (index <= 0) {
            cout << "Stack underflow!" << endl;
            return -1; // Or handle it via an exception
        }
return traverseANDreturndata(stack,index);
}
void print(void){
    printLL(stack);
}
};

int main() {
StackWithLL o;
o.push(5);
o.push(4);
o.push(3);
o.print();
ll popped_num = o.pop();
cout << "Popped: " << popped_num << endl;
o.print();
ll top_El=o.top();
cout<< "Top: "<<top_El<<endl;
cout<<endl;
o.push(2);
o.print();

top_El=o.top();
cout<< "Now Top: "<<top_El<<endl;

o.push(4);
o.push(7);
o.print();
top_El=o.top();
cout<< "Now Top: "<<top_El<<endl;
popped_num=o.pop();
cout << "Popped: " << popped_num << endl;
o.print();


return 0;
}