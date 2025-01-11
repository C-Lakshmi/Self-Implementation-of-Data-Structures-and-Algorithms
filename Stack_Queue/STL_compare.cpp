#include <iostream>
#include "stack.h"
#include "queue.h"
#include <chrono>
#include <stack>
#include <queue>

using namespace std;
using namespace std::chrono;

// Function to benchmark custom Stack vs STL stack
void stacktime() {
    Stack custom_stack;
    stack<int> stl_stack;
    const int num_operations = 100000; // Increased number of operations

    // Benchmark custom stack push
    auto start = high_resolution_clock::now();
    for (int i = 0; i < num_operations; i++) {
        custom_stack.push(i);
    }
    auto end = high_resolution_clock::now();
    auto duration_custom_push = duration_cast<nanoseconds>(end - start);
    cout << "My Stack Push: " << duration_custom_push.count() << " ns\n";

    // Benchmark STL stack push
    start = high_resolution_clock::now();
    for (int i = 0; i < num_operations; i++) {
        stl_stack.push(i);
    }
    end = high_resolution_clock::now();
    auto duration_stl_push = duration_cast<nanoseconds>(end - start);
    cout << "STL Stack Push: " << duration_stl_push.count() << " ns\n";

    // Benchmark custom stack pop
    start = high_resolution_clock::now();
    while (!custom_stack.isEmpty()) {
        custom_stack.pop();
    }
    end = high_resolution_clock::now();
    auto duration_custom_pop = duration_cast<nanoseconds>(end - start);
    cout << "My Stack Pop: " << duration_custom_pop.count() << " ns\n";

    // Benchmark STL stack pop
    start = high_resolution_clock::now();
    while (!stl_stack.empty()) {
        stl_stack.pop();
    }
    end = high_resolution_clock::now();
    auto duration_stl_pop = duration_cast<nanoseconds>(end - start);
    cout << "STL Stack Pop: " << duration_stl_pop.count() << " ns\n";
}

// Function to benchmark custom Queue vs STL queue
void queuetime() {
    Queue custom_queue;
    queue<int> stl_queue;
    const int num_operations = 100000; // Increased number of operations

    // Benchmark custom queue enqueue
    auto start = high_resolution_clock::now();
    for (int i = 0; i < num_operations; i++) {
        custom_queue.enqueue(i);
    }
    auto end = high_resolution_clock::now();
    auto duration_custom_enqueue = duration_cast<nanoseconds>(end - start);
    cout << "My Queue Enqueue: " << duration_custom_enqueue.count() << " ns\n";

    // Benchmark STL queue enqueue
    start = high_resolution_clock::now();
    for (int i = 0; i < num_operations; i++) {
        stl_queue.push(i);
    }
    end = high_resolution_clock::now();
    auto duration_stl_enqueue = duration_cast<nanoseconds>(end - start);
    cout << "STL Queue Enqueue: " << duration_stl_enqueue.count() << " ns\n";

    // Benchmark custom queue dequeue
    start = high_resolution_clock::now();
    while (!custom_queue.isEmpty()) {
        custom_queue.dequeue();
    }
    end = high_resolution_clock::now();
    auto duration_custom_dequeue = duration_cast<nanoseconds>(end - start);
    cout << "My Queue Dequeue: " << duration_custom_dequeue.count() << " ns\n";

    // Benchmark STL queue dequeue
    start = high_resolution_clock::now();
    while (!stl_queue.empty()) {
        stl_queue.pop();
    }
    end = high_resolution_clock::now();
    auto duration_stl_dequeue = duration_cast<nanoseconds>(end - start);
    cout << "STL Queue Dequeue: " << duration_stl_dequeue.count() << " ns\n";
}

int main() {
    cout << "Stack:\n";
    stacktime();

    cout << "\nQueue:\n";
    queuetime();

    return 0;
}
