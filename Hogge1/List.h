#ifndef LIST_H // Guard – start
#define LIST_H
typedef float Element; // typedef <existing type> <new type>
// basic form of generic programming
class List {
    public: // exportable
    // General description of each of the ADT operations/methods/functions – exportable operations only
    List();
    List( const List & ); // reuse add
    ~List();
    void add( const Element );
    void remove( const Element );
    void view() const;
    private: // non-exportable
    // No private member documentation – implementation details are hidden/abstracted away
    struct Node;
    typedef Node * NodePtr;
    struct Node {
        Element element;
        NodePtr next;
    };
    
    NodePtr front;
};
#endif