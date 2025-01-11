#include <iostream>
using namespace std;
#include "global.h"
#define ll long long

void insertNodeAfterIndex(node*& head, int index, node* newnode) {
    if (index == 0) {
        // Insert at the beginning
        newnode->next = head;
        head = newnode;
        return;
    }

    node* curr = head;
    int i = 0;

    while (i < index - 1 && curr != nullptr) {
        curr = curr->next;
        i++;
    }

    // Handle case where index is out of bounds
    if (curr == nullptr) {
        cout << "Index out of bounds" << endl;
        return;
    }

    newnode->next = curr->next;
    curr->next = newnode;
}

ll deleteNode(node*& head, int index) {
    if (index == 0) {
        // Delete the first node
        ll num = head->data;
        node* temp = head;
        head = head->next;
        delete temp;
        return num;
    }

    node* curr = head;
    node* prev = nullptr;
    int i = 0;

    while (i < index && curr != nullptr) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    // Handle case where index is out of bounds
    if (curr == nullptr) {
        cout << "Index out of bounds" << endl;
        return -1; // Return an error code or handle as needed
    }

    ll num = curr->data;
    prev->next = curr->next;
    delete curr;
    return num;
}