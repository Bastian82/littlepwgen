//
// Created by grzempek on 20.10.16.
//
#include "pwgen.h"
#include <iostream>
#include <vector>

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

void PasswordGenerator::mixup(vector<char> ch_arr,vector<int> int_arr) {

/*
    for (int x=0; x< ch_arr.size(); x++) {
        cout << ch_arr[x];
    }

    for (int x=0; x< int_arr.size(); x++) {
        cout << int_arr[x];
    }

        // wybierz jedna litere z ch_arr do cout
        vector<char>::iterator iter = ch_arr.begin();
        for (iter; iter < ch_arr.end(); iter++) {
            cout << *iter;
            iter = ch_arr.erase(iter);
        }
        // wybierz jedna litere z int_arr do cout
        vector<int>::iterator iter2 = int_arr.begin();
        for (iter2; iter2 < int_arr.end(); iter2++) {
            cout << *iter2;
            iter2 = int_arr.erase(iter2);
        }
*/
    while (!ch_arr.empty() || !int_arr.empty()) {

        if ((rand() % 100)%2 == 0){

            if (!ch_arr.empty()) {
                cout << *ch_arr.begin();
                ch_arr.erase(ch_arr.begin());
            }

        } else {

            if (!int_arr.empty()) {
                cout << *int_arr.begin();
                int_arr.erase(int_arr.begin());
            }

        }
    }

}

void PasswordGenerator::produce_pass(int pass_count, PassCounter Howmany) {

    string pass[pass_count];
    srand((unsigned int) time(NULL));
    std::vector<char> char_arr;
    std::vector<int> number_arr;
    for (int x = 0; x < pass_count; x++) {
    /*
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
    */

        for (int x =0; x < Howmany.letters; x++) {
            char_arr.push_back(letter_gen());
        }

        for (int x =0; x < Howmany.numbers; x++) {
            number_arr.push_back(numbers_gen());
        }

        for (int x =0; x < Howmany.specials; x++) {
            char_arr.push_back(special_gen());
        }

        mixup(char_arr, number_arr);

        cout << "\n";

        char_arr.clear();
        number_arr.clear();
    }

}

