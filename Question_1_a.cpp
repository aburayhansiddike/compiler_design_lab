#include<bits/stdc++.h>
using namespace std;

int countNumberOfOtherCharacter(string str){
    int cntOtherChar = 0;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        bool isCharcter = ((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z'));
        bool isDigit = (str[i] >= '0' and str[i] <= '9');

        if(!(isCharcter or isDigit)){
            cntOtherChar = cntOtherChar + 1;
        }
    }

    return cntOtherChar;
}
int countNumberOfDigits(string str){
    int cntDigits = 0;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        if(str[i] >= '0' and str[i] <= '9'){
            cntDigits = cntDigits + 1;
        }
    }

    return cntDigits;
}
int countNumberOfLetters(string str){
    int cntLetters = 0;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')){
            cntLetters = cntLetters + 1;
        }
    }

    return cntLetters;
}
int countNumberOfWords(string str){
    str = " " + str;
    int cntWords = 0;
    int strLen = (int)str.size();
    for(int i = 0; i < strLen; i += 1){
        if(str[i] == ' '){
            cntWords = cntWords + 1;
        }
    }
    return cntWords;
}
int main(){
    string str;
    getline(cin >> ws, str);

    int numberOfWords = countNumberOfWords(str);
    int numberOfLetters = countNumberOfLetters(str);
    int numberOfDigits = countNumberOfDigits(str);
    int numberOfOtherChar = countNumberOfOtherCharacter(str);
    cout << "Words : " << numberOfWords << '\n';
    cout << "Letters : " << numberOfLetters << '\n';
    cout << "Digits : " << numberOfDigits << '\n';
    cout << "Ohter Character : " << numberOfOtherChar << '\n';
    return 0;
}