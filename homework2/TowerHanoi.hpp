//just in case included the all class for this 
#include "DiscString.h"
#include "DiscInt.h"
#include "Node.h"
#include "LinkedList.h"
#include "LStack.h"
#include "TowerHanoi.h"



#include <string> // store string value 
#include <iostream> //output and input functions
#include <cstdlib>
#include <sstream> //Objects of this class use a string buffer that contains a sequence of characters.


template <class DiscData>
TowerHanoi<DiscData>::TowerHanoi()
{
    rodOne = new LStack<DiscData>();
    rodTwo = new LStack<DiscData>();
    rodThree = new LStack<DiscData>();
}

template <class DiscData>
TowerHanoi<DiscData>::TowerHanoi(const int new_data)
{
    rodOne = new LStack<DiscData>();
    rodTwo = new LStack<DiscData>();
    rodThree = new LStack<DiscData>();
    
    for(int start = new_data; 1 <= start; start--)
    {
        //create a class object<DiscString or DiscInt> class
        DiscData disks = DiscData(start); 
        
        //insert class objects in to the linkedList
        //from 5 -> 4 -> 3 -> 2 -> 1
        rodOne->push(disks);
    }
}

template <class DiscData>
TowerHanoi<DiscData>::~TowerHanoi()
{
    //delete pointer by deleting 
    //memory leaks might be occur here
    delete rodOne; 
    delete rodTwo; 
    delete rodThree; 
}

template<class DiscData>
void TowerHanoi<DiscData>::move(const int rodfrom, const int rodTo)
{
    //move from rodOne
    if(rodfrom == 1 && !rodOne->is_empty()) 
    {
        //the data move to rodTwo
        if(rodTo == 2)
        {
            //is_empty() is first because is_empty () be tested first then compare the 2 tops
            if(rodTwo->is_empty() || rodOne->top() < rodTwo->top())
            {
                rodTwo->push(rodOne->pop());  //add to rodTwo
            }
            else
            {
                cout<<" Invalid Move " << endl; //error
            }
        }
        
        //the data move to rodTwo
        else if(rodTo == 3 )
        {
            if( rodThree->is_empty() || rodOne->top() < rodThree->top())
            {
                rodThree->push(rodOne->pop());
            }
            else
            {
                cout<<" Invalid Move " << endl;
            }
        }
        //other int numbers, do not deal any char, double and so on
        else
        {
                cout<<"Please Input Valid Numbers " << endl;
        }
    }
    
    //move from rodTwo, copy and paste the rodOne ideas
    else if(rodfrom == 2 && !rodTwo->is_empty())
    {
        if(rodTo == 1)
        {
            if(rodOne->is_empty() || rodTwo->top() < rodOne->top())
            {
                rodOne->push(rodTwo->pop());
            }
            else
            {
                cout<<" Invalid Move " << endl;
            }
        }
        else if(rodTo == 3 )
        {
            if(rodThree->is_empty() || rodTwo->top() < rodThree->top())
            {
                rodThree->push(rodTwo->pop());
            }
            else
            {
                cout<<" Invalid Move " << endl;
            }
        }
        else
           {
                cout<<"Please Input Valid Numbers " <<endl;
           }
    }
    
    //move from rodThree, copy and paste the rodOne ideas
    else if(rodfrom == 3 && !rodThree->is_empty())
    {
        if(rodTo == 1)
        {
            if(rodOne->is_empty() || rodThree->top() < rodOne->top())
            {
                rodOne->push(rodThree->pop());
            }
            else
            {
                cout<<" Invalid Move " << endl;
            }
        }
        else if(rodTo == 2)
        {
            if(rodTwo->is_empty() || rodThree->top() < rodTwo->top() )
            {
                rodTwo->push(rodThree->pop());
            }
            else
            {
                cout<<" Invalid Move " << endl;
            }
        }
        else
           {
                cout<<"Please Input Valid Numbers " <<endl;
           }
    }
    
    //else from numbers are not 1, 2, 3
    else 
    {
         cout<<"Please Input Valid Numbers " <<endl;
    }
}

template<class DiscData>
bool TowerHanoi<DiscData>::checkWin() const
{
    //if rodOne and rodTwo are empty, then finish the game
    if(rodOne->is_empty() && rodTwo->is_empty())
    {
        return true; 
    }
    else
    {
        return false;
    }
}

template<class DiscData>
void TowerHanoi<DiscData>::push_TH(const DiscData& new_data, int rodNum)
{   
    //only possible to pass numbers are 1, 2, or 3 into this function 
    if(rodNum ==1) //rodOne is here 
    {
        rodOne->push(new_data); //data value is add to rodOne
    }
    else if(rodNum == 2) //rodTwo is here
    {
        rodTwo->push(new_data);
    }
    else //rodThree is here
    {
        rodThree->push(new_data);
    }
}

template<class DiscData>
DiscData TowerHanoi<DiscData>::pop_TH(int rodNum)
{
    //only possible to pass numbers are 1, 2, or 3 into this function 
    //almost the same idea as push_TH()
    if(rodNum ==1)
    {
        return rodOne->pop();
    }
    else if(rodNum == 2)
    {
        return rodTwo->pop();
    }
    else 
    {
        return rodThree->pop();
    }
}

template<class DiscData>
DiscData& TowerHanoi<DiscData>::top_TH(int rodNum) const
{
    //only possible to pass numbers are 1, 2, or 3 into this function 
    //almost the same idea as push_TH()
    if(rodNum ==1)
    {
        return rodOne->top();
    }
    else if(rodNum == 2)
    {
        return rodTwo->top();
    }
    else
    {
        return rodThree->top();
    }
}

template <class DiscData>
bool TowerHanoi<DiscData>::is_empty_TH(int rod) const
{
    //only possible to pass numbers are 1, 2, or 3 into this function 
    //almost the same idea as push_TH()
    if(rod == 1)
    {
        return rodOne->is_empty();
    }
    else if(rod == 2)
    {
        return rodTwo->is_empty();
    }
    else
    {
        return rodThree->is_empty();
    }
}

template<class DiscData>
std::ostream& operator << (std::ostream& out, TowerHanoi<DiscData>& tower)
{
    //creating new game here to pass the original data to the copy
    //create in stack 
    TowerHanoi<DiscData> copy = TowerHanoi <DiscData>(); 
    
    //reverse the rods 
    //original 1 2 3 
    //copy holds 3 2 1 
    while(!tower.is_empty_TH(1))
    {
        copy.push_TH(tower.pop_TH(1), 1);
    }
    
    while(!tower.is_empty_TH(2))
    {
        copy.push_TH(tower.pop_TH(2), 2);
    }
    
    while(!tower.is_empty_TH(3))
    {
        copy.push_TH(tower.pop_TH(3), 3);
    }
    
    //print out from highest number 
    //         original(tower)                                copy <- we are here now, after copy.push_TH(tower.pop(N), N)
    //      rodOne  rodTwo  rodThree                 rodOne  rodTwo  rodThree
    
    // L3   empty   empty    empty              L3   xxxxx      x      empty
    // L2    xxx    empty    empty              L2    xxx     empty    empty
    // L1   xxxxx      x     empty              L1   empty    empty    empty
    
    // this is L1~5 does 
    // L1 = rodOne + rodTwo + rodThree
    
    stringstream L5(""); 
    stringstream L4("");
    stringstream L3("");
    stringstream L2("");
    stringstream L1("");
    
    
    //preparing the string/int data into stringstream which can deal any types to print out 
    L5 << " ";
    for(int i = 1; i <=3; i++)
    {
       if(!copy.is_empty_TH(i))
       {
           L5 << copy.top_TH(i);
           tower.push_TH(copy.pop_TH(i), i);  //putting it back to the original rod
       }
       else
       {
           L5 << "         "; //print out spaces to the screen 
       }
       L5 << " ";
    }
    
    L4 << " ";
    for(int i = 1; i <=3; i++)
    {
       if(!copy.is_empty_TH(i))
       {
           L4 << copy.top_TH(i);
           tower.push_TH(copy.pop_TH(i), i);  //putting it back to the original rod
       }
       else
       {
           L4 << "         ";
       }
       L4 << " ";
    }
   
    L3 << " ";
    for(int i = 1; i <=3; i++)
    {
       if(!copy.is_empty_TH(i))
       {
           L3 << copy.top_TH(i);
           tower.push_TH(copy.pop_TH(i), i);  //putting it back to the original rod
       }
       else
       {
           L3 << "         ";
       }
       L3 << " ";
    }
  
    L2 << " ";
    for(int i = 1; i <=3; i++)
    {
       if(!copy.is_empty_TH(i))
       {
           L2 << copy.top_TH(i);
           tower.push_TH(copy.pop_TH(i), i);  //putting it back to the original rod
       }
       else
       {
           L2 << "         ";
       }
       L2 << " ";
    }
    
    L1 << " ";
    for(int i = 1; i <=3; i++)
    {
       if(!copy.is_empty_TH(i))
       {
           L1 << copy.top_TH(i);
           tower.push_TH(copy.pop_TH(i), i);  //putting it back to the original rod
       }
       else
       {
           L1 << "         ";
       }
       L1 << " ";
    }
  
    //print out from L1 to L5 
    out<< L1.str() << "\n" << L2.str()<< "\n" << L3.str() << "\n" << L4.str() << "\n" << L5.str() << "\n";
    
    out <<" " << "---------"<< " " << "---------"<< " " << "---------" <<" " << endl;
    out <<" " << "---(1)---"<< " " << "---(2)---"<< " " << "---(3)---" <<" " << endl;
    
    return out; 
}