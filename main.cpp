#include <iostream>

#include "basic_stack.h"

using namespace std;

/*
int main() {
    BasicStack bs = BasicStack();

    cout << bs.size() << endl;

    bs.push('a');
    bs.push('b');
    bs.push('d');
    cout << bs.as_string() << endl;
    cout << bs.peek() << endl;
    cout << bs.as_string() << endl;
    cout << bs.pop() << endl;
    cout << bs.as_string() << endl;
    bs.push('e');
    cout << bs.as_string() << endl;

    cout << bs.peekn(2) << endl;

    return 0;
}
*/

int main () {
  
   cout << endl;
   cout << "-----  BASIC STACK" << endl;   
 
   BasicStack bs = BasicStack();
 
   Stack* ps1 = &bs;
   cout << ps1->as_string() << endl;  // BasicStack: elements=
   ps1->push('a');
   cout << ps1->as_string() << endl;  // BasicStack: elements=a
   cout << ps1->peek() << endl;       // 'a'
   ps1->push('b');
   cout << ps1->peek() << endl;       // 'b'
   cout << ps1->as_string() << endl;  // BasicStack: elements=ab
   cout << ps1->peek() << endl;       // 'b'
   ps1->push('c');                   
   cout << ps1->peek() << endl;       // 'c'
   cout << ps1->as_string() << endl;  // BasicStack: elements=abc
   cout << ps1->pop() << endl;        // 'c'
   cout << ps1->pop() << endl;        // 'b'
   cout << ps1->as_string() << endl;  // BasicStack: elements=a
   cout << ps1->pop() << endl;        // 'a'
  
   try {
       ps1->pop(); //  can't pop empty stack
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   try {
       ps1->peek(); // can't peek empty stack
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   cout << endl;
   cout << "-----  RESETTING BASIC STACK" << endl;   
   bs = BasicStack();
   ps1->push('a');
   ps1->push('b');
   ps1->push('c');
   ps1->push('d');
   ps1->push('e');
   cout << ps1->as_string() << endl;  // abcde
   cout << ps1->peekn(3) << endl;     // cde
   cout << ps1->peekn(5) << endl;     // abcde
   try {
       cout << ps1->peekn(6) << endl;    // error
   } catch (std::invalid_argument& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   cout << ps1->as_string() << endl;  // abcde
   cout << ps1->popn(3) << endl;      // cde
   cout << ps1->as_string() << endl;  // ab
 
 
   cout << endl;
}
