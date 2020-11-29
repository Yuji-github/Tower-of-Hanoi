/*
 * c3338047 Yuji Ishikawa 
 * Node.hpp
 * To connect to #include "Node.h" 
 * To write functions which I mentioned on Node.h 
 * Node:: for return functions
 */   

#include "Node.h" 
#include <string>
#include <cstdlib>
#include <iostream>

//constructor section 
template <class DiscData>
Node<DiscData>::Node()
{
    next = NULL; 
    prev = NULL; 
    data = NULL;
}

template <class DiscData>
Node<DiscData>::Node(const DiscData& new_data, Node<DiscData>* new_next, Node<DiscData>* new_prev) //don't know why we need Node<DiscData>* in hpp
{
    next = new_next; 
    prev = new_prev;         
    data = new_data;
}

template <class DiscData>
Node<DiscData>::~Node()
{
    next = NULL; 
    prev = NULL;
    data = NULL;
}

template <class DiscData>
void Node<DiscData>::setNext(Node<DiscData>* new_next) 
{
    next = new_next;
}

template <class DiscData>
void Node<DiscData>::setPrev(Node<DiscData>* new_prev)
{
    prev = new_prev;
}

template <class DiscData>
void Node<DiscData>::setData(const DiscData& new_data)
{
    data = new_data;
}

template <class DiscData>
const Node<DiscData>* Node<DiscData>::getNext() const
{
    return next;
}

template <class DiscData>
Node<DiscData>* Node<DiscData>::getNext() 
{
    return next;
}

template <class DiscData>
const Node<DiscData>* Node<DiscData>::getPrev() const
{
    return prev;
}

template <class DiscData>
Node<DiscData>* Node<DiscData>::getPrev() 
{
    return prev;
}

template <class DiscData>
DiscData& Node<DiscData>::getData() 
{
    return data;
}

template <class DiscData>
DiscData Node<DiscData>::getData() const
{
    return data;
}