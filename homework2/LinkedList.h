/*
 * c338047 Yuji Ishikawa
 * This H file contains 2 templates class
 * DiscInt and DiscString 
 */

#ifndef YUJI_LINKEDLIST_H //macrogurad 
#define YUJI_LINKEDLIST_H //macrogurad

#include "DiscInt.h"
#include "DiscString.h"
#include "Node.h"

#include <cstdlib>
#include <iostream>

template <class DiscData>
class LinkedList
{
   public:
       
        //constructor
        /*
        *Pre-condition: None
        *Post-condition: create LinkedList  
        */
        LinkedList(); //default constructor 
        
        /*
        * pre-condition: None
        * post-condition: store data value
        */
        LinkedList(const DiscData& new_data); //overloading constructor 
        
        //destructor 
        /*
        *pre-condition: at least 1 node existing 
        *post-condition: all nodes are gone and length is 0
        */
        ~LinkedList(); 
        
        /*
         * Pre-condition: string value 
         * post-condition: connecting first nodes to others "... the black floor the dog"
         */
        void add_to_head(const DiscData& new_data);
        
        /*
         * Pre-condition: string value 
         * post-condition: connecting last nodes to others "the black floor the dog..."
         */
        void add_to_tail(const DiscData& new_data); //adding list 2 to list 1 tail
		
	 /*
         * pre-condition: none
         * post-condition: current moves to head
         */
        void move_to_head(); //pointer point at head 
        
        /*
         * pre-condition: none
         * post-condition: current moves to tail
         */
        void move_to_tail();
        
        //support functions not using this time / if you see some warning signs just ignore it as they did not called in this time 
        
        /*
         * pre-condition: None
         * post-condition: remove a node from head
         */
        DiscData remove_from_head(); 
        
        /*
         * pre-condition: None
         * post-condition: remove a node from head
         */
        DiscData remove_from_tail(); 
        
        /*
         * pre-condition: None
         * post-condition: return head node value
         */
        DiscData& get_head_Data() const;
        
        /*
         * pre-condition: None
         * post-condition: return current node value
         */
        DiscData& get_current_data() const;
        
        /*
         * pre-condition: None
         * post-condition: move to forward 
         */
        void forward(); 
        
        //+=operator overloading 
        /*
         * Pre-condition: string value 
         * post-condition: connecting last word of list 1 and first word of list 2 "the black floor the dog..."
         */
        void operator +=(LinkedList& list2); //connecting list 2 sentence to list 1
        
        /*
         * pre-condition: none
         * post-condition: get list length information  
         */
        std::size_t size(); //get list length size 
        
        private:
        Node<DiscData>* head;
        Node<DiscData>* tail;
        Node<DiscData>* current;

        std::size_t length;
};

/*
 * friend function this is only my friend in Australia MUST BE NICE, OKAY!!!
 * pre-condition: nodes and string values
 * post-condition: output the list values
 */

template<class DiscData>
std::ostream& operator <<(std::ostream& out, LinkedList<DiscData>& list); //operator for <<

#include "LinkedList.hpp"

#endif //macrogurad