#include "stack.h"
#include "basic_stack.h"
#include "capped_stack.h"

using namespace std;

CappedStack::CappedStack(const int cap){
    if(cap <= 0){
        throw std::invalid_argument("cap is null or negative!");
    }else{
        this->s = "";
        this->cap = cap;
    }
}

string CappedStack::as_string() const {
    debug_stamp("printing stack");
    return string("CappedStack: cap = ") + to_string(this->cap) + string(" elements: '") + this->s + "'";
}

void CappedStack::push(const char c) {
    debug_stamp(string("adding element '") + c + string("' at the end of stack"));
    if(this->s.size() < this->cap){
        this->s += c;
    }else{

    }
}

void CappedStack::set_cap(const int cap) {
    debug_stamp(string("resetting cap = ") + std::to_string(cap));
    if(cap < 1){
        throw std::invalid_argument("cap is null or negative!");
    }
    if(cap < this->s.size()){
        this->s = this->s.substr(0,cap);
        this->cap = cap;
    }else{
        this->cap = cap;
    }

}