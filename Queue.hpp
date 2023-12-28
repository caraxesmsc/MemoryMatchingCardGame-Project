
#ifndef Queue_hpp
#define Queue_hpp
#include "Card.h"
#include <stdio.h>
#include <iostream>
using namespace std;


class Queue
{
public:

    Queue();

    Queue(const Queue& original);
    ~Queue();
    const Queue& operator= (const Queue& rightHandSide);

    bool empty() const;

    void enqueue(const Card& value);

    void display(ostream& out) const;

    Card front() const;

    void dequeue();

    void deleteQueue();

    void printCards();

    void displayGrid();

    void createShuffledQueue(int* array);

    void shuffleArray(int arr[], int size);

    bool ismatched(Queue& card1, Queue& card2);

    bool checkMatch(int loc1, int loc2);
    int chooseCard();
    bool isGameOver(int n);
    bool checkMatchHard(Card card1, int loc2);
    void searchCard(Card card1);
    bool checkMatchCards(Card card1, Card card2);
    /*void shufflequeue(Queue<int> q);
    void arrayToQueue(int* arr);
    void shuffleArray(int arr[]);
    int* queueToArray(Queue<int> q);*/



    //private:
        /*** Node class ***/
    class Node
    {
    public:
        Card data;
        Node* next;
        //--- Node constructor
        Node(Card value, Node* link = 0)
        {
            data = value; next = link;
        }

    };
    typedef Node* NodePointer;

    /***** Data Members *****/
    NodePointer myFront,      // pointer to front of queue
        myBack;         // pointer to back of queue


}; // end of class declaration

//------ Prototype of output operator
ostream& operator<< (ostream& out, const Queue& aList);


#endif /* Queue_hpp */