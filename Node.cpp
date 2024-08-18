#include "Node.h"
#include <iostream>
using namespace std;

void List::NewNode(){
    int Value;

    cout<<"enter a value: ";
    cin>>Value;

    Node* newNode = new Node();
    newNode->data = Value;
    newNode->next = nullptr;
}

void List::InsertNode(){
    if(start == nullptr){
        NewNode();
        start = newNode;
        size++;
    }
}