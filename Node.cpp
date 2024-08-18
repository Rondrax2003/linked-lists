#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int value){
    this->data = value;
    this->next = nullptr;
}

List::List(){
    this->start = nullptr;
    this->size = 0;
}
List::~List(){
    Node* current = this->start;
    while(current !=nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}
void List::InsertNode(int value){

    Node* newNode = new Node(value);

    if(start == nullptr){
        this->start = newNode;
        size++;
        cout<< newNode->data <<endl;
    }else{
        newNode->next = this->start;
        this->start = newNode;
        size++;
        cout<< newNode->data <<endl;
    }
}

void List::InsertOrdened(int value){
    Node* current = this->start;
    if(start == nullptr){
        InsertNode(value);
    }else if(start->data > value){
        InsertNode(value);
    }else {
        Node* newNode = new Node(value);
        if(newNode->data < current->next->data){
            newNode->next = current->next;
            current->next = newNode;
            this->size++;
            current = nullptr;
            delete current;
            cout<< newNode->data <<endl;
        }
    }

}

int List::getsize(){
    cout<< this->size<<endl;
}
/*
void List::showList(){
    Node* printer = this->start;
    while (printer != nullptr)
    {
        cout<<this->data<<",";
    }
    
}*/