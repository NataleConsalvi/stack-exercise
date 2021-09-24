#ifndef CAPPED_STACK_H
#define CAPPED_STACK_H

#include <iostream>
#include "stack.h"
#include "basic_stack.h"

class CappedStack: public BasicStack{
    private:
        int cap;
    
    public:

       /**
        * Creates a CappedStack capped at provided cap.
          
           - if cap <= 0, throws a std::invalid_argument
       */   
        CappedStack(const int cap);

        /** Return a string like 
          
               CappedStack: cap=4 elements=ab
       */
       virtual string as_string() const;
 
       /** Adds item to the top of the stack, if current size is within cap.
              
               - If stack size is already at cap value, new item is silently discarded
          
       */
       virtual void push(const char c);
 
 
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



#endif //CAPPED_STACK_H