#include "DiscString.h"
#include "DiscInt.h"
#include "Node.h"
#include "LinkedList.h"
#include "LStack.h"
        
#include <string> // store string value 
#include <iostream> //output and input functions
#include <cstdlib> //c standard library functions 

template <class DiscData>
LStack<DiscData>::LStack()
{
    list_data = new LinkedList<DiscData>();
    length = 0;
}

template <class DiscData>
LStack<DiscData>::LStack(const DiscData& new_data)
{
    list_data = new LinkedList<DiscData>(new_data); 
    length = 1;
}

template <class DiscData>
LStack<DiscData>::~LStack()
{
    //memory leaks might be occur 
    delete list_data; 
}

template <class DiscData>
void LStack<DiscData>::push(const DiscData& new_data)
{
    list_data->add_to_head(new_data);
    length++;
}

template <class DiscData>
DiscData LStack<DiscData>::pop()
{   
    length--; 
    return list_data->remove_from_head();
}

template <class DiscData>
DiscData& LStack<DiscData>::top() const
{
    return list_data->get_head_Data();
}

template <class DiscData>
std::size_t LStack<DiscData>::size() const
{
    return list_data->size();
}

template <class DiscData>
bool LStack<DiscData>::is_empty() const
{
    if(list_data->size() == 0)
    {
        return true;
    }
    return false; 
}



