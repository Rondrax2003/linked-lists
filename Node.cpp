#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int value){
    this->data = value;
    this->next = nullptr;
}

List::List(){
    this->start = nullptr;
    this->end = nullptr;
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

    if(this->start == nullptr){
        this->start = newNode;
        this->end = newNode;
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

    if(this->start == nullptr || value < this->start->data){
        InsertNode(value);
    }else if(this->end->data< value){
        Node* newNode = new Node(value);
        this->end->next = newNode;
        this->end = newNode;
        size++;
    }else{
        Node* current = this->start;
        if(current->next->data > value){
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
            size++;
            current = nullptr;
            delete (current);
        }else{
            current = current->next;
        }
    }
}

int List::getsize(){
    return this->size;

}

void List::deleteNode(int value){
    if(this->start == nullptr){
        cout<<"void list"<<endl;
    }
    else{
        Node* current;
        if(current == this->start){
                this->start->next= this->start;
                current->next = nullptr;
                delete(current);
                size--;
            }else{
            for(current = this->start ;current->data != value;current=current->next){
                if(current == this->start){
                    this->start = this->start->next;
                    current->next= nullptr;
                    delete (current);
                    size--;
                }else if (current == this->end){
                    Node* tmp;
                    for(tmp = this->start; tmp->next != current; tmp=tmp->next);
                    this->end=tmp;
                    this->end->next = nullptr;
                    delete(current);
                    tmp=nullptr;
                    delete(tmp);
                    size--;
                }else{
                    Node* tmp;
                    for(tmp = this->start; tmp->next != current; tmp=tmp->next);
                    tmp->next = current->next;
                    current->next = nullptr;
                    delete(current);
                    tmp=nullptr;
                    delete(tmp);
                    size--;
                }
                
            }
        }
    }
}
/*
void List::showList(){
    Node* printer = this->start;
    while (printer != nullptr)
    {
        cout<<this->data<<",";
    }
    
}*/