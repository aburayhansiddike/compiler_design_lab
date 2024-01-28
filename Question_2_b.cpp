#include<bits/stdc++.h>
using namespace std;

set<char> vowelList = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};


vector<char> getAllConsonent(string str){
    int strLen = str.size();
    vector<char> consonents;
    for(int i = 0; i < strLen; i += 1){
        if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')){
            if(vowelList.find(str[i]) == vowelList.end()){
                consonents.push_back(str[i]);
            }
        }
    }

    return consonents;
}
vector<char> getAllVowel(string str){
    int strLen = str.size();
    vector<char> vowels;
    for(int i = 0; i < strLen; i += 1){
        if(vowelList.find(str[i]) != vowelList.end()){
            vowels.push_back(str[i]);
        }
    }

    return vowels;
}
int main(){
    string str;
    getline(cin >> ws, str);

    vector<char> vowels = getAllVowel(str);
    vector<char> consonants = getAllConsonent(str);
    cout << "Vowel : " ;
    for(auto it : vowels){
        cout << it << ' ';
    }
    cout << '\n';
    cout << "Consonent : ";
    for(auto it : consonants){
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}