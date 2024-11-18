#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
int main() {
   
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
       "stone", "torch", "ultra", "vivid", "worry", "yield", "zebra", "blaze", "clerk", "doubt",
       "exile", "frown", "glove", "hinge", "inbox", "jolly", "knees", "laser", "mirth", "novel",
       "orbit", "pride", "quilt", "rover", "slope", "tiger", "usher", "viper", "wrist", "yearn",
       "amber", "bison", "creek", "daisy", "ember", "fable", "grove", "hinge", "intro", "jumbo",
       "kudos", "loyal", "mercy", "nerve", "oasis", "pouch", "quake", "relay", "shell", "thorn",
       "unity", "valet", "waive", "zonal", "amber", "beige", "cider", "depot", "ether", "flint",
       "gleam", "hatch", "igloo", "jelly", "karma", "lobby", "mirth", "nudge", "zesty", "angel",
       "bliss", "crane", "dodge", "elite", "force", "grape", "haste", "image", "jumbo", "kneel",
       "lemon", "mango", "nylon", "olive", "pearl", "quake", "rider", "stone", "torch", "ultra"
    };
 
    srand(time(0));
 
    const char* secretWord = secretWords[rand() % (sizeof(secretWords) / sizeof(secretWords[0]))];
    int attempts = 6;
 
    cout << "Welcome to Wordle! Try to guess the 5-letter word.\n";
 
    while (attempts > 0) {
        cout << "Attempts remaining: " << attempts << ". Enter your guess: ";
        char guess[6];
        cin >> guess;
 
bool validGuess = true;
        for (int i = 0; i < 5; i++) {
            if (guess[i] == '\0') {
                validGuess = false;
                break;
            }
        }
 
        if (!validGuess || guess[5] != '\0') {
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
            return 0;
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
 