#ifndef UNTITLED1_MACHINE_H
#define UNTITLED1_MACHINE_H
#include <bits/stdc++.h>
using namespace std;
class Memory{
protected:
    map<int,int>cells;
public:
    Memory();
    int read(int Address);
    void write(int Address,int Value);
};
class Register{
protected:
    int arr[16] = {0};
public:
    int get_register(int operand1);
    void write_register_address(int operand1,int operand2,Memory mem);
    void write_register(int operand1,int operand2);
};
class Instruction{
public:
    bool fetch(string& operation);
    void case_three(int operand1,int operand2,Memory& mem,Register reg);
    void case_four(string subst,Register& registers);
    static bitset<8> Bits(int number);
    void case_five(string subst,string result,bitset<8> bits1,bitset<8> bits2,bitset<8> result_bits,bitset<8> xr,
                   Register& registers,int operand1);
};
class Machine{
public:
    int programCounter;
    Instruction instructions;
    Register registers;
    Memory memory;
    Machine():programCounter(0){}
    void loadProgram(const string& fileName);
    void executeStep(string& s);
    void read_memory(int programCounter,Memory mem);
};
#endif //UNTITLED1_MACHINE_H
