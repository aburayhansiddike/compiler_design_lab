#include<bits/stdc++.h>
using namespace std;


set<string> p = {"he", "she", "I", "we", "you", "they"};
set<string> n = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
set<string> v = {"read", "eat", "take", "run", "write"};
set<string> pn = {"Sagor", "Selim", "Salma", "Nipu"};

vector<string> getAllWords(string str){
    vector<string> words;
    string temp = "";
    for(int i = 0; i < (int)str.size(); i += 1){
        if(str[i] == ' '){
            words.push_back(temp);
            temp = "";
        }else{
            temp += str[i];
        }
    }
    words.push_back(temp);
    return words;
}
int main(){
    string str;
    getline(cin >> ws , str);

    int cntSpace = 0;

    for(int i = 0; i < (int)str.size(); i += 1){
        if(str[i] == ' '){
            cntSpace += 1;
        }
    }

    vector<string> words = getAllWords(str);
    if((int)words.size() == 1){
        cout << "Rejected\n";
    }else if((int)words.size() == 2){
        if((p.count(words[0]) != 0 or pn.count(words[0]) != 0) and v.count(words[1]) != 0){
            cout << "Accepted\n";
        }else{
            cout << "Rejected\n";
        }
    }else if((int)words.size() == 3){
        if((p.count(words[0]) != 0 or pn.count(words[0]) != 0) and v.count(words[1]) != 0 and n.count(words[2])){
            cout << "Accepted\n";
        }else{
            cout << "Rejected\n";
        }
    }else{
        cout << "Rejected\n";
    }
    return 0;
}