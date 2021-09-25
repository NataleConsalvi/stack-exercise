#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "stack.h"
#include <vector>
#include <algorithm>


using std::string;
using std::vector;


void debug_stamp(string s);

template <typename T>
class BasicStack: public Stack<T> {

    protected:
        vector<T> vec;

    public:

        BasicStack<T>(){
            this->vec = vector<T>();
        }

        virtual int size() const;

        virtual string as_string() const;

        virtual bool is_empty() const;

        virtual void push(const T c);

        virtual T peek() const;

        virtual T pop();

        virtual vector<T> peekn(const int n) const;

        virtual vector<T> popn(const int n);
};

template <typename T>
int BasicStack<T>::size() const {
    debug_stamp("analysing the size of stack");
    return this->vec.size();
}

template <typename T>
std::string BasicStack<T>::as_string() const {

    debug_stamp("printing stack");
    string s = "BasicStack: ";
    std::stringstream ss;
    for(int i = 0; i < this->vec.size(); i++){
        ss << this->vec[i];
    }
    s += ss.str();
    return s;
}

template <typename T>
bool BasicStack<T>::is_empty() const {

    debug_stamp("analysing if the stack is empty");
    if(this->vec.size() == 0){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void BasicStack<T>::push(const T c) {

    debug_stamp(string("adding element at the end of stack"));
    this->vec.push_back(c);
}

template <typename T>
T BasicStack<T>::peek() const {
    debug_stamp("analysing the element at the end of stack");

    if(this->vec.size() == 0){
        throw std::runtime_error(string("Stack is empty!"));
    }else{
        return this->vec[this->vec.size()];
        //return this->vec.back();
    }
    
}

template <typename T>
T BasicStack<T>::pop() {

    debug_stamp("poppint the element at the end of stack");
    if(this->vec.size() == 0){
        throw std::runtime_error(string("Stack is empty!"));
    }else{
        T t= this->vec.back();
        //this->vec.resize(this->vec.size() - 1);
        this->vec.pop_back();
        return t;
    }
}

template <typename T>
vector<T> BasicStack<T>::peekn(const int n) const {

    debug_stamp(string("analysing the last ") + std::to_string(n) + string(" elements at the end of stack"));
    if(n < 0){
        throw std::invalid_argument(string("n is negative!"));
    }
    if(n > this->vec.size()){
        throw std::invalid_argument(string("n is greater than size of stack! n = ") + std::to_string(n) + " > " + std::to_string(this->vec.size()) + " (size)");
    }

    //int i = this->vec.size() - n;
    return {this->vec.end() - n, this->vec.end()};
    //return {this->vec.begin() + i; this->vec.end()};
}

template <typename T>
vector<T> BasicStack<T>::popn(const int n) {

    debug_stamp(string("poppint the last ") + std::to_string(n) + string(" elements at the end of stack"));
    if(n < 0){
        throw std::invalid_argument(string("n is negative!"));
    }
    if(n > this->vec.size()){
        throw std::invalid_argument(string("n is greater than size of stack! (n) ") + std::to_string(n) + " > " + std::to_string(this->vec.size()) + " (size)");
    }
    //int i = this->vec.size() - n;
    vector<T> ret = {this->vec.end() - n, this->vec.end()};
    this->vec.resize(this->vec.size() - n);
    return ret;
    //return {this->vec.begin() + i; this->vec.end()};
}


#endif //BASIC_STACK_H