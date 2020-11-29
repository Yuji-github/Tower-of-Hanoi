/*
 * c3338047 Yuji Ishikawa 
 * TowerHanoi.h with template
 * This h file write how to control LStack
 * create in stack
 */

#ifndef YUJI_TOWERHANOI_H //macrogurad 
#define YUJI_TOWERHANOI_H //macrogurad

#include "DiscString.h"
#include "DiscInt.h"
#include "Node.h"
#include "LinkedList.h"
#include "LStack.h"

#include <cstdlib>
#include <iostream>
using namespace std;

template <class DiscData>
class TowerHanoi
{
    public: 
        
        //constructor
        /*
        *Pre-condition: None
        *Post-condition: create TowerHanoi  
        */
        TowerHanoi(); 
        
        //constructor
        /*
        *Pre-condition: int value 
        *Post-condition: create nodes(DiscString or DiscInt) at most 5  
        */
        TowerHanoi(const int new_data); 
        
        //destructor 
        /*
        *pre-condition: none
        *post-condition: all TowerHanoi value is erasing by pop function
        */
        ~TowerHanoi();
        
        //move 
        /*
        *pre-condition: need from and to values from the main 
        *post-condition: if TO value is bigger than FROM then from node can add to the top
        */
        void move(const int rodfrom, const int rodTo); 
        
        
        //checkWin 
        /*
        *pre-condition: need 3 LStacks
        *post-condition: if rodOne and rodTwo are empty, return true
        */
        bool checkWin() const;
        
        
        //push_TowerHanoi 
        /*
        *pre-condition: need 3 LStacks
        *post-condition: add the original values to the temp rods to print out
        */
        void push_TH(const DiscData& new_data, int rodNum);
        
        //pop_TowerHanoi 
        /*
        *pre-condition: need 3 LStacks
        *post-condition: pop 3 rods 
        */
        DiscData pop_TH(int rodNum);
        
        //top_TowerHanoi 
        /*
        *pre-condition: need 3 LStacks
        *post-condition: get the head/top node value 
        */
        DiscData& top_TH(int rodNum) const;
        
        //size 
        /*
        *pre-condition: none
        *post-condition: return the original size to print out
        */
        bool is_empty_TH(int rod) const;
    
    private: 
        //pointers because LinkedList and Node are created in heap
        LStack<DiscData>* rodOne; 
        LStack<DiscData>* rodTwo; 
        LStack<DiscData>* rodThree; 
};


/*
 * friend function
 * pre-condition: pop_TH, push_TH, top_TH need here 
 * post-condition: print upside down
 */
template <class DiscData>
std::ostream& operator << (std::ostream& out, TowerHanoi<DiscData>& tower);

#include "TowerHanoi.hpp" //for hpp file

#endif //macroguard