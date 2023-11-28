//
//  main.cpp
//  LQueue
//
//  Created by Ashraf AbdelRaouf on 11/7/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

#include "Queue.hpp"
#include "Stack.hpp"



int main(int argc, const char* argv[]) {
    int gameRestart = 0;
    while (gameRestart == 0) {
        Queue q1;
        cout << "Queue created.\t is it Empty? " << boolalpha << q1.empty() << endl;
        q1.createShuffledQueue();

        cout << "-------dev-------dev------dev-------\n";

        cout << "Contents of queue q1 (via  cout):\n";
        cout << q1 << endl;

        cout << "Contents of queue q1 (via  printCards() ):\n";
        q1.printCards();
        cout << "-------dev-------dev------dev-------\n";

        int n = 6;
        int GameCounter = 0;

        cout << "<><>Game<><>Started<><>\n";
        // Record the start time
        clock_t start_time = clock();

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
        q1.deleteQueue();
        // Record the end time
        clock_t end_time = clock();
        // Calculate the duration between start and end times
        double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "\nGame Ended\n" << "You Played " << GameCounter << " Rounds " << endl << "Game time: " << duration << " seconds" << endl;
        cout << "Press 0 to play again" << endl << "Press 1 to exit"<<endl;
        cin >> gameRestart;
    }
    cout << "Ben7ebak ya Dr Ashraf ^3^";
    return 0;

}
