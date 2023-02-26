#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
#include "input_secret_code.h"
using std::cout; using std::cin; using std::string;
#define inputfield "\n\t: "
#define endsection string(30, '=')



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