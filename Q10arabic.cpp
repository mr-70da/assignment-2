#include <bits/stdc++.h>
using namespace std;
#define ii int
#define vi vector <int> v ;
#define vll vector<ll>;
#define ss string
#define f(i,a,b)      for(ll i=a;i<b;i++)
#define fr(i,a,b)     for(ii i=b-1;i>=0;i--)
#define ll long long
ll calc(ll x1 , ll y1 , ll x2 , ll y2)
{
    ll ans = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    return ans;
}
ll factorial(int N){
    if(N>1){
        return N*factorial(N-1);

    }else{
        return 1;
    }

}
vector<string> split(string target, char delimiter){
    vector<string>splited_text;
    string temp;
    for(int i =0  ; i<target.size();i++ ){
        if(target[i] == delimiter)
        {
            splited_text.push_back(temp);
            temp="";
        }
        else{
            temp += target[i];
        }
    }splited_text.push_back(temp);
    return splited_text;

}
string encryption(string word){
    map<string,string>replacment;
    replacment.insert(make_pair("فلسطين","فـلـ.سـط.ين"));
    replacment.insert(make_pair("غزة","عْـزة"));
    replacment.insert(make_pair("حماس","حـ.ما.س"));
    replacment.insert(make_pair("قتل","قـ.ـتـ.ل"));
    replacment.insert(make_pair("حرب","حـ.ر.ب"));
    replacment.insert(make_pair("ارهاب","ار.هـ.اب"));
    replacment.insert(make_pair("جهاد","جـ.ها.د"));
    replacment.insert(make_pair("صهاينة","صـ.هايـ.نـة"));
    replacment.insert(make_pair("عدوان","عـ.د.وان"));
    replacment.insert(make_pair("قتلة","قـ.تـ.لة"));
    replacment.insert(make_pair("اسرائيل","اسر.ائـ.يل"));
    replacment.insert(make_pair("هجوم","هـ.جوم"));
    replacment.insert(make_pair("ذبح","ذبـ.ـح"));
    replacment.insert(make_pair("قطع","قـ.طـ.ـع"));
    for(auto I:replacment){
        if(word == I.first){
            return I.second;
        }
    }return word;

}
int main() {
   ifstream fin("textin.txt");
   ofstream fout("textout.txt");
   string word;
   while(getline(fin,word)){
       vector<string>s=split(word,' ');
       for(auto I:s){fout<<encryption(I)<<' ';}
   }
   fin.close();
   fout.close();



}
