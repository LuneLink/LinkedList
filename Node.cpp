/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Node.cpp
 * Author: LuneLink
 *
 * Created on 28 июля 2016 г., 16:46
 */

#include "Node.hpp"

Node::Node(int data) {
    pNext = 0;
    this->data = data;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

int Node::get() {
    return this->data;
}

void Node::set(int data) {
    this->data = data;
}