#include <iostream>
#include <utility>
using namespace std;

class HashNode {
public:
int key;
int value;
HashNode* next;
HashNode(int Key, int Value) : key(Key), value(Value), next(nullptr) {}
};

class Hash {
private:
int num;
int size;
int funcMod;
HashNode** table; //an array of pointers to the hashnodes table[i]=HashNode*=ptr to a Hashnode
int hashfunction(int key) {
return key % funcMod;
}
public:
Hash(int SIZE,int Mod) {
num=0;
size=SIZE;
funcMod=Mod;
table = new HashNode*[size]; 
for (int i = 0; i < size; ++i) {
table[i] = nullptr;
}
}
~Hash() {
for (int i = 0; i < size; ++i) {
HashNode* current = table[i];
while (current != nullptr) {
HashNode* temp = current;
current = current->next;
delete temp;
}
}
delete[] table;
}

void insert(int key, int value) {
int index = hashfunction(key);

HashNode* newNode = new HashNode(key, value);

if (table[index] == nullptr) {
table[index] = newNode;
num++;
} 
else{
HashNode* current = table[index];

while (current != nullptr) {

if (current->key == key) {
    // if the key already exists, it updates the value of that key
    current->value = value;
    delete newNode;
    return;
}
if(current->next==nullptr) break;
current = current->next;
}
if(current==nullptr){
    current=newNode;
    return;
}
//creating a new node after the last node= newNode
if(current->next==nullptr){
current->next = newNode;
num++;
}
}
}

void deleteKey(int key) {
int index = hashfunction(key);

HashNode* current = table[index];
HashNode* prev = nullptr;
while (current != nullptr) {

if (current->key == key){
if (prev == nullptr) { //for 1st node
table[index] = current->next;
num--;
} 
else { //any other node
prev->next = current->next; 
}
delete current;
num--;
return;
}
prev = current;
current = current->next;
}
}

bool containsKey(int key) {
    int index = hashfunction(key);
    HashNode* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int get(int key) {
int index = hashfunction(key);
HashNode* current = table[index];

while (current != nullptr) {
if (current->key == key) {
return current->value;
}
current = current->next;
}
return -1;
}
int numOfElements(void){
    return num;
}
void search(int value){
    int cnt=0;
for(int i=0;i<size;i++){
HashNode* current = table[i];
int j=0;
while (current != nullptr) {
if(current->value==value){
    cout<<"bucket index: "<<"("<<i<<","<<j<<")"<<"   ";
    cout<<"key: "<<current->key<<endl;
    cnt=1;
}
current=current->next;
j++;
}
}
if(!cnt) cout<<"NOT FOUND"<<endl;
}

void display() {
for (int i = 0; i < size; ++i) {
if (table[i] != nullptr) {
cout << "Index " << i << ": ";
HashNode* current = table[i];
while (current != nullptr) {
cout << "(" << current->key << " : " << current->value << ") -> ";
current = current->next;
}
cout << "end"<<endl;
}
}
}
};