#include <iostream>
#include "Maxheap.h"
#include "Minheap.h"
using namespace std;

int main() {
    //Example:
    //consider the numbers to be the priority order of CPU instructions to be executed. 
    //priority 1 will be execured before 2 and so on.
    //helps to implement a priority queue
    int arr[] = {1, 2, 5, 3, 9, 4, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    MaxHeap Heap(arr, len);

    Heap.Build_Max_Heap();
    cout << "Max Heap elements: ";
    Heap.printHeap();
    Heap.insertNode(8);
    Heap.insertNode(7);
    cout << "After inserting 8 and 7: ";
    Heap.printHeap();
    cout << "Extracted max: " << Heap.ExtractMax()<< endl;
    cout << "Heap after extracting max: ";
    Heap.printHeap();
    int sortedArr[len + 1];
    Heap.HeapSort(sortedArr);
    cout << "Sorted elements: ";
    for (int i = 0; i < len + 1; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;
    Heap.deleteNode(3);
    Heap.update(2,9);
    cout<<"On deleting 3 and updating 6 to 9:";
    Heap.printHeap();
    cout<<endl;
    int ind=Heap.search(2);
    cout<<"2 is at "<<ind<<"th index"<<endl;
    

    int a[] = {11, 22, 55, 34, 39, 24, 63};
    MinHeap Hp(a, 7);
    Hp.Build_Min_Heap();
    cout << "Min Heap elements: ";
    Hp.printHeap();
    Hp.insertNode(28);
    Hp.insertNode(7);
    cout << "After inserting 28 and 37: ";
    Hp.printHeap();
    cout << "Extracted min: " << Hp.ExtractMin()<< endl;
    cout << "Heap after extracting min: ";
    Hp.printHeap();
    int sortedArr2[9];
    Hp.HeapSort(sortedArr2);
    cout << "Sorted elements: ";
    for (int i = 0; i < 8; i++) {
        cout << sortedArr2[i] << " ";
    }
    cout << endl;
    return 0;
}