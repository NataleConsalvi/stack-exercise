#ifndef CAPPED_STACK_H
#define CAPPED_STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include "basic_stack.h"
#include <vector>
#include <algorithm>


using std::string;
using std::vector;

template <typename T>
class CappedStack: public BasicStack<T>{
    private:
        int cap;
    
    public:

       /**
        * Creates a CappedStack capped at provided cap.
          
           - if cap <= 0, throws a std::invalid_argument
       */   
        CappedStack<T>(const int cap);

        /** Return a string like 
          
               CappedStack: cap=4 elements=ab
       */
       virtual string as_string() const;
 
       /** Adds item to the top of the stack, if current size is within cap.
              
               - If stack size is already at cap value, new item is silently discarded
          
       */
       virtual void push(const T c);
 
 
       /** RETURN the cap of the stack
       */
       //virtual int get_cap() const;
 
       /**
        MODIFIES the cap setting its value to the provided cap.
          
            If the cap is less then the stack size, all the elements above
            the cap are removed from the stack.
            
            If cap < 1, throws an std::invalid_argument exception
            Does *not* return anything!
       */
       virtual void set_cap(const int cap);

};

template <typename T>
CappedStack<T>::CappedStack(const int cap){
    if(cap <= 0){
        throw std::invalid_argument("cap is null or negative!");
    }else{
        this->vec = vector<T>();
        this->cap = cap;
    }
}

template <typename T>
string CappedStack<T>::as_string() const {

    debug_stamp("printing stack");
    string s = "CapppedStack: cap = ";
    s += std::to_string(cap);
    s += " elements: ";
    std::stringstream ss;
    for(int i = 0; i < this->vec.size(); i++){
        ss << this->vec[i];
    }
    s += ss.str();
    return s;
}

template <typename T>
void CappedStack<T>::push(const T c) {
    debug_stamp(string("adding element at the end of stack"));
    if(this->vec.size() < this->cap){
        this->vec.push_back(c);
    }else{

    }
}

template <typename T>
void CappedStack<T>::set_cap(const int cap) {
    debug_stamp(string("resetting cap = ") + std::to_string(cap));
    if(cap < 1){
        throw std::invalid_argument("cap is null or negative!");
    }
    if(cap < this->vec.size()){
        this->vec = {this->vec.begin(),this->vec.begin() + cap};
        this->cap = cap;
    }else{
        this->cap = cap;
    }

}


#endif //CAPPED_STACK_H