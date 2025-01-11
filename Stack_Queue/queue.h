#include <iostream>
#define ll long long
using namespace std;

class Queue {
private:
    int front;
    int Back;
    int Size;
    ll* arr;
    
public:
Queue(){
Size = 100000000;
arr = new ll[Size];
front = -1;
Back = 0;
}

~Queue(){
delete[] arr;
}

void enqueue(ll el) {
if (front == Back) {
cout << "Queue is full" << endl;
return;
}
if (front == -1) {
front = 0;
}
arr[Back] = el;
Back = (Back + 1) % Size;
}

ll dequeue() {
if (front == -1) {
cout << "Queue is empty" << endl;
return -1;
}
ll el = arr[front];
if (front == Back) {
front = -1;
Back = 0;
} 
else{
front = (front + 1) % Size;
}
return el;
}

bool isEmpty() const {
return front == -1;
}

bool isFull(){
return Back == front;
}

void printQueue(){
if (isEmpty()) {
cout << "Queue is empty" << endl;
return;
}
int i = front;
while (true) {
cout << arr[i] << " ";
i = (i + 1) % Size;
if (i == Back) break;
}
cout << endl;
}
};