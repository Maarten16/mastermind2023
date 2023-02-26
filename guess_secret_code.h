#pragma once
#include <iostream>
struct black_white{int black; int white;};
using std::cout; using std::cin; using std::string;


char * all_possible_codes(int colours, int length, int total_number);
void guess_user(int colors_number, int code_length, string code);
char* filter_codes(char all_codes[], char code[], int length, int total_number, black_white result);
black_white black_white_scorer(char* position, char* code, int length);
