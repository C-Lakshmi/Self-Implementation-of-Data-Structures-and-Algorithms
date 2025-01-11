#include <iostream>
#include <queue>
#include <chrono>
#include <vector>
#include "Minheap.h"
using namespace std;

void MyMinHeap() {
    int elements[] = {3, 1, 6, 5, 2, 4};
    int len = sizeof(elements) / sizeof(elements[0]);

    MinHeap Heap(elements, len);
    int num_operations = 1000000;

    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 7; i < 7 + num_operations; ++i) {
        Heap.insertNode(i);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    auto insertDuration = chrono::duration_cast<chrono::nanoseconds>(endInsert - startInsert).count();
    cout << "My Heap Insertion Time: " << insertDuration << " ns for " << num_operations << " operations" << endl;
    cout << "Average per insertion: " << static_cast<double>(insertDuration) / num_operations << " ns" << endl;

    int extract_len = len + num_operations;

    auto startExtract = chrono::high_resolution_clock::now();
    for (int i = 0; i < extract_len; ++i) {
        Heap.ExtractMin();
    }
    auto endExtract = chrono::high_resolution_clock::now();
    auto extractDuration = chrono::duration_cast<chrono::nanoseconds>(endExtract - startExtract).count();
    cout << "My Heap Extraction Time: " << extractDuration << " ns for " << extract_len << " operations" << endl;
    cout << "Average per extraction: " << static_cast<double>(extractDuration) / extract_len << " ns" << endl;
}

void STLHeap() {
    priority_queue<int, vector<int>, std::greater<int>> pq;
    const int num_operations = 1000000;

    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 3; i < 3 + num_operations; ++i) {
        pq.push(i);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    auto insertDuration = chrono::duration_cast<chrono::nanoseconds>(endInsert - startInsert).count();
    cout << "STL Priority Queue Insertion Time: " << insertDuration << " ns for " << num_operations << " operations" << endl;
    cout << "Average per insertion: " << static_cast<double>(insertDuration) / num_operations << " ns" << endl;

    auto startExtract = chrono::high_resolution_clock::now();
    for (int i = 0; i < num_operations; ++i) {
        pq.pop();
    }
    auto endExtract = chrono::high_resolution_clock::now();
    auto extractDuration = chrono::duration_cast<chrono::nanoseconds>(endExtract - startExtract).count();
    cout << "STL Priority Queue Extraction Time: " << extractDuration << " ns for " << num_operations << " operations" << endl;
    cout << "Average per extraction: " << static_cast<double>(extractDuration) / num_operations << " ns" << endl;
}

int main() {
    cout << "My MinHeap:" << endl;
    MyMinHeap();

    cout << "\nSTL Priority Queue:" << endl;
    STLHeap();

    return 0;
}