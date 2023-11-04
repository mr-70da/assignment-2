#include "Bigreal.cpp"
using namespace std;

string menu(string& operation){
    cout<<"To compare enter please choose if you want to see if they are:\n"
          "     Equal press =\n"
          "     Greater press >\n"
          "     less press < \n"
          "To show the number press print\n"
          "To show sign enter sign\n"
          "To show the size enter size\n"
          "To print the sum enter sum\n"
          "To print the subtraction enter subtract\n"
          "If you want to change the value of the first number enter set1\n"
          "If you want to change the value of the second number enter set2\n"
          "To exit press 0\n";
    cin>>operation;
    return operation;
}
void operations(string& operation,Bigreal& a,Bigreal& b){
    Bigreal c;
    if(operation == "set1"){
        cout<<"Please enter the new first number:\n";
        a = a.set_values();
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="set2"){
        cout<<"Please enter the new second number:\n";
        b = b.set_values();
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation==">"){
        if(a>b){
            cout<<"The first number is greater than the second number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
        else{
            cout<<"The second number is greater than the first number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
    }
    else if(operation=="<"){
        if(a<b){
            cout<<"The first number is less than the second number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
        else{
            cout<<"The second number is less than the first number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
    }
    else if(operation=="="){
        if(a==b){
            cout<<"The first number is equal to the second number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
        else{
            cout<<"The first number is not equal to the second number.\n";
            menu(operation);
            return operations(operation,a,b);
        }
    }
    else if(operation=="print"){
        cout<<"The first number = "<<a;
        cout<<"The second number = "<<b;
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="sign"){
        cout<<"The sign of the first number is "<<a.sign_of_Bigreal();
        cout<<"The sign of the second number is "<<b.sign_of_Bigreal();
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="size"){
        cout<<"The size of the first number is "<<a.size();
        cout<<"The size of the second number is "<<b.size();
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="sum"){
        c = a+b;
        cout<<"The sum of "<<a<<" and "<<b<<" = "<<c<<'\n';
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="subtract"){
        c = a-b;
        cout<<"The subtraction of "<<a<<" and "<<b<<" = "<<c<<'\n';
        menu(operation);
        return operations(operation,a,b);
    }
    else if(operation=="0"){
        cout<<"Thank you for working with us\n";
    }
    else{
        cout<<"Please choose the right operation:\n";
        menu(operation);
        return operations(operation,a,b);
    }

}
void solve(){
    string s1,s2,operation;
    cout<<"Please put the first correct big real numbers: \n";
    getline(cin,s1);
    cout<<"Please put the second correct big real numbers: \n";
    getline(cin,s2);
    Bigreal a(s1),b(s2),c;
    cout<<"To compare enter please choose if you want to see if they are:\n"
          "     Equal press =\n"
          "     Greater press >\n"
          "     less press < \n"
          "To show the number press print\n"
          "To show sign enter sign\n"
          "To show the size enter size\n"
          "To print the sum enter sum\n"
          "To print the subtraction enter subtract\n"
          "If you want to change the value of the first number enter set1\n"
          "If you want to change the value of the second number enter set2\n"
          "To exit press 0\n";
    cin>>operation;
    operations(operation,a,b);
}
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
