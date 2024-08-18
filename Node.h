#ifndef NODE_H
#define NNODE_H

class List{
    private:

        int size = 0;
        Node* start;
    public:
        List();
        ~List();
        int getsize();
        void InsertNode(int value);
        void InsertOrdened(int value);
        void showList();
};

class Node{
    friend class List;
    private:
        int data;
        Node* next;
    public:
        Node(int value);
        ~Node();
};


#endif