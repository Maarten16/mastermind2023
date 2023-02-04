#include <iostream>
#include <limits>
#define inputfield "\n\t: "
using std::cout; using std::cin;

int length_input();

int main() {
    cout << "Hello, welcome to mastermind.\n";
    int secret_length = length_input();
    cout << "The secret code is " << secret_length << " pins long\n";
    cout << "Who chooses the combination to be guessed? For the player type: 'p'. For the computer type: 'c'" << inputfield;
    char who_generates_secret;
    cin >> who_generates_secret;
    cout << who_generates_secret;
    return 0;
}

    int length_input(){
        std::cout << "How long do you want the secret code to be?\nEnter a number between 0 and 10" << inputfield;
        int num;
        while (true) {
            if (cin >> num && num > 0 && num < 10) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return num;
            } else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 0 and 10." << inputfield;
            }
        }
    }