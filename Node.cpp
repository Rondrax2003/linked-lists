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
        Node* current = this->start;
        Node* newNode = new Node(value);
        while(current->next->data < value )
        {
            current= current->next;
        }
        if(current->next->data > value){
            newNode->next = current->next;
            current->next = newNode;
            size++;
            current = nullptr;
            delete current;
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
    else
    {
        Node* current = this->start;
        Node* tmp= nullptr;
        while(current->next != nullptr)
        {
            if (this->start->data == value && current == this->start)//if the value is in start
            {
                this->start= this->start->next;
                current->next = nullptr;
                cout<< "the"<< current->data << "has deleted"<<endl;
                delete current;
                size--;
            }else if(current->next == this->end && current->next->data == value)// if the value is in the end
            {
                tmp = this->end;
                this->end = current;
                this->end->next = nullptr;
                cout<< "the "<< tmp->data << " has deleted"<<endl;
                delete tmp;
                size--;
            }else if(current->next->data == value) //if the value isn't at start or at the end;
            {
                tmp = current->next;
                current->next = tmp->next;
                tmp->next = nullptr;
                cout<< "the "<< tmp->data << " has deleted"<<endl;
                delete tmp;
                size--;  
            }else{
                current=current->next;
                if(current->next == nullptr)
                {
                cout <<"this value not foun in the list"<<endl;
                delete(current);
                }
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
/*note block
this section will ne sed for registrer codes can be useful:
*/