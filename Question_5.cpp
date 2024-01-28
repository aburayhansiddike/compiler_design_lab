#include<bits/stdc++.h>
using namespace std;

bool isDigits(string str){
    for(int i = 0; i < (int)str.size(); i += 1){
        if(str[i] >= '0' and str[i] <= '9'){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool isDoubleNumber(string str){
    
    int pointIdx = -1;
    for(int i = 0; i < (int)str.size(); i += 1){
        if(str[i] == '.'){
            pointIdx = i;
            break;
        }
    }
    
    if(pointIdx <= 0 or str.back() == '.'){
        return false;
    }

    string beforePoint = "", afterPoint = "";
    beforePoint = str.substr(0, pointIdx);
    afterPoint = str.substr(pointIdx + 1);

    if(!isDigits(beforePoint) or !isDigits(afterPoint)){
        return false;
    }

    if(afterPoint.size() >= 3){
        if(beforePoint.size() == 1){
            return true;
        }else{
            if(beforePoint[0] == '1'){
                return true;
            }else{
                return false;
            }
        }
    }

    return true;
}
bool isFloatNumber(string str){
    string beforePoint = "", afterPoint = "";
    int pointIdx = -1;
    for(int i = 0; i < (int)str.size(); i += 1){
        if(str[i] == '.'){
            pointIdx = i;
            break;
        }
    }
    
    if(pointIdx <= 0 or str.back() == '.'){
        return false;
    }

    beforePoint = str.substr(0, pointIdx);
    afterPoint = str.substr(pointIdx + 1);

    if(!isDigits(beforePoint) or !isDigits(afterPoint)){
        return false;
    }
    
    if(afterPoint.size() == 2){
        if(beforePoint.size() == 1){
            return true;
        }else{
            if(beforePoint[0] == '1'){
                return true;
            }else return false;
        }
    }else{
        return false;
    }
}
bool isFloatVarible(string str){
    bool flg = false;
    char c = str[0];
    if((tolower(c) >= 'a' and tolower(c) <= 'h') or (tolower(c) >= 'o' and tolower(c) <= 'z') or (c >= '0' and c <= '9')){
        flg = true;
    }

    for(int i = 1; i < (int)str.size(); i += 1){
        if(!isalpha(str[i])){
            flg = false;
            break;
        }
    }

    return flg;
}
int main(){
    string str;
    getline(cin >> ws, str);

    if(isFloatVarible(str)){
        cout << "FloadVariable\n";
    }else if(isFloatNumber(str)){
        cout << "FloatNumber\n";
    }else if(isDoubleNumber(str)){
        cout << "Double Number\n";
    }else{
        cout << "Invalid Input or Undefined\n";
    }

    return 0;
}