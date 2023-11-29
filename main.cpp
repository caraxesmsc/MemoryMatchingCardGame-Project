
#include <iostream>
#include <ctime>

using namespace std;

#include "Queue.hpp"
#include "Stack.hpp"



int main(int argc, const char* argv[]) {
    int gameRestart = 0;

    
    // Generate an array of indices from 0 to 5 (representing pairs)
    int indices[6];
    int* ptr = &indices[0];
    for (int i = 0; i < 6; ++i) {
        indices[i] = i;
    }
    
    // Optionally, you can display the stack contents for testing
   //s1.display(cout);
    while (gameRestart == 0) {
        Queue q1;
        cout << "Queue created.\t is it Empty? " << boolalpha << q1.empty() << endl;
        q1.createShuffledQueue(ptr);

        cout << "-------dev-------dev------dev-------\n";

        cout << "Contents of queue q1 :\n";
        q1.printCards();
        cout << "-------dev-------dev------dev-------\n";

        int n = 6;
        int GameCounter = 0;

        cout << "<><>Game<><>Started<><>\n";
        // Record the start time
        clock_t start_time = clock();
        int gameMode = 1;
        cout << "Memory Matching Card Game" << endl << "For Normal mode Press 1" << endl << "For Hard mode Press 2" << endl;
        cin >> gameMode;
        if (gameMode == 1) {
            while (q1.isGameOver(n)) {
                cout << "Contents of queue q1 (via  displayGrid() ):\n";
                q1.displayGrid();
                int loc1 = q1.chooseCard();
                int loc2 = q1.chooseCard();

                if (q1.checkMatch(loc1, loc2)) {
                    cout << endl << "^o^ Cards are matched ^o^" << endl;
                    n--;
                }
                else {
                    cout << "Cards are not matched." << endl;
                }
                GameCounter++;
            }
        }
        else if (gameMode == 2) {
                // Create a stack to store unique values
                Stack s1(6);
                cout << "3amalna stack";
                s1.createObjectiveStack(ptr);
                cout << "malena stack";

            while (!s1.empty()) {
                cout << "Contents of queue q1 (via  displayGrid() ):\n";
                Card card1 = s1.top();
                q1.searchCard(card1);
                q1.displayGrid();
                int loc2 = q1.chooseCard();

                if (q1.checkMatchHard(card1, loc2)) {
                    cout << endl << "^o^ Cards are matched ^o^" << endl;
                    s1.pop();
                }
                else {
                    cout << "Cards are not matched." << endl;
                }
                GameCounter++;
            }
        }
        else {
            cout << "No Game Chosen";
        }
        q1.deleteQueue();
        // Record the end time
        clock_t end_time = clock();
        // Calculate the duration between start and end times
        double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "\nGame Ended\n" << "You Played " << GameCounter << " Rounds " << endl << "Game time: " << duration << " seconds" << endl;
        cout << "Press 0 to play again" << endl << "Press 1 to exit"<<endl;
        cin >> gameRestart;
    }
    cout << "Game is Over";
    return 0;

}
