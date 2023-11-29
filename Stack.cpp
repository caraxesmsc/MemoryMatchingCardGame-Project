#include "Stack.hpp"
#include "Card.h"

#ifdef SSTACK

Stack::Stack() : myTop(-1), myCapacity(DEFAULT_CAPACITY) {}
Stack::Stack(int numElements) : myTop(-1), myCapacity(DEFAULT_CAPACITY) {}


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

void Stack::push(const Card& value) {
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
        out << myArray[i].CardName << ' ';
    }
    out << endl;
}

Card Stack::top() const {
    if (!empty())
        return myArray[myTop];
    else {
        cerr << "Stack Empty -- Returning garbage." << endl;
        Card garbage;
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


void Stack::createObjectiveStack(int* indexArray) {
    // Push unique values to the stack
    for (int i = 0; i < 6; ++i) {
        push(Card(*indexArray * 2));
        indexArray++;
    }

}
#endif // SSTACK