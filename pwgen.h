//
// Created by grzempek on 20.10.16.
//

#ifndef PIASKOWNICA_PWGEN_H
#define PIASKOWNICA_PWGEN_H
#include <string>

using namespace std;

class PasswordGenerator {

 public:
    char letters[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'w', 'x', 'y', 'z'};
    const int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    const char specials[21] = {'!','@','#','$','%','^','&','(',')',',','<','>','?','[',']','|','~','+','=','_','.'};
    char letter_gen();
    int numbers_gen();
    char special_gen();
    void produce_pass(int pass_length, int pass_count);
};

#endif //PIASKOWNICA_PWGEN_H