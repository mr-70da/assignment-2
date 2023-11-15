// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <bits/stdc++.h>
#include "Machine.cpp"
using namespace std;
int menu(Machine& machine,int& operation){
    cout<<"There is a menu to choose from the operation you want:\n"
          "     If you want to exit press 0:\n"
          "     To load a new program from a file press 1: \n"
          "     To fetch instructions to IR press 2: \n"
          "     To display the status of the registers and memory press 3: \n";
    cin>>operation;
    cin.ignore();
    string filename,command;
    switch (operation) {
        case 1:
            cout<<"Please enter the file name:\n";
            getline(cin,filename);
            filename+=".txt";
            machine.loadProgram(filename);
            break;
        case 2:
            cout<<"put the operation you want to execute like 0x1 0x0 0xA3 means 10A3:\n";
            getline(cin,command);
            if(machine.instructions.fetch(command)){ machine.executeStep(command); }
            else
                cout<<"There is an invalid operation in this line "<<'\n';
            break;
        case 3:
            cout<<"Program Counter = "<<machine.programCounter/2<<'\n';
            cout<<"Registers: \n";
            for (int i = 0; i < 16; ++i) {
                cout<<"r"<<::hex<<i<<" points to "<<::hex<<machine.registers.get_register(i)<<'\n';
            }
            cout<<"Memory: \n";
            for (int i = 0; i < 256; ++i) {
                if(i<16){ cout<<0;}
                if(i%2==0)
                    cout << ::hex << i << " has a value of " <<::dec << machine.memory.read(i) << '\n';
                else
                    cout << ::hex << i << " has a value of " << ::hex<< machine.memory.read(i) << '\n';
            }
            cout<<"IR: "<<'\n';
            for (int i = 0,count = 0; i < 32; i+=2,count++) {
                cout<<"IR"<<::hex<<count<<" has a operation of "<<::hex<<(int)machine.memory.read(i)/10<<'\n';
            }
            break;
        case 0:
            return operation;
        default:
            cout<<"Invalid operation please choose a valid one: \n";
            menu(machine,operation);
    }
    return operation;
}
void solve(){
    Machine machine;
    int operation=1;
    while(operation!=0){
        menu(machine,operation);
    }
    cout<<"Thank you for working with us\n";
}
int main(){
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
}
