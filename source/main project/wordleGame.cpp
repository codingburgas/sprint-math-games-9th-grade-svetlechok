#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

void wordleGame () {
    int choice;


    cout << "\033[31m ,--.   ,--.\033[0m  \033[33m,-----.\033[0m  \033[93m,------.\033[0m  \033[92m,-----.\033[0m     \033[36m,--.\033[0m    \033[35m,------.\033[0m  " << endl; // Red for first part, Green for second part
    cout << "\033[31m |  |   |  |\033[0m \033[33m'  .-.  '\033[0m \033[93m|  .--. '\033[0m \033[92m|  .-.  \\\033[0m  \033[36m|  |\033[0m    \033[35m|  .---' \033[0m" << endl;  // Yellow for this part
    cout << "\033[31m |  |.'.|  |\033[0m \033[33m|  | |  |\033[0m \033[93m|  '--'.'\033[0m \033[92m|  | |  |\033[0m  \033[36m|  |\033[0m    \033[35m|  `--,   \033[0m" << endl;  // Blue for this part
    cout << "\033[31m |   ,'.   |\033[0m \033[33m'  '-'  ' \033[0m\033[93m|  |\\  \\\033[0m \033[92m '  '-'  |\033[0m  \033[36m|___  '\033[0m \033[35m|  `---.  \033[0m" << endl; // Magenta for this part
    cout << "\033[31m '--'   '--'\033[0m  \033[33m`-----'\033[0m  \033[93m`--' '--'\033[0m  \033[92m`-----'\033[0m   \033[36m`------'\033[0m \033[35m`------'  \033[0m" << endl;  // Cyan for this part




    cout << endl;
    
    cout << "\033[1mWELCOME TO WORDLE GAME!\033[0m" << endl;
    
   


        cout << "+--------+--------+--------------+\n";
        cout << "|\033[4m1.Start\033[0m |\033[4m2.Exit\033[0m  |\033[4m3.Instructions\033[0m|\n";
        cout << "+--------+--------+--------------+\n";
        cout << "\033[3mYou choose: \033[0m";
     
 
    cin >> choice;

    if (choice == 1) {
        const char* colors[] = {
       "\033[31m", // Red
       "\033[33m", // Yellow
       "\033[32m", // Green
       "\033[36m", // Cyan
       "\033[34m", // Blue
       "\033[35m"  // Magenta
        };


        const char* wordle = "WORDLE";
        for (int i = 0; i < 6; i++) {
            cout << colors[i % 6] << wordle[i];
        }
        cout << "\033[0m" << endl;



        const char* secretWords[] = {
            "drain", "hello", "apple", "berry", "charm", "flame", "catch", "dance", "grape", "haste",
            "image", "jumbo", "kneel", "lemon", "mango", "nylon", "olive", "pearl", "quake", "rider",
            "stone", "torch", "ultra", "vivid", "worry", "yield", "zebra","alarm", "beach", "candy", "dream", "eagle", "frost", "giant", "honey", "ivory", "jolly",
"knife", "lunar", "magic", "noble", "ocean", "pivot", "quiet", "river", "sunny", "trust",
"urban", "vapor", "whale", "xenon", "youth", "zesty", "amber", "blaze", "crown", "dusty",
"ember", "flora", "grove", "haste", "inbox", "jewel", "kiosk", "light", "moist", "nerve",
"oasis", "pride", "quest", "royal", "shade", "tiger", "unity", "vocal", "wheat", "zippy"

        };

        srand(time(0));

        const char* secretWord = secretWords[rand() % (sizeof(secretWords) / sizeof(secretWords[0]))];
        int attempts = 6;

        cout << "Welcome to Wordle! Try to guess the 5-letter word.\n";

        while (attempts > 0) {
            cout << "Attempts remaining: " << attempts << ". Enter your guess: ";
            string guess;
            cin >> guess;

            if (guess.length() != 5) {
                cout << "Please enter a 5-letter word.\n";
                continue;
            }

            bool isCorrect = true;
            for (int i = 0; i < 5; i++) {
                if (guess[i] != secretWord[i]) {
                    isCorrect = false;
                    break;
                }
            }

            if (isCorrect) {
                cout << "\033[32mCongratulations! You guessed the word!\033[0m\n";
                return;
            }

            char feedback[5] = { '_', '_', '_', '_', '_' };
            char secretCopy[6];
            for (int i = 0; i < 5; i++) secretCopy[i] = secretWord[i];
            secretCopy[5] = '\0';

            for (int i = 0; i < 5; i++) {
                if (guess[i] == secretWord[i]) {
                    feedback[i] = 'G';
                    secretCopy[i] = '*';
                }
            }

            for (int i = 0; i < 5; i++) {
                if (feedback[i] != 'G') {
                    for (int j = 0; j < 5; j++) {
                        if (guess[i] == secretCopy[j]) {
                            feedback[i] = 'Y';
                            secretCopy[j] = '*';
                            break;
                        }
                    }
                }
            }


            for (int i = 0; i < 5; i++) {
                if (feedback[i] == 'G') {
                    cout << "\033[32m" << guess[i] << "\033[0m";
                }
                else if (feedback[i] == 'Y') {
                    cout << "\033[33m" << guess[i] << "\033[0m";
                }
                else {
                    cout << "\033[90m" << guess[i] << "\033[0m";
                }
            }
            cout << endl;

            attempts--;
        }

        cout << "Out of attempts! The word was: " << secretWord << endl;
    }
    else if (choice == 2) {
        cout << "\033[1mRULES:\033[0m" << endl;
        cout << "Each guess must be a valid five-letter word.\n";
        cout << "The color of a tile will change to show you how close your guess was:\n";
        cout << "- \033[32mGreen\033[0m: Correct letter in the correct spot.\n";
        cout << "- \033[33mYellow\033[0m: Correct letter in the wrong spot.\n";
        cout << "- \033[90mGray\033[0m: Letter not in the word.\n";
        cout << "Let's play! Reload the game if you wish! ";
    }

    else if (choice == 3) {
        cout << "Exiting the game. Goodbye!\n";

        cout << "   _____  " << endl;
        cout << "  /     \\ " << endl;
        cout << " | O   O |" << endl;
        cout << " |   ^   |" << endl;
        cout << " |  \\_/  |" << endl;
        cout << "  \\_____/ " << endl;


        return;
    }
}
