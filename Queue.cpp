#include "Queue.hpp"
#include "Stack.hpp"
#include "Card.h"

//--- Definition of Queue constructor
Queue::Queue()
    : myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue& original)
{
    myFront = myBack = 0;
    if (!original.empty())
    {
        // Copy first node
        myFront = myBack = new Queue::Node(original.front());

        // Set pointer to run through original's linked list
        Queue::NodePointer origPtr = original.myFront->next;
        while (origPtr != 0)
        {
            myBack->next = new Queue::Node(origPtr->data);
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

//--- Definition of Queue destructor
Queue::~Queue()
{
    // Set pointer to run through the queue
    Queue::NodePointer prev = myFront,
        ptr;
    while (prev != 0)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue& Queue::operator=(const Queue& rightHandSide)
{
    if (this != &rightHandSide)         // check that not q = q
    {
        this->~Queue();                  // destroy current linked list
        if (rightHandSide.empty())       // empty queue
            myFront = myBack = 0;
        else
        {                                // copy rightHandSide's list
            // Copy first node
            myFront = myBack = new Queue::Node(rightHandSide.front());

            // Set pointer to run through rightHandSide's linked list
            Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
            while (rhsPtr != 0)
            {
                myBack->next = new Queue::Node(rhsPtr->data);
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{
    return (myFront == 0);
}

//--- Definition of enqueue()
void Queue::enqueue(const Card& value)
{
    Queue::NodePointer newptr = new Queue::Node(value);
    if (empty())
        myFront = myBack = newptr;
    else
    {
        myBack->next = newptr;
        myBack = newptr;
    }
}

//--- Definition of display()
void Queue::display(ostream& out) const
{
    Queue::NodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data.CardName << "  ";
    out << endl;

}

//--- Definition of output operator
ostream& operator<< (ostream& out, const Queue& aQueue) {
    aQueue.display(out);
    return out;
}

//--- Definition of front()
Card Queue::front() const
{
    if (!empty())
        return (myFront->data);
    else
    {
        cerr << "*** Queue is empty " << " -- returning garbage ***\n";
        Card* temp = new(Card);
        Card garbage = *temp;     // "Garbage" value
        delete temp;
        return garbage;
    }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
    if (!empty())
    {
        Queue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == 0)     // queue is now empty
            myBack = 0;
    }
    else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}

void Queue::deleteQueue() {
    while (myFront != nullptr) {
        Node* temp = myFront;
        myFront = myFront->next;
        delete temp;
    }
    myBack = nullptr;
}

void Queue::printCards() {
    Node* current = myFront;
    while (current != nullptr) {
        cout << current->data.CardName << " ";
        current = current->next;
    }
    cout << endl;
}
bool Queue::ismatched(Queue& card1, Queue& card2) {
    if (card1.empty() || card2.empty()) {
        return false;
    }
    Card match1 = card1.front();
    Card match2 = card2.front();

    return (match1.CardName == match2.CardName);
}
bool Queue::checkMatch(int loc1, int loc2) {

    Queue::Node* head1 = myFront;
    Queue::Node* head2 = myFront;

    for (int i = 0; i < loc1; i++) {
        head1 = head1->next;
    }
    for (int i = 0; i < loc2; i++) {
        head2 = head2->next;
    }


    if (head1->data.CardName == head2->data.CardName) {
        head1->data.isShown = true;
        head2->data.isShown = true;
        return true;
    }
    return false;
}
bool Queue::checkMatchHard(Card card1, int loc2) {

    Queue::Node* head2 = myFront;


    for (int i = 0; i < loc2; i++) {
        head2 = head2->next;
    }


    if (card1.CardName == head2->data.CardName) {
        head2->data.isShown = true;
        return true;
    }
    return false;
}
bool Queue::checkMatchCards(Card card1, Card card2) {

    if (card1.CardName == card2.CardName) {
        card1.isShown = true;
        card2.isShown = true;

        return true;
    }
    return false;
}
void Queue::displayGrid() {
    Node* current = myFront;
    for (int i = 0; i < 12; i++) {
        if (current->data.isShown) {
            cout << " (" << current->data.CardName << ")";
        }
        else {
            cout << " [" << i << "]";
        }
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
        current = current->next;
    }
}
void Queue::createShuffledQueue(int* indexArray) {



    // Duplicate indices to create pairs
    int shuffledIndices[12];
    for (int i = 0; i < 6; ++i) {
        shuffledIndices[i * 2] = *indexArray;
        shuffledIndices[i * 2 + 1] = *indexArray;
        indexArray++;
    }
    // Reset the pointer to the beginning
    indexArray -= 6;
    // Shuffle the indices array
    shuffleArray(shuffledIndices, 12);

    // Add the shuffled cards to the deck
    for (int i = 0; i < 12; ++i) {
        enqueue(Card(shuffledIndices[i] * 2));
    }
}

// Custom shuffle function (Fisher-Yates algorithm)
void Queue::shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; --i) {
        srand(time(NULL));

        int j = rand() % (i + 1);
        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int Queue::chooseCard() {
    int loc;
    Queue::Node* head1 = myFront;
    cout << "Enter location (0-11): ";
    cin >> loc;
    for (int i = 0; i < loc; i++) {
        head1 = head1->next;
    }
    cout << "you chose location " << loc << " card is " << head1->data.CardName << endl;
    return loc;
}
void Queue::searchCard(Card card1) {

    Queue::Node* head1 = myFront;
    while (head1->data.CardName != card1.CardName) {
        head1 = head1->next;
    }
    head1->data.isShown = true;
}

bool Queue::isGameOver(int n) {
    if (n == 0) {
        cout << " Game Over !";
        return false;
    }
    else {
        return true;
    }
}
