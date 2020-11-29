/*
 * c3338047 Yuji Ishikawa 
 * LinkedList.cpp
 * This class write how LinkedList function works
 * LinkedList is basically pointing at node 
 */

#include "LinkedList.h"
#include "Node.h"
#include "DiscString.h"
#include "DiscInt.h"
        
#include <string> // store string value 
#include <iostream> //output and input functions
#include <cstdlib> //c standard library functions 
#include <cassert>

//public functions

//constructor section
template <class DiscData>
LinkedList<DiscData>::LinkedList()
{
    head = NULL; 
    tail = NULL;
    length = 0; 
}

template <class DiscData>
LinkedList<DiscData>::LinkedList(const DiscData& new_data)
{
    if (head == NULL)
    {
        Node<DiscData>* new_node = new Node<DiscData>(new_data); 
        head = new_node; 
        length = 1;
    }
    else
    {
        Node<DiscData>* new_node = new Node<DiscData>(new_data);
        tail = new_node; 
        length = 1;
    }
}

//destruct the linked-list data 
template <class DiscData>
LinkedList<DiscData>::~LinkedList()
    {
        while(tail != NULL)
        {
            remove_from_tail();
        } 
        tail = NULL; 
        head = NULL; 
        current = NULL;
    }

template<class DiscData>
void LinkedList<DiscData>::add_to_head(const DiscData& new_data)
{
    /*
     * This function is to add Nodes to LinkedList head     
     */
    
    if(length == 0)
        {
            head = new Node<DiscData>(new_data);
            tail = head;
            current = tail;
            length = 1; 
        }
        else
        {
            Node<DiscData>* temp = new Node<DiscData>(new_data); //current is on head
            temp -> setNext(head); //set Next to extra Node from temp
            head -> setPrev(temp); //set Previous to head from extra Node
            head = temp; //head moves to extra Node
            length++; 
            temp = NULL;
        }
}

template<class DiscData>
void LinkedList<DiscData>::add_to_tail(const DiscData& new_data) 
{
    /*
     * This function is to add Nodes to LinkedList tail     
     */
    
    if(length == 0)
        {
            head = new Node<DiscData>(new_data);
            tail = head;
            current = tail;
            length = 1; 
        }
        else
        {
                Node<DiscData>* temp = new Node<DiscData>(new_data); //current is on tail 
                tail -> setNext(temp); //set Next to extra Node from tail 
                temp -> setPrev(tail); //set Previous to tail from extra Node
                tail = temp; //tail moves to extra Node
                length++; 
                temp = NULL;
        }
}

template<class DiscData>
void LinkedList<DiscData>::move_to_head() 
{
    /*
     * this function current moves to head  
     */
    
    current = head;
}

template<class DiscData>
void LinkedList<DiscData>::move_to_tail()
{
    /*
    * this function current moves to tail  
    */
    
    current = tail;
}


template<class DiscData>
DiscData LinkedList<DiscData>::remove_from_head()
{
    /*
     * this function delete node from node 
     */
    
    assert(length != 0);
        
    if (length == 1)
    {
        Node<DiscData>* temp = head;
        tail = NULL; 
        head = NULL;
        length--;
        return temp->getData();
    }
    else
    {
        //step 1 create temp to point at the original head point
        Node<DiscData>* temp = head; 

        //step 2 moving tail-point to tail_temp
        head = temp -> getNext();

        //step 3 decrease node_count 
        length--; 

        return temp->getData();
    }
}

template<class DiscData>
DiscData LinkedList<DiscData>::remove_from_tail()
{
    /*
     * this function delete node from node 
     */
    
    assert(length != 0);
       
    
    if (length == 1)
    {
        Node<DiscData>* temp = tail;
        tail = NULL; 
        head = NULL;
        length--;
        return temp->getData();
    }
    else
    {
        //step 1 create temp to point at the original tail point
        Node<DiscData>* temp = tail; 

        //step 2 moving tail-point to tail_temp
        tail = temp -> getPrev(); //tail is previous from temp

        //step 3 decrease node_count 
        length--; 

        return temp->getData();
    }
}

// += operator 
template<class DiscData>
void LinkedList<DiscData>::operator +=(LinkedList<DiscData>& list2)
{
    /*
     * This function is to connect between Node and Node LinkedList  
     */
    
    list2.move_to_head(); //list2 is set on head 
    int stop = list2.size(); //list 2 length size 10
    for (int count = 0; count < stop; count++)
    {
        this->add_to_tail(list2.get_current_data());
        list2.forward();
    }
    list2.move_to_head(); //just in case to set to the head
}

template<class DiscData>
std::size_t LinkedList<DiscData>::size()
{
    /*
     * this function get list size 
     */
    
    return length; 
}

template<class DiscData>
DiscData& LinkedList<DiscData>::get_head_Data() const
{
    return head -> getData();
}

template<class DiscData>
DiscData& LinkedList<DiscData>::get_current_data() const
{
    /*
     * This function is to get current string value
     */
    
    return current -> getData();
} 

template<class DiscData>
void LinkedList<DiscData>::forward() 
{
    /*
     * this function current moves to forward 
     */
    
    current = current -> getNext(); //current ->getCurrent()
}

//friend function 
template<class DiscData>
std::ostream& operator <<(std::ostream& out, LinkedList<DiscData>& list)
{
    /*
     * this function is outputting Node (string) values from each list
     */
    
    list.move_to_head(); 
    int stop = list.size();
   
    for (int count = 0; count < stop; count++)
    {
        out << list.get_current_data() + " "; 
           list.forward();
    }  
    
    list.move_to_head(); //just in case to set the head
    return out;
}