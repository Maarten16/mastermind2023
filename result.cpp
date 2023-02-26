#include "result.h"
void congratulate(){
    std::cout << "congratulations! the correct code has been guessed!";
    std::exit(0);
}

void consolation(){
    std::cout << "unfortunately you have not guessed the code in time";
    std::exit(0);
}