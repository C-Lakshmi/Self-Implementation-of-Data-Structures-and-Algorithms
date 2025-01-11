#include <iostream>
#include <queue>
#include "stackwithqueue.h"
#define ll long long
using namespace std;

int main() {
    StackUsingQueue stack;

    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.print();  // Print stack contents

    ll top_num = stack.top();
    cout << "Top: " << top_num << endl;

    stack.pop();
    cout << "After pop: ";
    stack.print();  // Print stack contents after pop

    return 0;
}