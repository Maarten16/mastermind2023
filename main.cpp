#include <iostream>
#include <vector>
#include <math.h>
#include "input_secret_code.h"
#include "gamesettings.h"
#include "guess_secret_code.h"

#define inputfield "\n\t: "
#define endsection string(30, '=')

using std::cout; using std::cin; using std::string;



int main() {
    //adjustable variables
    const int minimumcolors = 2;
    const int maximumcolors = 9;
    const int minimumlength = 2;
    const int maximumlength = 9;
    const int minimumguesses = 4;
    const int maximumguesses = 20;
    std::vector<string> colornames = {"blue", "red", "green", "orange", "purple", "yellow", "brown", "pink", "grey"};


            //welcome
    cout << "Hello, welcome to mastermind!\n";
    
    //gamesettings:
    //==================================================================================================================
    
            //choose gamemode
    cout << "Which gamemode do you want to play?\n";
    cout << "Type 'A' if you player to make and guess the code\n";
    cout << "Type 'B' if you want player to make and computer to guess the code\n";
    cout << "Type 'C' if you want computer to make and player to guess the code\n";
    cout << "type 'D' if you want computer to make and guess the code" << inputfield;
    char gamemode = gamemode_input();
    cout << "You chose gamemode " << gamemode << "\n";
    cout << endsection << '\n' << '\n';

            //choose number of colors
    cout << "With how many colors do you want to play?\n" << "Enter a number between " << minimumcolors << " and " << maximumcolors << inputfield;
    const int colors_number = int_input(minimumcolors, maximumcolors);
    cout << "The number of colours you will play with is: " << colors_number << "\n";
    cout << endsection << '\n' << '\n';

            //chose code length
    cout << "How long do you want the code to be?\n" << "Enter a number between " << minimumlength << " and " << maximumlength << inputfield;
    const int code_length = int_input(minimumlength, maximumlength);
    while(code_length == colors_number == 9){
        cout << "please enter a length of max 8 when playing with 9 numbers";
    }
    cout << "The code is " << code_length << " pins long\n";
    cout << endsection << '\n' << '\n';

            //choose ammount of guesses
    cout << "How many guesses do you want available?\n" << "Enter a number between " << minimumguesses << " and " << maximumguesses << inputfield;
    int total_guesses = int_input(minimumguesses, maximumguesses);
    cout << "There will be " << total_guesses << " guesses available\n";
    cout << endsection << '\n' << '\n';

    
    //input_secret_code
    //==================================================================================================================
    
            //determination and input secret code
    string codestr;
    if(gamemode == 'A' || gamemode == 'B'){
        codestr = codeinput_user(colors_number, code_length, colornames);
    }
    else{
        codestr = codeinput_computer(colors_number, code_length);
    }
    cout << codestr << '\n';
    
    //guess_secret_code
    //==================================================================================================================



            //user guesses
    if (gamemode == 'A' || gamemode == 'C'){
        while(total_guesses >= 0){
            string strguess = codeinput_user(colors_number, code_length, colornames);
            char guess[code_length];
            char code[code_length];
            for (int i = 0; i < code_length; i++){
                guess[i] = strguess[i];
                code[i] = codestr[i];
            }
            black_white score = black_white_scorer(guess, code, code_length);
            cout << strguess<< ") score [" << score.black << ' ' << score.white << "]\n";
            total_guesses --;
        }

    }
            //computer guesses
    else{
        int possible_codes_amount = pow(colors_number, code_length);
        //generate all possible combinations
        char * possible = all_possible_codes(colors_number, code_length, possible_codes_amount);
        char guess[code_length];
        char code[code_length];

        for (int i = 0; i < code_length; i++){
            guess[i] = possible[i];
            code[i] = codestr[i];
        }
        black_white score = black_white_scorer(guess, code, code_length);
        cout << code<< '\n';
        cout << ") score [" << score.black << ' ' << score.white << "]\n";
    }
    



//need to delete the heap array
    return 0;
}

