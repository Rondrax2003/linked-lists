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
    Node* current = start;
    if(this->start == nullptr){
        InsertNode(value);
    }else if(start->data > value){
        Node* newNode = new Node(value);
        if(newNode->data < current->next->data){
            newNode->next = current->next;
            current->next = newNode;
            current = nullptr;
            delete current;
            cout<< newNode->data <<endl;
            this->size++;
        }else if(end->next == newNode){
            end = newNode;
            size++;
            cout<< newNode->data <<endl;
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
        for(current = this->start ;current->next != nullptr;current=current->next){
            if(current == this->start){
                this->start->next= this->start;
                current->next = nullptr;
                delete(current);
                size--;
            }else if(current->next == this->end){
                this->end = current;
                current = current->next;
                current->next = nullptr;
                delete (current);
            }else if(current->data == value){
                Node* tmp;
                for(tmp=this->start;tmp->next != current;tmp = tmp->next);
                tmp->next = current->next;
                current->next = nullptr;
                delete(current);
                tmp->next=nullptr;
                delete (tmp);
                size--;
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