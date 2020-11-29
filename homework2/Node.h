/*
 * c338047 Yuji Ishikawa
 * This H file contains 2 templates class
 * DiscInt and DiscString 
 * DiskData is Disk data_type
 * as I duno which objects comes when the user runs this file
 */

#ifndef YUJI_NODE_H //macrogurad 
#define YUJI_NODE_H //macrogurad

#include "DiscInt.h"
#include "DiscString.h"

#include <cstdlib>
#include <iostream>

template <class DiscData>
class Node
{
    public: 
        
        //constructor 
        /*
        *pre-condition: none
        *post-condition: create constructors 
        */
        Node();
        
        //constructor 
        /*
        *pre-condition: int value
        *post-condition: create constructors with loop function 
        */
        Node(const DiscData& new_data = DiscData(), Node* new_next = NULL, Node* new_prev = NULL);
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: all Node will be gone 
        */
        ~Node();
        
        //setter
        /*
         * pre-condition: none
         * post-condition: set the next and previous
         */
        void setNext(Node* new_next);
        void setPrev(Node* new_Prev);
        void setData(const DiscData& new_data);
        
        //getter
        /*
         * pre-condition: data should be stored
         * post-condition: get the next, previous, data value (int or string)
         */
        
        const Node* getNext() const; 
        Node* getNext(); 
        
        const Node* getPrev() const;
        Node* getPrev();
        
        DiscData& getData();
        DiscData getData()const;
        
    private:
        
        DiscData data;
        Node* next;
        Node* prev; 
}; 

#include "Node.hpp"

#endif //macrogurad