// General description of the ADT and supported operations – exportable operations only
// Do not include any implementation details

#ifndef _STACK_H
#define _STACK_H

#include <iostream>

typedef std::string Element;
typedef Element * ElementPtr;

class Stack {

    public:

        Stack();
        Stack( const int );
        Stack( Stack & );
        ~Stack();
        void push( const Element );
        Element pop( );
        Element peek( );
        void view( );

    private:

        const int STACK_SIZE = 2;
        ElementPtr stackArray;
        int top;

};

#endif
