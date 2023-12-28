
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, const char* argv[]) {
    int gameRestart = 0;

    
    // Generate an array of indices (representing pairs)
    int indices[6];
    int* ptrtoindices = &indices[0];
    // I want to store 0-5 , but i want the values to be 1-6
    for (int i = 0; i < 6; i++) {
        indices[i] = i+1;
        //cout << indices[i]<<endl;
    }
    
    // Optionally, you can display the stack contents for testing
   //s1.display(cout);
    while (gameRestart == 0) {
        Queue q1;
        q1.createShuffledQueue(ptrtoindices);

        cout << "-------dev-------dev------dev-------\n";
        cout << "Contents of queue q1 :\n";
        cout << "0 1 2 3 4 5 6 7 8 9  10 11\n";

        q1.printCards();
        cout << "-------dev-------dev------dev-------\n";

        int n = 6;
        int GameCounter = 0;

        cout << "<><>Game<><>Started<><>\n";
       
        int gameMode = 1;
        cout << "Memory Matching Card Game" << endl << "For Normal mode Press 1" << endl << "For Hard mode Press 2" << endl;
        cin >> gameMode;
        if (gameMode == 1) {
            // Record the start time
            clock_t start_time = clock();
            while (q1.isGameOver(n)) {
                //display grid
                q1.displayGrid();
                //choose locations
                int loc1 = q1.chooseCard();
                int loc2 = q1.chooseCard();
                //check if they are matched
                if (q1.checkMatch(loc1, loc2)) {
                    cout << "Cards are matched" << endl;
                    n--;
                }
                else {
                    cout << "Cards are not matched." << endl;
                }
                GameCounter++;
            }
            // Record the end time
            clock_t end_time = clock();
            // Calculate the duration between start and end times
            double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "\nGame Ended\n" << "You Played " << GameCounter << " Rounds " << endl << "Game time: " << duration << " seconds" << endl;
        }
        else if (gameMode == 2) {
            //counter to store how many times i played    
            int stackGameCounter = 0;
            // Create a stack to store objective cards
            Stack s1(6);
                
            s1.createObjectiveStack(ptrtoindices);
                
            // Record the start time
            clock_t start_time = clock();
            
            while (!s1.empty()) {
                Card card1 = s1.top();
                q1.searchCard(card1);
                q1.displayGrid();
                cout << "You have to match card: " << card1.CardName << endl;
                int loc2 = q1.chooseCard();

                if (q1.checkMatchHard(card1, loc2)) {
                    cout << "Cards are matched " << endl;
                    s1.pop();
                }
                else {
                    cout << "Cards are not matched." << endl;
                }
                stackGameCounter++;
            }
            double successRate = 600/stackGameCounter ;
            // Record the end time
            clock_t end_time = clock();
            // Calculate the duration between start and end times
            double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "\nGame Ended\n" << "You Played " << stackGameCounter << " Rounds " << endl << "Your succes Rate is " << successRate << "%\n" << "Game time: " << duration << " seconds" << endl;

        }
        else {
            cout << "No Game Chosen";
        }
        
        q1.deleteQueue();
        
        cout << "Press 0 to play again" << endl << "Press 1 to exit"<<endl;
        cin >> gameRestart;
    }
    cout << "Game is Over";
    return 0;

}
