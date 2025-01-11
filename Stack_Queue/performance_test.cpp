#include "queue.h"
#include "queuewithstack.h"
#include "vector"
#include "stack.h"
#include "stackwithqueue.h"
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void measureStack(int numOperations, vector<double>& times) {
    Stack s;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numOperations; ++i) {
        s.push(i);
    }
    for (int i = 0; i < numOperations; ++i) {
        s.pop();
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    times.push_back(duration.count());
}

void measureStackFromQueue(int numOperations, vector<double>& times) {
    StackUsingQueue s;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numOperations; ++i) {
        s.push(i);
    }
    for (int i = 0; i < numOperations; ++i) {
        s.pop();
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    times.push_back(duration.count());
}
// Function to measure the performance of a Queue
void measureQueue(int numOperations, vector<double>& times) {

Queue q;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numOperations; ++i) {
        q.enqueue(i);
    }
    for (int i = 0; i < numOperations; ++i) {
        q.dequeue();
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    times.push_back(duration.count());
}

// Function to measure the performance of a Queue implemented using stacks
void measureQueueFromStack(int numOperations, vector<double>& times) {
    QueueWithStack q;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numOperations; ++i) {
        q.enqueue(i);
    }
    for (int i = 0; i < numOperations; ++i) {
        q.dequeue();
    }
    auto end = high_resolution_clock::now();
    duration<double, std::micro> duration = end - start;
    times.push_back(duration.count());
}

int main() {
    vector<int> testSizes = {100, 1000, 5000, 10000, 20000};
    vector<double> stackTimes;
    vector<double> stackFromQueueTimes;

    for (int size : testSizes) {
        cout << "Measuring time for size: " << size << endl;
        measureStack(size, stackTimes);
        measureStackFromQueue(size, stackFromQueueTimes);
        
        cout << "Size: " << size << " | Stack Time: " << stackTimes.back() << " µs | StackFromQueue Time: " << stackFromQueueTimes.back() << " µs" << endl;
    }

    ofstream outFile("stack_data.csv");
    outFile << "TestSize,StackTime,StackFromQueueTime\n";
    for (size_t i = 0; i < testSizes.size(); ++i) {
        outFile << testSizes[i] << "," << stackTimes[i] << "," << stackFromQueueTimes[i] << "\n";
    }
    outFile.close();

    int result = system("gnuplot stack_data.gp");
    if (result != 0) {
        std::cerr << "Error running gnuplot for stack_data.gp" << std::endl;
	}
    vector<double> queueTimes;
    vector<double> queueFromStackTimes;

    // Measure performance for different sizes
    for (int size : testSizes) {
        cout << "Measuring time for size: " << size << endl;
        measureQueue(size, queueTimes);
        measureQueueFromStack(size, queueFromStackTimes);
        
        // Print results to terminal
        cout << "Size: " << size << " | Queue Time: " << queueTimes.back() << " µs | QueueFromStack Time: " << queueFromStackTimes.back() << " µs" << endl;
    }

    // Output results to CSV file
    ofstream outFile2("queue_data.csv");
    outFile2 << "TestSize,QueueTime,QueueFromStackTime\n";
    for (size_t i = 0; i < testSizes.size(); ++i) {
        outFile2 << testSizes[i] << "," << queueTimes[i] << "," << queueFromStackTimes[i] << "\n";
    }
    outFile2.close();

	 result = system("gnuplot queue_data.gp");
    if (result != 0) {
        std::cerr << "Error running gnuplot for queue_data.gp" << std::endl;
    }
    return 0;
}

