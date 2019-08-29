//
//  main.cpp
//  Project1
//
//  Created by McKenzie Humann on 8/25/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int RollDice(int pot) {
    int roll;
    roll = rand() % 6 + 1;
    if (roll > 1) {
        pot += roll;
        cout << "Die Roll : " << roll << "    Pot : " << pot << endl;
        
    }
    else {
        pot = 0;
        cout << "Die Roll 1: BUST" << endl << endl;
    }
    return pot;
}

bool RollAgain(int pot) {
    bool rollAgain = false;
    string resp;
    if (pot > 0) {
        cout << "(R)oll again or (H)old? ";
        cin >> resp;
        
        while (resp != "r" && resp != "R" && resp != "h" && resp != "H") {
            cout << "You must enter R or H." << endl << endl;
            cout << "(R)oll again or (H)old? ";
            cin >> resp;
        }
    
        if (resp == "r" || resp == "R") {
            rollAgain = true;
        }
    }
    
    return rollAgain;
}

int AITurn () {
    int pot = 0;
    
    cout << "AI Turn" << endl << endl;
    while (pot < 20) {
        pot = RollDice(pot);
        if (pot == 0) {
            break;
        }
    }
    return pot;
}

int PlayerTurn () {
    int pot = 0;
    bool rollAgain = true;
    
    cout << "Player's Turn" << endl << endl;
    while (rollAgain == true) {
        pot = RollDice(pot);
        rollAgain = RollAgain(pot);
    }
    
    cout << endl;
    return pot;
}

bool GamePlayerFirst() {
    
    int playerScore = 0;
    int AIScore = 0;
    bool playerLast = true; // only to pass to the main function to switch players in subsequent game
    
    srand(int(time(NULL)));
    
    while (true) {
        cout << "Score   You: " << playerScore << " AI: " << AIScore << endl << endl;
        playerScore += PlayerTurn();
        
        if (playerScore >= 50) {
            cout << "You won!" << endl;
            cout << "Final Score:  You: " << playerScore;
            cout << "  AI: " << AIScore << endl;
            playerLast = true;
            break;
        }
        
        cout << "Score   You: " << playerScore << " AI: " << AIScore << endl << endl;
        AIScore += AITurn();
        
        if (AIScore >= 50) {
            cout << "Computer won!" << endl;
            cout << "Final Score:  You: " << playerScore;
            cout << "  AI: " << AIScore << endl;
            playerLast = false;
            break;
        }
    }
    return playerLast;
}

bool GameAIFirst() {
    int playerScore = 0;
    int AIScore = 0;
    bool playerLast = false; // only to pass to the main function to switch players in subsequent game
    
    srand(int(time(NULL)));
    
    while (true) {
        cout << "Score   You: " << playerScore << " AI: " << AIScore << endl << endl;
        AIScore += AITurn();
        
        if (AIScore >= 50) {
            cout << "Computer won!" << endl;
            cout << "Final Score:  You: " << playerScore;
            cout << "  AI: " << AIScore << endl << endl;
            playerLast = false;
            break;
        }

        cout << "Score   You: " << playerScore << " AI: " << AIScore << endl << endl;
        playerScore += PlayerTurn();
        
        if (playerScore >= 50) {
            cout << "You won!" << endl;
            cout << "Final Score:  You: " << playerScore;
            cout << "  AI: " << AIScore << endl << endl;
            playerLast = true;
            break;
        }
    }
    
    return playerLast;
}



int main() {
    string resp = "y";
    bool playerLast = false; // true if player is last, false if AI is last;
    
    while (resp == "y" || resp == "Y") {
        if (playerLast == true) {
            playerLast = GameAIFirst();
        }
        else {
            playerLast = GamePlayerFirst();
        }
        cout << "Do you want to play again? Please enter (Y)es or (N)o: ";
        cin >> resp;
        while (!(resp == "y" || resp == "Y" || resp == "n" || resp == "N")) {
            cout << "You must enter Y or N" << endl << endl;
            cout << "Do you want to play again? Please enter (Y)es or (N)o: ";
            cin >> resp;
            continue;
        }

    }
    
    return 0;
}
