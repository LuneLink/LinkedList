/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.hpp
 * Author: LuneLink
 *
 * Created on 28 июля 2016 г., 15:35
 */
#pragma once 

#include "Node.hpp"
#include <iostream>

class LinkedList {
private:
    Node *pHead;
    int size;
    
    void removeNode(Node *node);

public:
    
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    
    void add(int nData);
    void remove(int id);
    int get(int nId);
    void clear();
    void out();
};

