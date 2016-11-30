//
// Created by grzempek on 20.10.16.
//
#include "pwgen.h"
#include <iostream>
#include <vector>
#include <algorithm>

char PasswordGenerator::letter_gen(int & upper){

  char letter;
  int v = rand() % 23;
  if (upper == -1 ) {
    if ((rand() % 100)%2 == 0){
      letter = letters[v];
    } else {
      letter =  toupper(letters[v]);
    }
  } else {
    if (upper > 0){
      letter = toupper(letters[v]);
      --upper;
    } else {
      letter = letters[v];
    }
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

  std::random_shuffle(ch_arr.begin(), ch_arr.end());

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
    int upper_per_iter = Howmany.uppercase;
    for (unsigned int x =0; x < Howmany.letters; x++) {
      char_arr.push_back(letter_gen(upper_per_iter));
    }
    for (unsigned int x =0; x < Howmany.numbers; x++) {
      number_arr.push_back(numbers_gen());
    }
    for (unsigned int x =0; x < Howmany.specials; x++) {
      char_arr.push_back(special_gen());
    }
    mixup(char_arr, number_arr);
    cout << "\n";
    char_arr.clear();
    number_arr.clear();
  }
}

