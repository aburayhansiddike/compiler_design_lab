#include<bits/stdc++.h>
using namespace std;


set<char> vowelList = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
vector<string> getAllWords(string str){
    vector<string> words;
    string temp = "";
    int strLen = str.size();
    for(int i = 0; i < strLen; i += 1){
        if((str[i] >= 'a' and str[i] <= 'z') or (str[i] >= 'A' and str[i] <= 'Z')){
            temp += str[i];
        }else{
            if(temp.size() > 0){
                words.push_back(temp);
                temp.clear();
            }
        }
    }

    if(temp.size() > 0) words.push_back(temp);
    return words;
}
int main(){
    string str;
    getline(cin >> ws, str);

    vector<string> words = getAllWords(str);
    string vowel = "", consonent = "";
    for(int i = 0; i < (int)words.size(); i += 1){
        char letter = words[i][0];
        if(vowelList.find(letter) != vowelList.end()){
            vowel += words[i];
            vowel += " ";
        }else{
            consonent += words[i];
            consonent += " ";
        }
    }
    cout << "Vowel words string : " << vowel << '\n';
    cout << "Consonent words string : " << consonent << '\n';
    cout << '\n';
    return 0;
}