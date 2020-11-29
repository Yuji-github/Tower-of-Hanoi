//c3338047 Yuji Ishikawa

#include "DiscInt.h"

#include <iostream>
#include <cstdlib>


    DiscInt::DiscInt()
    {
        data = 0;
    }
    
    DiscInt::DiscInt(int& new_data)
    {
        switch (new_data)
        {
            case 1: data = 1; 
            break;
            
            case 2: data = 2;
            break; 
            
            case 3: data = 3;
            break;
                   
            case 4: data = 4;
            break;
             
            case 5: data = 5;
            break;
            
            default: data = 0;
        }
    }
    
    DiscInt::~DiscInt()
    {
        data = 0;
    }
    
    int DiscInt::getData() const
    {
        return data;
    }
    
    bool operator < (DiscInt& data1, DiscInt& data2)
    {
        if(data1.getData() < data2.getData())
        {
            return true; 
        }
        else 
        {
            return false; 
        }
    }
    
    std::ostream& operator << (std::ostream& out, DiscInt& data)
    {
        out <<"    " << data.getData() << "    " ; 
        
        return out; 
    }