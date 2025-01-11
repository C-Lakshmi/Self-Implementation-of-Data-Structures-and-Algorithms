#include <iostream>
using namespace std;

class MinHeap{
private:
int size;
int* arr;
public:
MinHeap(int a[], int len){
    arr=  new int[1000000];
    size=len;
    for(int i=0;i<len;i++){
        arr[i]=a[i];
    }
}
~MinHeap() {
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
void MinHeapifyDown(int i){
if(i<0||i>=size){
cout << "Index out of bounds" << std::endl;
return;
}
    int l = Left(i);
    int r = Right(i);
    int smallest = i;

    if(l < size && arr[l] < arr[smallest]){
        smallest = l;
    }

    if(r < size && arr[r] < arr[smallest]){
        smallest = r;
    }

    if(smallest != i){
        swap(arr, i, smallest);
        MinHeapifyDown(smallest); 
    }
}

void Build_Min_Heap(){
    for(int i = (size / 2) - 1; i >= 0; i--){
        MinHeapifyDown(i);
    }
}

void printHeap(void){
for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
void MinHeapifyUp(int index){
if(index<0||index>=size){
cout << "Index out of bounds" << endl;
return;
}
    int i=index;
    while(i>0){
    if(arr[Parent(i)]>arr[i]) swap(arr,Parent(i),i);
    i=Parent(i);
    }
}
void insertNode(int n){
    size++;
    arr[size-1]=n;
    MinHeapifyUp(size-1);
}
void deleteNode(int index){
if(index<0||index>=size){
cout << "Index out of bounds" << std::endl;
return;
}
if(index==size-1){
    size--;
    return;
}
arr[index]=arr[size-1];
size--;
MinHeapifyDown(index);   
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
if(num<arr[Parent(index)]) MinHeapifyUp(index);
else MinHeapifyDown(index);
}

int ExtractMin(void){
if(size == 0){
cout << "Heap is empty" << std::endl;
return -2;
}
    int Min_Element=arr[0];
    deleteNode(0);
    return Min_Element;
}
int FindMin(void){
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
sortedArr[i] = ExtractMin();
}

size = originalSize; 
delete[] arr; 
arr = tempArr;
}
}; 
