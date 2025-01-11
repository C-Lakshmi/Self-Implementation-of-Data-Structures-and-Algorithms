#include <iostream>
#include <queue>
#define ll long long
using namespace std;

class StackUsingQueue {
private:
    queue<ll> q; //FIFO

public:

    void push(ll x) {
        q.push(x);

        
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q.pop();
    }

    
    ll top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q.empty();
    }

    // Print the contents of the stack
    void print() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<ll> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};