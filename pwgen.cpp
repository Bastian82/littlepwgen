//
// Created by grzempek on 20.10.16.
//
#include "pwgen.h"
#include <iostream>

char PasswordGenerator::letter_gen(){

    int v = rand() % 23;
    char letter;
    if ((rand() % 100)%2 == 0){
       letter = letters[v];
    } else {
       letter =  toupper(letters[v]);
    }

    return letter;
}

int PasswordGenerator::numbers_gen(){

    int v = rand() % 10;
    return numbers[v];

}

char PasswordGenerator::special_gen(){

    int v = rand() % 21;
    char special = specials[v];
    return special;
}

void PasswordGenerator::produce_pass(int pass_length = 10, int pass_count = 10) {

    string pass[pass_count];
    srand((unsigned int) time(NULL));
    for (int x = 0; x < pass_count; x++) {
        pass[x] = "";
        string v;
        for (int y = 0; y < pass_length; y++){
            if ((rand() % 100)%2 == 0){
              pass[x] += letter_gen();
            } else if ((rand() % 100)%3 == 0){
              pass[x] +=  to_string(numbers_gen());
            } else {
              pass[x] +=  special_gen();
            }

        }
    }

    for (int x = 0; x < pass_count; x++) {
       cout << pass[x] << "\n";
    }
}

