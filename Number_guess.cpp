#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    int numberToGuess = rand() % 100 + 1;       // Random number between 1 and 100
    int playerGuess = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    while (playerGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> playerGuess;

        if (playerGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else if (playerGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }
    }

    return 0;
}