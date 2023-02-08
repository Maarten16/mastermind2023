#include <iostream>
#include <limits>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define inputfield "\n\t: "
#define endsection string(30, '=')

using std::cout; using std::cin; using std::string;

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

            //gamemode
    cout << "Which gamemode do you want to play?\n";
    cout << "Type 'A' if you player to make and guess the code\n";
    cout << "Type 'B' if you want player to make and computer to guess the code\n";
    cout << "Type 'C' if you want computer to make and player to guess the code\n";
    cout << "type 'D' if you want computer to make and guess the code" << inputfield;
    char gamemode = gamemode_input();
    cout << "You chose gamemode " << gamemode << "\n";
    cout << endsection << '\n' << '\n';

            //colors
    cout << "With how many colors do you want to play?\n" << "Enter a number between " << minimumcolors << " and " << maximumcolors << inputfield;
    int colors_number = int_input(minimumcolors, maximumcolors);
    cout << "The number of colours you will play with is: " << colors_number << "\n";
    cout << endsection << '\n' << '\n';

            //length
    cout << "How long do you want the code to be?\n" << "Enter a number between " << minimumlength << " and " << maximumlength << inputfield;
    int code_length = int_input(minimumlength, maximumlength);
    cout << "The code is " << code_length << " pins long\n";
    cout << endsection << '\n' << '\n';

            //guesses
    cout << "How many guesses do you want to have?\n" << "Enter a number between " << minimumguesses << " and " << maximumguesses << inputfield;
    int total_guesses = int_input(minimumguesses, maximumguesses);
    cout << "You will have " << total_guesses << " guesses\n";
    cout << endsection << '\n' << '\n';

            //code input
    if(gamemode == 'A' || gamemode == 'B'){
        string code = codeinput_user(colors_number, code_length, colornames);
        cout << code;
    }
    else{
        string code = codeinput_computer(colors_number, code_length);
        cout << code;
    }






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



    while(codelength > 0){// will become validate_color
        cin >> color;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                cout << "invalid input";
            }
        }
        else{
            for(int i = 0; i < colors_num; i++){
                if (color == colornames[i]){
                    code += char(ASCI_upper + i);
                    codelength--;
                    break;
                }
                cout << "invalid input";
            }
        }
    }
    return code;
}