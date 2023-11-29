#include "Card.h"
#ifndef STACK
#define SSTACK

#include <iostream>
using namespace std;
const int DEFAULT_CAPACITY = 128;

class Stack {

public:
    Stack();
    Stack(int numElements = DEFAULT_CAPACITY);
    const Stack& operator= (const Stack& rhs);
    bool empty() const;
    void push(const Card& value);
    void display(ostream& out) const;
    Card top() const;
    void pop();
    void createObjectiveStack(int* indexArray);
private:

    Card myArray[DEFAULT_CAPACITY];


    int myTop; // Top index in stack
    int myCapacity; // Capacity of dynamic stack

};

ostream& operator<< (ostream& out, const Stack& aStack);

#endif /* STACK */
