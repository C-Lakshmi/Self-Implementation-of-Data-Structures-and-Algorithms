#include <iostream>
#define ll long long
using namespace std;
#define MAX_SIZE 100000000

class Stack {
private:
    ll* stack;  
    int topIndex;     

public:
    
Stack(){
        stack = new ll[MAX_SIZE]; 
        topIndex = -1;  
}

    
~Stack(){
        delete[] stack;  
}


bool isEmpty(){
        return topIndex == -1;
}

bool isFull(){
        return topIndex >= MAX_SIZE - 1;
}

  
void push(ll n){
if (!isFull()){
stack[++topIndex] = n;
} 
else{
cout << "Stack is full" << endl;
}
}

ll pop(){
if (!isEmpty()) {
return stack[topIndex--];
} 
else{
cout << "Stack is empty" << endl;
return -1; 
}
}

ll top(){
if (!isEmpty()) {
return stack[topIndex];
} 
else{
cout << "Stack is empty" << endl;
return -1;  // Return an invalid value
}
}

void print(){
for (int i = topIndex; i >= 0; --i) {
cout << stack[i] << " ";
}
cout << endl;
}

};