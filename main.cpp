#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
#include <memory>

#define inputfield "\n\t: "
#define endsection string(30, '=')

using std::cout; using std::cin; using std::string;

char * all_possible_codes(int colours, int length, int total_number);
string codeinput_computer(int colors_number, int code_length);
string codeinput_user(int colors_num, int codelength, std::vector<string> &color_names);
int int_input(int minimum, int maximum);
char gamemode_input();


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
    cout << "How many guesses do you want to have?\n" << "Enter a number between " << minimumguesses << " and " << maximumguesses << inputfield;
    int total_guesses = int_input(minimumguesses, maximumguesses);
    cout << "You will have " << total_guesses << " guesses\n";
    cout << endsection << '\n' << '\n';

            //determination and input secret code
    string code;
    if(gamemode == 'A' || gamemode == 'B'){
        code = codeinput_user(colors_number, code_length, colornames);
    }
    else{
        code = codeinput_computer(colors_number, code_length);
    }
    cout << code << '\n';

            //generate all possible combinations
    int possible_codes_number = pow(colors_number, code_length);
    char * possible = all_possible_codes(colors_number, code_length, possible_codes_number);
    cout << possible;





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

string codeinput_computer(int colors_number, int code_length){
    string code = "";
    int random;
    int ASCI_upper = 65;
    for (int i = 0; i < code_length; i++){
        random = (rand() % colors_number);
        code += char(ASCI_upper + random);
    }
    return code;
}

string codeinput_user(int colors_num, int codelength, std::vector<string> &colornames){
    string code = "";
    string color;
    int ASCI_lower = 97;
    int ASCI_upper = 65;

        //display possible inputs
    cout << "please enter your colours one by one. the possible colours are:\n";
    for(int i = 0; i < colors_num; i++){
        cout << char(ASCI_upper + i) << ") " << colornames[i] << '\n';
    }

    while(codelength > 0){// will become validate_color
        //input color
        cout << '\t'<<':';
        cin >> color;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //check input
        if(color.size() == 1){
            int asci = int(color[0]);
            if (asci >= ASCI_upper && asci < ASCI_upper + colors_num){
                code += color[0];
                codelength--;
            }
            else if(asci >= ASCI_lower && asci < ASCI_lower + colors_num){
                asci -= 32;
                code += char(asci);
                codelength--;
            }
            else{
                cout << "invalid input. please try again\n";
            }
        }
        else{
            for(int i = 0; i < colors_num; i++){
                if (color == colornames[i]){
                    code += char(ASCI_upper + i);
                    codelength--;
                    goto new_iter;
                }
            }
            cout << "invalid input. please try again\n";
        }
        new_iter:;
    }
    return code;
}

char * all_possible_codes(const int colours, const int length, const int total_number){
    int size = total_number * length;
    char* all_codes = new char[size + 1]; //dont forget to destroy
    for (int i = 0; i < size; i++){
        all_codes[i] = 'A';
    }
    all_codes[size] = '\0';
    char* position = all_codes; //dont forget to destroy
    int to_add[length];
    for (int i = 0; i < length; i++) {
        to_add [i] = 0;
    }

    for (int i = 0; i < total_number; i++) {
        for (int j = 0; j < length; j++) {
            position[j] += to_add[j];
        }
        if (!(to_add[0] == colours - 1)) {
            to_add[0]++;
        }
        else {
            int i = 1;
            for (; i < length; i++) {
                if (!(to_add[i] == colours - 1)) {
                    to_add[i]++;
                    for (int j = i - 1; j >= 0; j--) {
                        to_add[j] = 0;
                    }
                    break;
                }
            }
        }
        position += length;

    }
    return all_codes;





    return 0;
}




