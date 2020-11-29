//c3338047 Yuji Ishikawa 

#include "DiscString.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

    DiscString::DiscString()
    {
        data = "";
    }
    
    DiscString::DiscString(int new_data)
    {
        switch(new_data)
        {
            case 1: data = "X"; 
            break;
            
            case 2: data = "XXX";
            break; 
            
            case 3: data = "XXXXX";
            break;
                   
            case 4: data = "XXXXXXX";
            break;
             
            case 5: data = "XXXXXXXXX";
            break;
            
            default: data = "";
        }
    }
    
    DiscString::~DiscString()
    {
        data = "";
    }
    
    string DiscString::getData() const
    {
        return this->data;
    }

    bool operator < (DiscString& data1, DiscString& data2)
    {
        if(data1.getData().length() < data2.getData().length())
        {
            return true; 
        }
        else 
        {
            return false; 
        }
    }
    
    std::ostream& operator << (std::ostream& out, DiscString& data)
    {
        //just for print out nicely not necessary for this 
        //return out << data.getData();
        
        switch(data.getData().length())
        {
            case 1: out << "    X    "; 
            break;
            
            case 3: out << "   XXX  ";
            break; 
            
            case 5: out << "  XXXXX  ";
            break;
                   
            case 7: out << " XXXXXXX ";
            break;
             
            case 9: out << "XXXXXXXXX";
            break;
            
            default: out << "";
        }
        
        return out; 
    }