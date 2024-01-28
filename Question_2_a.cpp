#include<bits/stdc++.h>
using namespace std;

set<char> vowelList = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};


int countConsonent(string str){
    int strLen = str.size();
    int cnt = 0;
    for(int i = 0; i < strLen; i += 1){
        if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')){
            if(vowelList.find(str[i]) == vowelList.end()){
                cnt = cnt + 1;
            }
        }
    }

    return cnt;
}
int countVowel(string str){
    int strLen = str.size();
    int cnt = 0;
    for(int i = 0; i < strLen; i += 1){
        if(vowelList.find(str[i]) != vowelList.end()){
            cnt = cnt + 1;
        }
    }

    return cnt;
}
int main(){
    string str;
    getline(cin >> ws, str);

    int numberOfVowel = countVowel(str);
    int numberOfConsonant = countConsonent(str);
    cout << "Vowel : " << numberOfVowel << '\n';
    cout << "Consonent : " << numberOfConsonant << '\n';
    return 0;
}