#include <iostream>
#include <cstdlib> //library for random number generation
#include <ctime> //library for time

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    srand(time(0));
    int Number = rand() % 101 + 1;
    while(Number == 50 || Number == 25 || Number == 75 || Number == 37 || Number == 62 || Number == 87 || Number == 12 || Number == 6 || Number == 93 || Number == 31){
        Number = rand() % 101 + 1;
    }
    int guessCount = 1;

    cout << "What is your guess?" << endl;
    int guess;
    cin >> guess;

    while(guess != Number){
        if(guess < Number){
            cout << "HIGHER" << endl;
        } else {
            cout << "LOWER" << endl;
        }
        cin >> guess;
        guessCount++;
    }

    cout << "Guesses: " << guessCount << endl;
}