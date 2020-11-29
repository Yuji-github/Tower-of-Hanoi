/*
 * c3338047 Yuji Ishikawa 
 * Lstack.h with template
 * This h file write how Stack function works
 * Lstack is basically last in first out 
 */

#ifndef YUJI_LSTACK_H //macrogurad 
#define YUJI_LSTACK_H //macrogurad

#include "DiscString.h"
#include "DiscInt.h"
#include "Node.h"
#include "LinkedList.h"

#include <cstdlib>
#include <iostream>

template <class DiscData>
class LStack
{
    public:
        
        //constructor
        /*
        *Pre-condition: None
        *Post-condition: create LStack  
        */
        LStack();
        
        //constructor
        /*
        *Pre-condition: int value 
        *Post-condition: create linkedList in heap  
        */
        LStack(const DiscData& new_data);
        
        //destructor 
        /*
        *pre-condition: none
        *post-condition: all LinkedLists will be deleted 
        */
        ~LStack();
        
        //push 
        /*
        *pre-condition: need 3 LStacks
        *post-condition: add the original values to the other rods 
        */
        void push(const DiscData& new_data);
        
        //pop 
        /*
        *pre-condition: none
        *post-condition: delete the top node 
        */
        DiscData pop();
        
        //top
        /*
        *pre-condition: none
        *post-condition: get the head/top node value 
        */
        DiscData& top()const;
        
        
        //size 
        /*
        *pre-condition: none
        *post-condition: return the original size to print out
        */
        std::size_t size() const;
        
        //is_empty 
        /*
        *pre-condition: none
        *post-condition: return the linkedList is empty 
        */
        bool is_empty() const;
       
    private:
        //LinkedList is created in heap because heap is faster and more memories  
        LinkedList<DiscData>* list_data;
        std::size_t length;
}; 

#include "LStack.hpp" //for hpp file

#endif //macrogurad 
