#ifndef UNTITLED1_BIGREAL_H
#define UNTITLED1_BIGREAL_H
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Bigreal {
    char sign = '+';
    string number,real;
public:
    Bigreal(){
        sign = '+';
        number = "",real = "";
    };
    int size();
    [[nodiscard]] char sign_of_Bigreal() const;
    explicit Bigreal(string& number);
    static Bigreal set_values();
    friend bool check(Bigreal& b);
    Bigreal operator+(Bigreal b);
    Bigreal operator-(Bigreal b);
    bool operator>(Bigreal& b);
    bool operator==(Bigreal& b);
    bool operator<(Bigreal& b);
    friend ostream &operator<<(ostream &out, const Bigreal& num);
};
#endif //UNTITLED1_BIGREAL_H
