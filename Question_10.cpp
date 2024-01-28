#include<bits/stdc++.h>
using namespace std;


string space = "\t\t\t\t";
int main(){
    int n;
    cout << "Enter the number of production rules : ";
    cin >> n;
    cin.ignore();
    string grammerLeft[n], grammerRight[n];
    for(int i = 0; i < n; i += 1){
        cout << "Enter the production rule " << i + 1 << " :  ";
        string temp;
        getline(cin >> ws, temp);
        bool left = true;
        for(int j = 0; j < (int)temp.size(); j += 1){
            if(temp[j] == ' '){
                continue;
            }
            if(temp[j] == '='){
                left = false;
                continue;
            }

            if(left){
                grammerLeft[i].push_back(temp[j]);
            }else{
                grammerRight[i].push_back(temp[j]);
            }
        }
    }

    map<string, string> grammerMap;
    cout << "\nGrammer : " << '\n';
    for(int i = 0; i < n; i += 1){
        cout << grammerLeft[i] << " -> " << grammerRight[i] << '\n';
        grammerMap[grammerRight[i]] = grammerLeft[i];
    }

    cout << "Input the string : ";
    string str;
    getline(cin >> ws, str);
    str += "$";
    cout << "Stack" << space << "String" << space << "Comment\n";
    cout << "********************************************************************************\n";

    string reduceString = "";
    while(str.front() != '$'){
        cout << "$";
        reduceString += str[0];
        str = str.substr(1);
        cout << reduceString << space << str << space << "shift" << '\n';


        while(true){
            bool flg = false;
            for(int i = 0; i < (int)reduceString.size(); i += 1){
                string tempSubstr = reduceString.substr(i);
                auto it = grammerMap.find(tempSubstr); 
                if(it != grammerMap.end() and it -> second.size() > 0){
                    // string leftString = reduceString.substr(0, i);
                    flg = true;
                }

                if(flg){
                    string comment = "reduced " + tempSubstr + " -> " + grammerMap[tempSubstr];
                    reduceString = reduceString.substr(0, i) + grammerMap[tempSubstr];
                    cout << "$" << reduceString << space << str << space << comment << '\n';
                    break;
                }
            }
            if(!flg){
                break;
            }
        }
    }

    if(reduceString == grammerLeft[0]){
        cout << "Accepted!\n";
    }else{
        cout << "Rejected\n";
    }
    return 0;
}