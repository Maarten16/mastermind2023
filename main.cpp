#include <iostream>
#include <limits>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define inputfield "\n\t: "
#define endsection std::string(30, '=')

using std::cout; using std::cin;

int int_input(int minimum, int maximum);
char gamemode_input();

int main() {
    //adjustable variables
    int minimumcolors = 2;
    int maximumcolors = 9;
    int minimumlength = 2;
    int maximumlength = 9;
    int minimumguesses = 4;
    int maximumguesses = 20;

    //code
    cout << "Hello, welcome to mastermind!\n";

            //gamemode
    cout << "Which gamemode do you want to play?\n";
    cout << "Type 'A' if you player to make and guess the secret code\n";
    cout << "Type 'B' if you want player to make and computer to guess the secret code\n";
    cout << "Type 'C' if you want computer to make and player to guess the secret code\n";
    cout << "type 'D' if you want computer to make and guess the secret code" << inputfield;
    char gamemode = gamemode_input();
    cout << "You chose gamemode " << gamemode << "\n";
    cout << endsection << '\n' << '\n';

            //colors
    cout << "With how many colors do you want to play?\nEnter a number between " << minimumcolors << " and " << maximumcolors << inputfield;
    int colors_number = int_input(minimumcolors, maximumcolors);
    cout << "The number of colours you play with is: " << colors_number << "\n";
    cout << endsection << '\n' << '\n';

            //length
    cout << "How long do you want the secret code to be?\nEnter a number between " << minimumlength << " and " << maximumlength << inputfield;
    int secret_length = int_input(minimumlength, maximumlength);
    cout << "The secret code is " << secret_length << " pins long\n";
    cout << endsection << '\n' << '\n';
    return 0;
}

    int int_input(int minimum, int maximum){
        int num;
        while (true) {
            if (cin >> num && num >= minimum && num <= maximum) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return num;
            } else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between " << minimum << " and " << maximum << inputfield;
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
            else if (mode == 'b' || mode == 'B'){
                return 'B';
            }
            else if (mode == 'c' || mode == 'C'){
                return 'C';
            }
            else if (mode == 'd' || mode == 'D'){
                return 'D';
            }
            else{
                cout << "invalid input. Please give the letter 'A', 'B, 'C', or 'D" << inputfield;
                cin >> mode;
            }
        }
}