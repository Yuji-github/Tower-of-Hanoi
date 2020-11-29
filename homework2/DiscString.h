/*
 * c338047 Yuji Ishikawa
 * This H file contains string values
 * if disc is 1 x, 2 = xxx, 3 = xxxxx, 4 = xxxxxxx and so on
 * The maximum disc is 5 
 */

#ifndef YUJI_DISCSTRING_H //macroguard
#define YUJI_DISCSTRING_H //macroguard

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class DiscString
{
    public: 
        
        //constructor 
        /*
        *pre-condition: need at least 1 int value
        *post-condition: create constructors 
        */
        DiscString();
        DiscString(int new_data); 
        
        //destructor
        /*
        *pre-condition: none
        *post-condition: all DiscString Data will be gone 
        */
        ~DiscString();
        
        //get the string value 
        /*
        * pre-condition: string value must exist at least 1
        * post-condition: return data (string)
        */
        string getData() const;
        
    private:
        string data; 
}; 

/*
 * friend function because this function needs 2 objects to compare  
 * pre-condition: needs 2 objects 
 * post-condition: return true if data2 is bigger
 */
bool operator < (DiscString& data1, DiscString& data2); 

/*
 * friend function 
 * pre-condition: nodes and string values
 * post-condition: output the list values
 */
std::ostream& operator << (std::ostream& out, DiscString& data);

#endif //macroguard
