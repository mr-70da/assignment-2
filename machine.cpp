#include "Machine.h"
using namespace std;

Memory::Memory() {
    for (int i = 0; i < 256; ++i) {
        cells[i] = 0;
    }
}

int Memory::read(int Address) {
    return cells[Address];
}

void Memory::write(int Address, int Value) {
    cells[Address] = Value;
}

bitset<8> Instruction::Bits(int number) {
    auto bits1 = bitset<sizeof(int) * 2>(number);
    return bits1;
}

void Machine::read_memory(int programcounter,Memory mem) {
    int op = mem.read(programcounter) / 10;
    int operand1 = mem.read(programcounter) % 10;
    int operand2 = mem.read(programcounter + 1);
    stringstream stream1,stream2,stream3;
    stream1 << std::hex << op;
    stream2 << std::hex << operand1;
    stream3 << std::hex << operand2;
    string result,op1 = stream1.str(),op2 = stream2.str(),op3 = stream3.str();
    result+="0x"+op1+" 0x"+op2+" 0x"+op3;
    executeStep(result);
}

void Machine::loadProgram(const string &fileName) {
    ifstream Filename(fileName,ios::in);
    string operations;
    int count_line = 1;
    while(getline(Filename,operations)){
        if(instructions.fetch(operations)){
            executeStep(operations);
        }
        else{
            cout<<"There is an invalid operation in line number "<<count_line<<'\n';
        }
        count_line++;
    }
}

void Register::write_register_address(int operand1,int operand2,Memory mem) {
    arr[operand1] = mem.read(operand2);
}

int Register::get_register(int operand1) {
    return arr[operand1];
}

void Register::write_register(int operand1, int operand2) {
    arr[operand1] = operand2;
}

bool Instruction::fetch(string& operation) {
    bool right[3]{false,false,false};
    if(isxdigit(static_cast<unsigned char>(operation[2]))){
        right[0] = true;
    }
    if (isxdigit(static_cast<unsigned char>(operation[6]))){
        right[1] = true;
    }
    if(isxdigit(static_cast<unsigned char>(operation[10]))&&isxdigit(static_cast<unsigned char>(operation[11]))){
        right[2] = true;
    }
    if(operation[2]=='4'&&operation[6]!='0'&&isxdigit(static_cast<unsigned char>(operation[10]))&&
    isxdigit(static_cast<unsigned char>(operation[11]))){
        return false;
    }
    if(operation[2]=='C'&&operation[6]!='0'&&operation[10]!='0'&&operation[11]!='0'){
        return false;
    }
    if(right[0]&&right[1]&&right[2]){
        return true;
    }
    else{
        return false;
    }
}

void Instruction::case_three(int operand1, int operand2,Memory& memory,Register registers) {
    if(operand2!=0) {
        int copy;
        copy = registers.get_register(operand1);
        memory.write(operand2, copy);
    }
    else{
        cout<<"The register number "<<operand1<<" has points to ";
        cout<<registers.get_register(operand1)<<"\n";
    }
}

void Instruction::case_four(string subst, Register& registers) {
    int copy,register1,register2;
    register1 = stoi(string(1,subst[2]),nullptr,16);//0x42
    copy = registers.get_register(register1);
    register2 = stoi(string(1,subst[3]),nullptr,16);
    registers.write_register(register2,copy);
}

void Instruction::case_five(string subst,string result, bitset<8> bits1, bitset<8> bits2, bitset<8> result_bits,
                            Register &registers,int operand1) {
    int register1,register2;
    register1 = stoi(string(1,subst[2]),nullptr,16);
    register2 = stoi(string(1,subst[3]),nullptr,16);
    bits1 = Bits(registers.get_register(register1));
    bits2 = Bits(registers.get_register(register2));
    int i,carry;
    carry= 0;
    i = 0;
    while(i<8){
        if(bits1[i]+bits2[i]+carry>1){
            if(bits1[i]+bits2[i]+carry==2)
                result_bits.reset(i);
            else
                result_bits.set(i);
            carry = 1;
        }
        else{
            if(bits1[i]+bits2[i]+carry==0) {
                result_bits.reset(i);
            }
            else{
                result_bits.set(i);
            }
            carry = 0;
        }
        i++;
    }
    result = result_bits.to_string();
    registers.write_register(operand1,(int)bitset<8>(result).to_ulong());
}

void Machine::executeStep(string & s) {
    int op = stoi(s.substr(0, 3), nullptr, 16);
    int operand1 = stoi(s.substr(4, 3), nullptr, 16);
    string subst = s.substr(8, 4);
    int operand2 = stoi(subst, nullptr, 16);
    bitset<8>bits1,bits2,result_bits,xr;string result;
    memory.write(programCounter++,op*10+operand1);
    memory.write(programCounter++,operand2);
    switch (op) {
        case 1:
            registers.write_register_address(operand1,operand2,memory);
            break;
        case 2:
            registers.write_register(operand1,operand2);
            break;
        case 3:
            instructions.case_three(operand1,operand2,memory,registers);
            break;
        case 4:
            instructions.case_four(subst,registers);
            break;
        case 5:
            instructions.case_five(subst,result,bits1,bits2,result_bits,registers,operand1);
            break;
        case 11:
            int copy;
            if(registers.get_register(operand1)==registers.get_register(0)){
                copy = programCounter;
                programCounter = operand2;
                for (int j = 0; j < (int)copy/2; ++j) {
                    read_memory(programCounter,memory);
                }
            }
            break;
        case 12:
            cout<<"Finished code Successfully\n";
            EXIT_SUCCESS;
            break;
        default:
            cout<<"Invalid operation \n";
    }
}

