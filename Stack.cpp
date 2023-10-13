using namespace std;

#include <iostream>
#include <iomanip>
#include "Stack.h"

Stack::Stack(const int maxSize){

    if(maxSize >= 1)
    {
        stackArray = new Element[maxSize - 1];
        top = 0;
    }

    else if(maxSize < 1)
    {
        cout << "You entered the value " << maxSize << " which is unfortunately not able to be a size for a Stack. Please reset the program and retry with a number larger than or equal to 1.";
    }

    else if(maxSize != 0)
    {
        stackArray = new Element[STACK_SIZE];
        top = 0;
    }

}


Stack::~Stack() {

    delete[] stackArray;

}


void Stack::push( const Element element )
{

    if (top < STACK_SIZE)
    {
        stackArray[top++] = element;
    }

    else if(top >= STACK_SIZE)
    {
        cout << endl << endl << "The stack is currently full with the max: " << STACK_SIZE << " items. Please remove an element before attempting to add " << element << ".\n\n" << endl;
    }

    else
    {
        cout << endl << endl << "Sorry, there was an error with reading the top value.";
    }

    return;

}


Element Stack::pop()
{

    if(top >= 0)
    {
        Element element = stackArray[top--];
        return element;
    }

    else if(top < 0)
    {
        cout << "\n\nUnfortunately, there was an error with popping out the next element because the stack is empty.\n\n";
        return Element();
    }

    else
    {
        cout << "\n\nThere was an error with popping out the next element due to an issue with the 'top' variable.\n\n";
        return Element();
    }

}

Element Stack::peek()
{

    if (top >= 0) {
        Element tempElement = pop();
        push(tempElement);
        return tempElement;
    }

    else if(top < 0)
    {
        cout << "\n\nThe stack you are trying to view the top element of is empty, please revise your request.\n\n";
        return Element();
    }

    else
    {
        cout << "\n\nThere was an error processing the top value, please revise your request.\n\n";
        return Element();
    }

}

void Stack::view()
{
    Stack tempStack(STACK_SIZE);
    cout << "/n/nStack elements from top to bottom are:" << endl;

    if(top >=0)
    {
        Stack temp(STACK_SIZE);
        cout << "\n\n Stack elements from top to bottom are: " << endl;

        while (top >= 0)
        {
            Element element = pop();
            temp.push(element);
            cout << element << endl;
        }

        while (temp.top >= 0)
        {
            Element element = temp.pop();
            push(element);
        }
    }

    else if(top < 0)
    {
        cout << "\nStack is empty";
    }else{
        cout << "\n";

    }
    return;

}
