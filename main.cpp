#include <iostream>
#include <limits>
#define inputfield "\n\t: "
using std::cout; using std::cin;

int length_input();
char gamemode_input();

int main() {
    cout << "Hello, welcome to mastermind.\n";
    cout << "How long do you want the secret code to be?\nEnter a number between 0 and 10" << inputfield;
    int secret_length = length_input();
    cout << "The secret code is " << secret_length << " pins long\n";
    cout << "Which gamemode do you want to play?\n";
    cout << "Type 'A' if you player to make and guess the secret code\n";
    cout << "Type 'B' if you want player to make and computer to guess the secret code\n";
    cout << "Type 'C' if you want computer to make and player to guess the secret code\n";
    cout << "type 'D' if you want computer to make and guess the secret code" << inputfield;
    char gamemode = gamemode_input();
    cout << "You chose gamemode " << gamemode;
    return 0;
}

    int length_input(){
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

    char gamemode_input(){
    char mode;
    cin >> mode;
    while(true){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (mode == 'a' || mode == 'A'){
            return 'A';
        }
        else if (mode == 'a' || mode == 'A'){
            return 'B';
        }
        else if (mode == 'a' || mode == 'A'){
            return 'C';
        }
        else if (mode == 'a' || mode == 'A'){
            return 'D';
        }
        else{
            cout << "invalid input. Please give the letter 'A', 'B, 'C', or 'D" << inputfield;
            cin >> mode;
        }
    }
}