#include <iostream>
#include "stack.h"
#include "queue.h"
#define ll long long
using namespace std;

int main() {
    Stack o; 
cout<<"Stack Implementation"<<endl;
//Example Usage: 

//For storing address of the instructions to be executed in order-
//instruction at the top of the stack is executed first, then popped, then the next instruction is executed.
//This is used in the stack pointer in computer hardware

//Stack is also used to store recursive calls and programs as activation records(temporary storage-stored in memory till execution of the function is completed). 
//When a function recursively calls functions, they are pushed into the stack on top of the function 1-by-1 in order
//when the call terminates, finally returning a value, the function at the top of the stack returning the value is popped and the value is returned to the previous 
//function that called it and so on, till the stack is empty.

//We have 3 instructions to be executed in order 3-4-5, then they are pushed into the stack in reverse order, and then popped one by one.
    o.push(5);
    o.push(4);
    o.push(3);
    o.print();  
// instruction 3 is executed
    ll popped_num = o.pop();
    cout << "Popped: " << popped_num << endl;
    ll topEl=o.top(); //top private variable and top() method having same name can cause issues
    cout << "Now Top: " << topEl << endl;
    o.print(); 

 //Example usage
 //In a ticketing counter, the passengers, with unique token nos, representing their ids, are standing
 //in a queue to buy the tickets. the passenger at the front, who came first, gets his ticket first, and his tocken no is dequeued from the queue
 //new passengers are enqueued at the back of the queue. Last in will be the last out, last to get the ticket.
cout<<"Queue Implementation"<<endl;
Queue q;
   
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);

//We have 3 passengers who arrived and were enqueued in the order 10-20-30 who want tickets, then they are dequeued in first in first out basis, 10 gets his ticket first, and is dequeued,
//followed by 20, and 30 gets it last.
cout << "Dequeued: " << q.dequeue() << endl;  // Expected output: 10
q.printQueue();  // Expected output: 20 30

    return 0;
}