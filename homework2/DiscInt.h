/*
 * c338047 Yuji Ishikawa
 * This H file contains int values
 * Discs are  1, 2, 3, 4, 5 
 * The maximum disc is 5 
 */

#ifndef YUJI_DISCINT_H //macroguard
#define YUJI_DISCINT_H //macroguard

#include <cstdlib>
#include <iostream>

class DiscInt
{
    public:
        //constructor 
        /*
        *pre-condition: need at least 1 int value
        *post-condition: create constructors 
        */
        DiscInt(); 
        DiscInt(int& new_data); 
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: all discInt Data will be gone 
        */
        ~DiscInt();
        
        //get the int value 
        /*
        * pre-condition: string value must exist at least 1
        * post-condition: return data (int)
        */
        int getData() const;
        
    private:
       int data; //int is data_type and the data_type name is data 
}; 


/*
 * friend function because this function needs 2 objects to compare 
 * pre-condition: needs 2 objects 
 * post-condition: return true if data2 is bigger
 */
bool operator < (DiscInt& data1, DiscInt& data2); 


/*
 * friend function 
 * pre-condition: nodes and string values
 * post-condition: output the list values
 */
std::ostream& operator << (std::ostream& out, DiscInt& data);

#endif