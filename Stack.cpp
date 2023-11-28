#include "Stack.hpp"
#include "Card.h"

#ifdef SSTACK

Stack::Stack(int numElements) : myTop(-1), myCapacity(DEFAULT_CAPACITY) {}

Stack::Stack(const Stack& original) : myTop(original.myTop), myCapacity(DEFAULT_CAPACITY) {
    for (int pos = 0; pos <= myTop; pos++) {
        myArray[pos] = original.myArray[pos];
    }
}

Stack::~Stack() {
    // Nothing to delete in a static list implementation of a stack! :)
}

const Stack& Stack::operator=(const Stack& rhs) {
    if (this != &rhs) {
        myTop = rhs.myTop;
        for (int pos = 0; pos <= myTop; pos++) {
            myArray[pos] = rhs.myArray[pos];
        }
    }
    return *this;
}

bool Stack::empty() const {
    return myTop == -1;
}

void Stack::push(const StackElement& value) {
    if (myTop >= myCapacity - 1) {
        cerr << "Stack-full! " << endl;
        exit(1);
    }
    myArray[++myTop] = value;
}

void Stack::display(ostream& out) const {
    if (empty()) {
        cerr << "Stack-empty!" << endl;
        return;
    }
    for (int i = myTop; i >= 0; i--) {
        out << myArray[i] << ' ';
    }
    out << endl;
}

StackElement Stack::top() const {
    if (!empty())
        return myArray[myTop];
    else {
        cerr << "Stack Empty -- Returning garbage." << endl;
        StackElement garbage;
        return garbage;
    }
}

void Stack::pop() {
    if (!empty())
        myTop--;
    else {
        cerr << "Stack Empty!" << endl;
    }
}

ostream& operator<< (ostream& out, const Stack& aStack) {
    aStack.display(out);
    return out;
}

#endif // SSTACK