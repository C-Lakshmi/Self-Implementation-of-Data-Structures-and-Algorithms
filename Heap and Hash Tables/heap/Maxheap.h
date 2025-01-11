#include <iostream>
using namespace std;

class MaxHeap{
private:
int size;
int* arr;
public:
MaxHeap(int a[], int len){
    arr=  new int[1000000];
    size=len;
    for(int i=0;i<len;i++){
        arr[i]=a[i];
    }
}
~MaxHeap() {
    delete[] arr;
}

int Parent(int i){
if(i<0||i>=size){
cout << "Index out of bounds" << std::endl;
return -2;
}
if(i!=0) return (i-1)/2;
else return -1;
}
int Left(int i){
if(i<0||i>=size){
cout << "Index out of bounds" << std::endl;
return -2;
}
return 2*i+1;
}
int Right(int i){
if(i<0||i>=size){
cout << "Index out of bounds" << std::endl;
return -2;
}   
return 2*i+2;
}
void swap(int arr[],int i,int j){
if(i<0||i>=size||j<0||j>=size){
cout << "Index out of bounds" << std::endl;
return;
}
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void MaxHeapifyDown(int i){
if(i<0||i>=size){
cout << "Index out of bounds" << std::endl;
return;
}
    int l = Left(i);
    int r = Right(i);
    int largest = i;

    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }

    if(r < size && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr, i, largest);
        MaxHeapifyDown(largest); // Recursively heapify the affected subtree
    }
}

void Build_Max_Heap(){
    for(int i = (size / 2) - 1; i >= 0; i--){
        MaxHeapifyDown(i);
    }
}

void printHeap(void){
for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
void MaxHeapifyUp(int index){
if(index<0||index>=size){
cout << "Index out of bounds" << std::endl;
return;
}
    int i=index;
    while(i>0){
    if(arr[Parent(i)]<arr[i]) swap(arr,Parent(i),i);
    i=Parent(i);
    }
}
void insertNode(int n){
    size++;
    arr[size-1]=n;
    MaxHeapifyUp(size-1);
}

void deleteNode(int index){
if(index<0||index>=size){
cout << "Index out of bounds" <<endl;
return;
}
if(index==size-1){
    size--;
    return;
}
arr[index]=arr[size-1];
size--;
MaxHeapifyDown(index);   
}

int search(int num){
for(int i=0;i<size;i++){
    if(arr[i]==num) return i;
}
return -1;
}

int update(int index,int num){
if(index<0||index>=size){
cout << "Index out of bounds" << std::endl;
return -2;
}
arr[index]=num;
if(num>arr[Parent(index)]) MaxHeapifyUp(index);
else MaxHeapifyDown(index);
}

int ExtractMax(void){
if(size <= 0){
cout << "Heap is empty" << std::endl;
return -2;
}
    int Max_Element=arr[0];
    deleteNode(0);
    return Max_Element;
}

int FindMax(void){
if(size == 0){
cout << "Heap is empty" << std::endl;
return -2;
}
    return arr[0];
}

void HeapSort(int * sortedArr){

int* tempArr = new int[size];

for (int i = 0; i < size; i++) {
tempArr[i] = arr[i];
}

int originalSize = size;

for (int i = 0; i < originalSize; i++) {
sortedArr[i] = ExtractMax();
}


delete[] arr; // free the current array as it is empty
arr = tempArr;
size = originalSize; 
}
};

