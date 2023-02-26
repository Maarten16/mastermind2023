#include "guess_secret_code.h"

char * all_possible_codes(const int colours, const int length, const int total_number){
    int size = total_number * length;
    //try catch to see memory available
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

    };
    return all_codes;

}

void guess_user(int colors_number, int code_length, string code){
    cout << colors_number, code_length, code;
}

char* filter_codes(char * all_codes, char* guess, int length, int total_number, black_white score){
    char* filtered_codes = new char[total_number * length + 1];
    char* filtered_position = filtered_codes;
    for(int i = 0; i < total_number; i++){
        black_white result = black_white_scorer(all_codes, guess, length);
        if ((result.white == score.white) && (result.black == score.black)){
            for(int i = 0; i < length; i++){
                filtered_position[i] = all_codes[i];
            }
            filtered_position+= length;
        }
        all_codes += length;
    }
    return filtered_codes;
}

inline black_white black_white_scorer(char* comp, char* code, int length){
    char codecp[length];
    char compcp[length];
    for (int i = 0; i < length; i++) {
        codecp[i] = code[i];
        compcp[i] = comp[i];
    }
    black_white score;
    score.black = 0; score.white = 0;
    for(int i = 0; i < length; i++){
        if (codecp[i] == compcp[i]){
            score.black++;
            codecp[i] = 'x';
            compcp[i] = 'y';
        }
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(codecp[i] == compcp[j]){
                score.white++;
                codecp[i] = 'x';
                compcp[j] = 'y';
            }
        }
    }
    return score;
}
