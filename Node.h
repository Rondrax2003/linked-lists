#ifndef NODE_H
#define NNODE_H

class List{
    int size = 0;
    Node* start;
    Node* newNode = nullptr;

    void NewNode();
    void InsertNode();
};

class Node{
    public:
    int data;
    Node* next;
};


#endif