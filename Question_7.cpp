#include<bits/stdc++.h>
using namespace std;

char singleQuote = '\'';
char doubleQuote = '\"';

vector<string> keywords = {"xor", "true", "false", "or", "and", "for", "if", "else", "do", "while", "break", "continue", "int", "float", "double", "bool", "long", "unsigned", "char", "string", "void", "auto", "new", "switch", "namespace", "class", "const", "sizeof", "typedef", "delete", "nullptr", "main"};
vector<string> all_operators = {
    "+",
    "^",
    "-",
    "*",
    "/",
    "%",
    "++",
    "--",
    "+=",
    "-=",
    "%=",
    "*=",
    "/=",
    "==",
    "!=",
    ">",
    "<",
    ">>",
    "<<",
    ">=",
    "<=",
    "%=",
    "%",
    "||",
    "&&",
    "&",
    "="};

bool isIdentifier(string str){
    bool isIdentifier = false;
    if(isalpha(str[0]) or   str[0] == '_'){
        isIdentifier = true;
        for(int i = 1; i < (int)str.size(); i += 1){
            if(!isalpha(str[i]) and !isdigit(str[i]) and str[i] != '_' ){
                isIdentifier = false;
                break;
            }
        }
    }
    if(isIdentifier){
        return true;
    }else{
        return false;
    }
}

bool isOperator(string str){
    if(binary_search(all_operators.begin(), all_operators.end(), str)){
        return true;
    }else{
        return false;
    }
}
bool isKeyWord(string str){
    if(binary_search(keywords.begin(), keywords.end(), str)){
        return true;
    }else{
        return false;
    }
}
bool isConstant(string str){
   
    if(str[0] == doubleQuote and str[(int)str.size() - 1] == doubleQuote){
        return true;
    }else if(str[0] == singleQuote and str[(int)str.size() - 1] == singleQuote and (int)str.size() == 3){
        return true;    
    }else if(isdigit(str[0])){
        bool isConstant = true;
        int pointCount = 0;
        for(int i = 0; i < (int)str.size(); i += 1){
            if(str[i] == '.'){
                pointCount += 1;
                continue;
            }
            if(!isdigit(str[i])){
                isConstant = false;
                break;
            }
        }
        if(pointCount <= 1 and isConstant){
            return true;
        }
    }
    return false;
}
vector<string> seperateWords(string str){
    vector<string> words;
    string word = "";
    for (auto letter : str){
        if (letter == ' '){
            words.push_back(word);
            word = "";
        }else{
            word += letter;
        }
    }
    words.push_back(word);
    return words;
}
int main(){

    sort(keywords.begin(), keywords.end());
    sort(all_operators.begin(), all_operators.end());

    string str;
    getline(cin >> ws, str);
    vector<string> lexemes = seperateWords(str);
    for(int i = 0; i < (int)lexemes.size(); i += 1){
        cout << "Scanned : " << lexemes[i] << '\n';
        if(isConstant(lexemes[i])){
            cout << "Constant\n";
        }else if(isKeyWord(lexemes[i])){
            cout << "Keywords\n";
        }else if(isOperator(lexemes[i])){
            cout << "Operator\n";
        }else if(isIdentifier(lexemes[i])){
            cout << "Identifier\n";
        }else{
            cout << "Invalid Input" << '\n';
        }
    }
    return 0;
}