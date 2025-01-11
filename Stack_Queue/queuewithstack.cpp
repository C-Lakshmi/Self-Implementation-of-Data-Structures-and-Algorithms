#include <iostream>
#include <stack>
#define ll long long
using namespace std;
//Queue= FIFO
class QueueWithStack{
private:
stack <ll> st; //LIFO
stack <ll> q;

public:
bool isEmpty(){
    return st.empty() && q.empty();
}
void enqueue(ll n){
st.push(n); //5 4 //insert into stack and create reverse stack for pop
// st= 0
}
// q= 5

ll dequeue(void){  
if(q.empty()){
if(st.empty()) return -1;
while(!st.empty()){
ll topEl=st.top(); 
q.push(topEl); 
st.pop();   
}
}
ll el=q.top(); 
q.pop(); 
return el;
}

void print(void){
stack <ll> temp=q;
while(!temp.empty()){
ll topEl=temp.top(); //2
temp.pop();
cout<<topEl<<" ";
}
stack<ll> tempStRev;
stack<ll> tempSt = st; // We need to reverse stack1's order
while (!tempSt.empty()){
tempStRev.push(tempSt.top());
tempSt.pop();
}
while (!tempStRev.empty()) {
cout << tempStRev.top() << " ";
tempStRev.pop();
}
cout << endl;
return;
}

};

int main() { 
QueueWithStack o;
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