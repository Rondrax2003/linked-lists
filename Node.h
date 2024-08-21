#ifndef NODE_H
#define NODE_H

class Node{
    friend class List;
    private:
        int data;
        Node* next;
    public:
        Node(int value);
};

class List{
    friend class Node;
    private:

        int size = 0;
        Node* start;
        Node* end;
    public:
        List();
        ~List();
        int getsize();
        void InsertNode(int value);
        void InsertOrdened(int value);
        void deleteNode(int value);
        void showList();
};




#endif