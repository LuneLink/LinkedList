#pragma once

class Node {

private: 
    int data;
    
public:
    Node *pNext;
    
    Node(int data);
    Node(const Node& orig);
    virtual ~Node();
    
    int get();
    void set(int nData);
    Node* getNext();
    void setNext(Node &node);
    
};

