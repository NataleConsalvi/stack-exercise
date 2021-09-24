#include "stack.h"
#include "basic_stack.h"

void debug_stamp(std::string s){
    cout << "DEBUG: " << s << "." << endl;
}

int BasicStack::size() const {
    debug_stamp("analysing the size of stack");
    return this->s.size();
}

std::string BasicStack::as_string() const {
    debug_stamp("printing stack");
    return string("BasicStack: ") + string("elements: '") + this->s + "'";
}

bool BasicStack::is_empty() const {
    debug_stamp("analysing if the stack is empty");
    if(size() == 0){
        return true;
    }else{
        return false;
    }
}

void BasicStack::push(const char c) {
    debug_stamp(string("adding element '") + c + string("' at the end of stack"));
    this->s += c;
}

char BasicStack::peek() const {
    debug_stamp("analysing the element at the end of stack");
    if(this->s.size() == 0){
        throw std::runtime_error(string("Stack is empty!"));
    }else{
        return this->s.back();
    }
    
}

char BasicStack::pop() {
    debug_stamp("poppint the element at the end of stack");
    if(this->s.size() == 0){
        throw std::runtime_error(string("Stack is empty!"));
    }else{
        char c = this->s.back();
        this->s.pop_back();
        return c;
    }
}

string BasicStack::peekn(const int n) const {

    debug_stamp(string("analysing the last ") + std::to_string(n) + string(" elements at the end of stack"));
    if(n < 0){
        throw std::invalid_argument(string("n is negative!"));
    }
    if(n > this->s.size()){
        throw std::invalid_argument(string("n is greater than size of stack! n = ") + std::to_string(n) + " > " + std::to_string(this->s.size()) + " (size)");
    }

    int i = this->s.size();
    return this->s.substr(i - n, n);
}

string BasicStack::popn(const int n) {

    debug_stamp(string("poppint the last ") + std::to_string(n) + string(" elements at the end of stack"));
    if(n < 0){
        throw std::invalid_argument(string("n is negative!"));
    }
    if(n > this->s.size()){
        throw std::invalid_argument(string("n is greater than size of stack! (n) ") + std::to_string(n) + " > " + std::to_string(this->s.size()) + " (size)");
    }
    int i = this->s.size();
    string a = this->s.substr(i - n, n);
    for(int i = 0; i < n; i++){
        this->s.pop_back();
    }
    return a;
}