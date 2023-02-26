#include "gamesettings.h"
#include <iostream>
#include <limits>
#include <vector>
using std::cout; using std::cin; using std::string;
#define inputfield "\n\t: "
#define endsection string(30, '=')



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