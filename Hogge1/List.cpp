#include <iostream>
#include "List.h"
using namespace std;

//copy constructor
List::List(const List & old)
{
    Node * oldNodePtr;

    head = nullptr;

    //moves through the old list and appends each node to the new list
    oldNodePtr = old.head;

    while(oldNodePtr)
    {
        add(oldNodePtr->value);
        oldNodePtr = oldNodePtr->next;
    }

    return;
}

//destructor
List::~List()
{
    Node *Nodeptr;

    for (Nodeptr = head; head; Nodeptr = head)
    {
        head = head->next
        delete Nodeptr;
    }
}

//

//creates new node with num and inserts it into the list in numerical order
void List::add(float element)
{
    Node *newNode;
    Node *nodePtr;
    Node *previousNode = NULL;

    newNode = new Node;
    newNode->value = element;

    //checks if the list is empty and needs to make newNode the first node
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else    //if list is not empty, inserts a new node
    {
        //makes nodePtr the head
        nodePtr = head;

        //makes previousNode null
        previousNode = nullptr;


        //skips each node that's value is less than num
        while(nodePtr != NULL && nodePtr->value < element)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //if it is first then it is inserted before other nodes
        if(previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    //otherwise insert it after the previous node
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

//searches for the node with num and removes it from the list without breaking the link
void List::remove(float element)
{
    Node *nodePtr;
    Node *previousNode;

    if(!head)
        return;

    //checks if value is the first node
    if(head->value == element)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        //moves to the next node until the node equals the value
        nodePtr = head;

        while(nodePtr && nodePtr->value != element)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //checks to see if the end of the list was reached, if not then assigns the pointer
        //   of the (soon to be) deleted node to the previous node then deletes the node
        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//displays each value in the list with its corresponding node number
void List::view() const
{
    Node *nodePtr;

    //makes nodePtr the head of the list
    nodePtr = head;

    //go through the list until nodePtr isn't pointing to a value
    while(nodePtr)
    {
        //displays value of node
        cout << nodePtr->value << endl;
        //moves to the next node
        nodePtr = nodePtr->next;
    }
}