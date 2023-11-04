#include "Bigreal.h"
using namespace std;
Bigreal::Bigreal(string& num){
    if(regex_match(num,regex("[+-]?\\d*.?\\d+"))){
        if(num[0]=='-'&&num[1]=='.'){
            sign = '-';
            num[0] = '0';
        }
        else if(num[0]=='-'&&num[1]!='.'){
            sign = '-';
        }
        auto it = num.find('.');
        if(it!=string::npos&& isdigit(num[0])||it!=string::npos&& isdigit(num[1])){
            if(num[0]=='+'||num[0]=='-'){
                number = num.substr(1, num.find('.')-1); }
            else
                number = num.substr(0, num.find('.'));
            if(num[0]=='+'||isdigit(num[0])){
                real = num.substr(number.size() + 1, num.size() - 1); }
            else
                real = num.substr(number.size() + 2, num.size() - 1);
        }
        else if(it!=string::npos&&isdigit(num[1])){
            real = num.substr(1, num.size() - 1);
        }
        else{
            number = num;
        }
    }
    if(number.empty()){
        number = "0";
    }
    if(real.empty()){
        real = "0";
    }
}
Bigreal Bigreal::operator+(Bigreal b) {
    Bigreal d;
    if(sign == b.sign) {
        d.sign = sign;
        if (number.size() > b.number.size()) {
            for (int i = 0; i < (int) number.size() - (int) b.number.size(); ++i) {
                b.number.insert(0, "0");
            }
        } else if (number.size() < b.number.size()) {
            for (int i = 0; i < (int) b.number.size() - (int) number.size(); ++i) {
                number.insert(0, "0");
            }
        }
        if (real.size() > b.real.size()) {
            int x = (int) real.size() - (int) b.real.size();
            for (int i = 0; i < x; ++i) {
                b.real.push_back('0');
            }
        } else if (real.size() < b.real.size()) {
            int x = (int) real.size() - (int) b.real.size();
            for (int i = 0; i < x; ++i) {
                real.push_back('0');
            }
        }
        deque<int> integar1, integar2, result_int, real1, real2, result_real;
        for (int i = 0; i < number.size(); ++i) {
            integar1.push_back(number[i] - '0');
            integar2.push_back(b.number[i] - '0');
        }
        for (int i = 0; i < real.size(); ++i) {
            real1.push_back(real[i] - '0');
            real2.push_back(b.real[i] - '0');
        }
        int carry_real = 0, carry_integar = 0, carry_dot = 0;
        for (int i = (int) real1.size() - 1; i >= 0; --i) {
            if (real1[i] + real2[i] >= 10 && i == (int) real1.size() - 1) {
                carry_dot++;
                result_real.push_front((real1[i] + real2[i]) % 10);
            } else if (real1[i] + real2[i] + carry_real >= 10) {
                result_real.push_front((real1[i] + real2[i] + carry_real) % 10);
                carry_real = 0;
                (i == 0 ? carry_dot++ : carry_real++);
            } else {
                result_real.push_front(real1[i] + real2[i] + carry_real);
                carry_real = 0;
            }
        }
        for (int i = (int) integar1.size() - 1; i >= 0; --i) {
            if (carry_dot == 1) {
                if (integar1[i] + integar2[i] + carry_dot >= 10) {
                    carry_integar++;
                    result_int.push_front((integar1[i] + integar2[i] + carry_dot) % 10);
                    carry_dot = 0;
                } else {
                    result_int.push_front(integar1[i] + integar2[i] + carry_dot);
                    carry_dot = 0;
                }
            } else {
                if (integar1[i] + integar2[i] + carry_integar >= 10) {
                    carry_integar = 0;
                    result_int.push_front((integar1[i] + integar2[i] + carry_integar) % 10);
                    carry_integar++;
                } else if (integar1[i] + integar2[i] + carry_integar >= 10 && i == 0) {
                    result_int.push_front((integar1[i] + integar2[i] + carry_integar) % 10);
                    result_int.push_front(1);
                    carry_integar = 0;
                } else if (integar1[i] + integar2[i] + carry_integar < 10) {
                    result_int.push_front(integar1[i] + integar2[i] + carry_integar);
                    carry_integar = 0;
                }
            }
        }
        for (int i: result_int) {
            d.number += to_string(i);
        }
        for (int i: result_real) {
            d.real += to_string(i);
        }
        return d;
    }
    else{
        b.sign = (b.sign=='+'?'-':'+');
        return this->operator-(b);
    }
}

bool Bigreal::operator==(Bigreal &b) {
    if (number.size() > b.number.size()) {
        for (int i = 0; i < (int) number.size() - (int) b.number.size(); ++i) {
            b.number.insert(0, "0");
        }
    } else if (number.size() < b.number.size()) {
        for (int i = 0; i < (int) b.number.size() - (int) number.size(); ++i) {
            number.insert(0, "0");
        }
    }
    if (real.size() > b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            b.real.push_back('0');
        }
    } else if (real.size() < b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            real.push_back('0');
        }
    }
    deque<int> integar1, integar2, result_int, real1, real2, result_real;
    for (int i = 0; i < number.size(); ++i) {
        integar1.push_back(number[i] - '0');
        integar2.push_back(b.number[i] - '0');
    }
    for (int i = 0; i < real.size(); ++i) {
        real1.push_back(real[i] - '0');
        real2.push_back(b.real[i] - '0');
    }
    bool equal  = true;
    for (int i = 0; i < integar1.size()&&equal; ++i) {
        if(integar1[i]!=integar2[i]){
            equal = false;
        }
    }
    for (int i = 0; i < real1.size()&&equal; ++i) {
        if(integar1[i]!=integar2[i]){
            equal = false;
        }
    }
    if(equal){
        return true;
    }
    else{
        return false;
    }
}
bool Bigreal::operator<(Bigreal &b) {
    if (number.size() > b.number.size()) {
        for (int i = 0; i < (int) number.size() - (int) b.number.size(); ++i) {
            b.number.insert(0, "0");
        }
    } else if (number.size() < b.number.size()) {
        for (int i = 0; i < (int) b.number.size() - (int) number.size(); ++i) {
            number.insert(0, "0");
        }
    }
    if (real.size() > b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            b.real.push_back('0');
        }
    } else if (real.size() < b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            real.push_back('0');
        }
    }
    if(sign=='+'&&b.sign=='-'){
        return false;
    }else if(sign=='-'&&b.sign=='-'||sign=='+'&&b.sign=='+'){
        if(number<b.number){
            return true;
        }
        else if(number>b.number){
            return false;
        }
        else{
            if(real<b.real){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return true;
    }
}
bool Bigreal::operator>(Bigreal &b) {
    if (number.size() > b.number.size()) {
        for (int i = 0; i < (int) number.size() - (int) b.number.size(); ++i) {
            b.number.insert(0, "0");
        }
    } else if (number.size() < b.number.size()) {
        for (int i = 0; i < (int) b.number.size() - (int) number.size(); ++i) {
            number.insert(0, "0");
        }
    }
    if (real.size() > b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            b.real.push_back('0');
        }
    } else if (real.size() < b.real.size()) {
        int x = (int) real.size() - (int) b.real.size();
        for (int i = 0; i < x; ++i) {
            real.push_back('0');
        }
    }
    if(sign=='-'&&b.sign=='+'){
        return false;
    }else if(sign=='-'&&b.sign=='-'||sign=='+'&&b.sign=='+'){
        if(number>b.number){
            return true;
        }
        else if(number<b.number){
            return false;
        }
        else{
            if(real>b.real){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        return true;
    }
}
Bigreal Bigreal::operator-(Bigreal b) {
    Bigreal d;
    if(sign==b.sign){
        if (number.size() > b.number.size()) {
            for (int i = 0; i < (int) number.size() - (int) b.number.size(); ++i) {
                b.number.insert(0, "0");
            }
        } else if (number.size() < b.number.size()) {
            for (int i = 0; i < (int) b.number.size() - (int) number.size(); ++i) {
                number.insert(0, "0");
            }
        }
        if (real.size() > b.real.size()) {
            int x = (int) real.size() - (int) b.real.size();
            for (int i = 0; i < x; ++i) {
                b.real.push_back('0');
            }
        } else if (real.size() < b.real.size()) {
            int x = (int) real.size() - (int) b.real.size();
            for (int i = 0; i < x; ++i) {
                real.push_back('0');
            }
        }
        deque<int> integar1, integar2, result_int, real1, real2, result_real;
        for (int i = 0; i < number.size(); ++i) {
            integar1.push_back(number[i] - '0');
            integar2.push_back(b.number[i] - '0');
        }
        for (int i = 0; i < real.size(); ++i) {
            real1.push_back(real[i] - '0');
            real2.push_back(b.real[i] - '0');
        }
        int sub_carry = 0;
        if(*this>b){
            d.sign = sign;
            for (int i = (int)real1.size()-1; i >=0 ; --i) {
                if(real1[i]-real2[i]-sub_carry>=0){
                    result_real.push_front(real1[i]-real2[i]-sub_carry);
                    sub_carry = 0;
                }
                else if(real1[i]-real2[i]-sub_carry<0){
                    result_real.push_front((real1[i]-real2[i]-sub_carry)+10);
                    sub_carry = 1;
                }
            }
            for (int i = (int)integar1.size()-1; i >=0 ; --i) {
                if(integar1[i]-integar2[i]-sub_carry>=0){
                    result_int.push_front(integar1[i]-integar2[i]-sub_carry);
                    sub_carry = 0;
                }
                else if(integar1[i]-integar2[i]-sub_carry<0){
                    result_real.push_front((integar1[i]-integar2[i]-sub_carry)+10);
                    sub_carry = 1;
                }
            }
        }
        else{
            d.sign = (b.sign=='+'?'-':'+');
            for (int i = (int)real1.size()-1; i >=0 ; --i) {
                if(real2[i]-real1[i]-sub_carry>=0){
                    result_real.push_front(real2[i]-real1[i]-sub_carry);
                    sub_carry = 0;
                }
                else if(real2[i]-real1[i]-sub_carry<0){
                    result_real.push_front((real2[i]-real1[i]-sub_carry)+10);
                    sub_carry = 1;
                }
            }

            for (int i = (int)integar1.size()-1; i >=0 ; --i) {
                if(integar2[i]-integar1[i]-sub_carry>=0){
                    result_int.push_front(integar2[i]-integar1[i]-sub_carry);
                    sub_carry = 0;
                }
                else if(integar2[i]-integar1[i]-sub_carry<0){
                    result_int.push_front((integar2[i]-integar1[i]-sub_carry)+10);
                    sub_carry = 1;
                }
            }
        }
        for (int i: result_int) {
            d.number += to_string(i);
        }
        for (int i: result_real) {
            d.real += to_string(i);
        }
        return d;
    }
    else{
        b.sign = (b.sign=='+'?'-':'+');
        return this->operator+(b);
    }
}
ostream &operator<<(ostream &out, const Bigreal& num){
    out<<num.sign<<num.number<<"."<<num.real<<'\n';
    return out;
}
int Bigreal::size(){
    return (int)number.size()+(int)real.size()+1;
}
char Bigreal::sign_of_Bigreal() const{
    return sign;
}
Bigreal Bigreal::set_values() {
    string s;
    cin>>s;
    Bigreal a(s);
    return a;
}
