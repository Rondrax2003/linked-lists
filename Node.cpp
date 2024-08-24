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
  
    }else{
        newNode->next = this->start;
        this->start = newNode;
        size++;
    }
}

void List::InsertOrdened(int value)
{
    if(this->start == nullptr || value < this->start->data)
    {
        InsertNode(value);
    }else if(this->end->data< value){
        Node* newNode = new Node(value);
        this->end->next = newNode;
        this->end = newNode;
        size++;
    }else{
        Node* current;
        for(current= this->start;current->next->data > value; current = current->next)
        {
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
            size++;
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
    else
    {
        Node* current;
        for(current = this->start ;current->data != value;current=current->next)
        {
            if (current == this->start && this->start->data == value)
            {
                this->start->next= this->start;
                current->next = nullptr;
                cout<< "the"<< current->data << "has deleted"<<endl;
                delete(current);
                size--;
            }else if(current == this->end && this->end->data == value)
            {
                Node* tmp;
                for(tmp = this->start; tmp->next != this->end; tmp=tmp->next);
                this->end = tmp;
                this->end->next = nullptr;
                cout<< "the"<< current->data << "has deleted"<<endl;
                delete(current);
                tmp=nullptr;
                delete(tmp);
                size--;
            }else if(current->data == value)
            {
                Node* tmp;
                for(tmp = this->start; tmp->next != current; tmp=tmp->next);
                tmp->next = current->next;
                current->next = nullptr;
                cout<< "the"<< current->data << "has deleted"<<endl;
                delete(current);
                tmp=nullptr;
                delete(tmp);
                size--;
            }else if(current == this->end && current->data != value)
            {
                cout<< "the value value "<< value <<" isn't not found in the list"<<endl;
                current = nullptr;
                delete (current);
            }
        }
    }
}

void List::showList(){
    Node* printer;
    for(printer = this->start;printer != nullptr; printer = printer->next)
    {
        cout<< printer->data<<endl;
    }
}