#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <set>
#include <cmath>

#include "bst.h"

using namespace std;

void timeanalysis(){
    set <int> s;
    int n=10000;

    std::chrono::time_point<std::chrono::system_clock> sins, eins;
    sins = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) s.insert(i);
    eins = std::chrono::system_clock::now();
       
    set<int>::iterator it;
    
    std::chrono::time_point<std::chrono::system_clock> sfind, efind;
    sfind = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) it = s.find(rand()%(n-1));
    efind = std::chrono::system_clock::now();
    
    std::chrono::time_point<std::chrono::system_clock> sdel, edel;
    sdel = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) s.erase(i);
    edel = std::chrono::system_clock::now();
    
    BST b=BST(nullptr);
    Node* root=nullptr;
    std::chrono::time_point<std::chrono::system_clock> s_ins, e_ins;
    s_ins = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) root = b.insertNode(root, i);
    e_ins = std::chrono::system_clock::now();
   
    std::chrono::time_point<std::chrono::system_clock> s_find, e_find;
    s_find = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) b.searchNode(root, i);
    e_find = std::chrono::system_clock::now();
    
    
    std::chrono::time_point<std::chrono::system_clock> s_del, e_del;
    s_del = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) root = b.deleteNode(root, i);
    e_del = std::chrono::system_clock::now();

        float myinsert =
        chrono::duration_cast<chrono::nanoseconds>(eins - sins).count();
        myinsert *= 1e-9;

        float mydelete =
        chrono::duration_cast<chrono::nanoseconds>(edel - sdel).count();
        mydelete *= 1e-9;

        float myfind =
        chrono::duration_cast<chrono::nanoseconds>(efind - sfind).count();
        myfind *= 1e-9;
    
        float insert =
        chrono::duration_cast<chrono::nanoseconds>(e_ins - s_ins).count();
        insert *= 1e-9;

        float Delete =
        chrono::duration_cast<chrono::nanoseconds>(e_del - s_del).count();
        Delete *= 1e-9;

        float find =
        chrono::duration_cast<chrono::nanoseconds>(e_find - s_find).count();
        find *= 1e-9;

        cout<<setprecision(9);
        cout<<"SUMMARY for Binary Search Tree:"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"TIME TAKEN: "<<endl;
    cout<<"STL set (Binary Balanced search Tree): "<<endl;
        
    cout<<"Insert: "<<myinsert*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Search: "<<myfind*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Delete: "<<mydelete*10e5<<" (in 10e5 sec)"<<endl;
    
    cout<<endl;
    
    cout<<"Self Implemented (Binary Search Tree): "<<endl;

    cout<<"Insert: "<<insert*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Search: "<<find*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Delete: "<<Delete*10e5<<" (in 10e5 sec)"<<endl;

}