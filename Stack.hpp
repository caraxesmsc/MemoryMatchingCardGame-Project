#ifndef STACK
#define STACK

/* Here's something new... We want to use one header file for all three implementations
 * But surely we can't compile three different implementations in the same project!
 * So what can we do? We can choose which implementation to compile for our project
 * One way to do that is to use preprocessor directives to define the type of stack
 * Uncomment only the implementation you want to compile in your project
 */

 // #define SSTACK // If you want the static list implementation
 // #define DSTACK // If you want the dynamic list implementation
#define LLSTACK // If you want the linked-list implementation

#include <iostream>
using namespace std;
typedef Card StackElement;
const int DEFAULT_CAPACITY = 128;

class Stack {

public:
    Stack(int numElements = DEFAULT_CAPACITY);
    Stack(const Stack& original);
    ~Stack();
    const Stack& operator= (const Stack& rhs);
    bool empty() const;
    void push(const StackElement& value);
    void display(ostream& out) const;
    StackElement top() const;
    void pop();

private:
#ifdef SSTACK
    StackElement myArray[DEFAULT_CAPACITY];
#else
    StackElement* myArray;
#endif

#ifdef LLSTACK
    class Node {
    public:
        StackElement data;
        Node* next;
        Node(StackElement value, Node* link = 0) : data(value), next(link) {}
    };
    typedef Node* NodePointer;
    NodePointer myTop; // Pointer to top node of stack
#else
    int myTop; // Top index in stack
    int myCapacity; // Capacity of dynamic stack
#endif
};

ostream& operator<< (ostream& out, const Stack& aStack);

#endif /* STACK */
