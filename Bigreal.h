//
// Created by acer on 11/3/2023.
//

#ifndef UNTITLED1_BIGREAL_H
#define UNTITLED1_BIGREAL_H
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Bigreal {
    char sign = '+';
    bool ok = true;
    string number,real,output;
public:
    Bigreal(string& number);
    Bigreal operator+(Bigreal& b);
    Bigreal operator-(Bigreal& b);
    bool operator>(Bigreal& b);
    bool operator==(Bigreal& b);
    bool operator<(Bigreal& b);
    void print_number_sign_real();
    void print_result();
};
#endif //UNTITLED1_BIGREAL_H
