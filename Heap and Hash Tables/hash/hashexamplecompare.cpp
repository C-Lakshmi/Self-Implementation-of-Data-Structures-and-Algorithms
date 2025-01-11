#include <iostream>
#include <unordered_map>
#include <chrono>
#include <vector>
#include "hash.h"
using namespace std;

void testMyHash(Hash& H, int numElements) {
    for (int i = 0; i < numElements; ++i) {
        H.insert(i, i * 10);
    }
    for (int i = 0; i < numElements; ++i) {
        H.get(i);
    }
}

void testSTLHash(unordered_map<int, int> stlHash, int numElements) {
    for (int i = 0; i < numElements; ++i) {
        stlHash[i] = i * 10;
    }
    for (int i = 0; i < numElements; ++i) {
        stlHash[i];
    }
    
}


void comparePerformance(int numElements) {
    Hash H(numElements,numElements);
    unordered_map<int, int> stlHash;

    auto startCustom = chrono::high_resolution_clock::now();
    testMyHash(H, numElements);
    auto endCustom = chrono::high_resolution_clock::now();

    auto startSTL = chrono::high_resolution_clock::now();
    testSTLHash(stlHash, numElements);
    auto endSTL = chrono::high_resolution_clock::now();

    chrono::duration<double> customDuration = endCustom - startCustom;
    chrono::duration<double> stlDuration = endSTL - startSTL;

    cout << "My Hash Table Time: " << customDuration.count() << " seconds" << endl;
    cout << "STL Unordered Map Time: " << stlDuration.count() << " seconds" << endl;
}

int main() {
    int numElements = 1000000; // Number of elements to test
    comparePerformance(numElements);
    cout<<endl;
    //EXAMPLE:
    //Consider Student IDs to be mapped to Marks on a Maths Test
    //Student IDs(KEYS): 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015
    //Corresponding Scores(VALUES): 90, 85, 78, 92, 88, 76, 95, 89, 91, 84, 67, 69, 54, 13, 78
    //hash function mod10
    Hash o=Hash(15,10);
    o.insert(1001,90);
    o.insert(1002, 85);
    o.insert(1003, 78);
    o.insert(1004, 92);
    o.insert(1005, 88);
    o.insert(1006, 76);
    o.insert(1007, 95);
    o.insert(1008, 89);
    o.insert(1009, 91);
    o.insert(1010, 84);
    o.insert(1011, 67);
    o.insert(1012, 69);
    o.insert(1013, 54);
    o.insert(1014, 13);
    o.insert(1015, 78);

    o.display();
    cout<<endl;
    int marks1013=o.get(1013);
    cout<<"marks of student with ID 1013: "<<marks1013<<endl;
    int marks1009=o.get(1009);
    cout<<"marks of student with ID 1009: "<<marks1009<<endl;
    cout<<"IDs of student with marks 78: ";
    o.search(78);
    cout<<"IDs of student with marks 84: ";
    o.search(84);

    cout<<"IDs of student with marks 100: ";
    o.search(100);
    o.deleteKey(1014);
    o.numOfElements();
    if(!o.containsKey(1018)){
        o.insert(1018,100);
    }
    o.display();
    return 0;
}
