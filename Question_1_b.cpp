#include<bits/stdc++.h>
using namespace std;

vector<char> getAllOtherCharacter(string str){
    vector<char> otherCharacters;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        bool isCharcter = ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z'));
        bool isDigit = (str[i] >= '0' and str[i] <= '9');

        if(!(isCharcter or isDigit)){
            otherCharacters.push_back(str[i]);
        }
    }

    return otherCharacters;
}

vector<char>getAllDigits(string str){
    vector<char> digits;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        if(str[i] >= '0' and str[i] <= '9'){
            digits.push_back(str[i]);
        }
    }

    return digits;
}

vector<char> getAllLetters(string str){
    vector<char> letters;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')){
            letters.push_back(str[i]);
        }
    }

    return letters;
}
int main(){
    string str;
    getline(cin >> ws, str);

    vector<char> words = getAllLetters(str);
    vector<char> digits = getAllDigits(str);
    vector<char> otherCharacters = getAllOtherCharacter(str);

    cout << "Words: ";
    for(auto it : words){
        cout << it << ' ';
    }
    cout << '\n';

    cout << "Digits : ";
    for(auto it : digits){
        cout << it << ' ';
    }
    cout << '\n';

    cout << "Other Characters : ";
    for(auto it : otherCharacters){
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}