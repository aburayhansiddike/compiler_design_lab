#include<bits/stdc++.h>
using namespace std;

bool isLongInt(string str){
    int cnt = 0;
    if(str[0] > '1' and str[0] <= '9') cnt += 1;

    for(int i = 1; i < (int)str.size(); i += 1){
        if(str[i] >= '0' and str[i] <= '9'){
            cnt += 1;
            continue;
        }else return false;
    }

    if(cnt >= 5) return true;
    else return false;
}
bool isShortInt(string str){
    bool flg = true;
    if(str[0] > '0' and str[0] <= '9') return true;
    else flg = false;

    for(int i = 1; i < (int)str.size(); i += 1){
        if(str[i] >= '0' and str[i] <= '9'){
            continue;
        }else return false;
    }

    return flg;
}
bool isVariable(string str){
    bool flg = true;
    if(tolower(str[0]) < 'i' or towlower(str[0]) > 'n'){
        flg = false;
    }

    for(int i = 1; i < (int)str.size(); i += 1){
        if(tolower(str[0]) >= 'a' and tolower(str[0]) <= 'z' ){
            continue;
        }else if(str[i] >= '0' and str[i] <= '9'){
            continue;
        }else{
            flg = false;
            break;
        }
    }
    return flg;
}
int main(){
    string str;
    getline(cin >> ws, str);

    if(isVariable(str)){
        cout << "Integer variable\n";
    }else if((int)str.size() <= 4 and isShortInt(str)){
        cout << "ShortInt Number" << '\n';
    }else if(isLongInt(str)){
        cout << "Long Int Number\n";
    }else{
        cout << "Otherwise\n";
    }
    
    return 0;
}