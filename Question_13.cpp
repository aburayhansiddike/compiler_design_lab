#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammer;
map<char, set<char>> First;
map<char,set<char>> follow = {{'S', {'$'}}};
map<char, bool> hasEps;

bool isVariable(char ch){
    if(ch >= 'A' and ch <= 'Z'){
        return true;
    }else{
        return false;
    }
}
void inputGrammer(){
    char start, x;
    string rule;
    while(cin >> start >> x >> x >> rule){
       grammer[start].push_back(rule);
    }

    cout << "Given grammer is : " << '\n';
    for(auto it : grammer){
        for(auto it1 : it.second){
            cout << it.first << " -> " << it1 << '\n';
        }
    }
}
void computeFirst(){
    for(auto g : grammer){
        for(auto s : g.second){
            if(s[0] >= 'A' and s[0] <= 'Z'){
                continue;
            }else{
                First[g.first].insert(s[0]);
            }
        }
    }

    int variable = (int)grammer.size();
    for(int i = 1; i <= variable; i += 1){
        for(auto g : grammer){
            bool next = true;
            for(auto s : g.second){
                for(int j = 0; j < (int)s.size(); j += 1){
                    char ch = s[j];
                    if(ch >= 'A' and ch <= 'Z'){
                        int cntProduction = (int)grammer[ch].size();
                        int cntFirst = (int)First[ch].size();

                        if(cntProduction > cntFirst){
                           next = false;
                           break;
                        }
                        bool eps = false;
                        for(auto f : First[ch]){
                            if(f == '@'){
                                eps = true;
                            }
                            First[g.first].insert(f);
                        }
                        if(!eps) break;
                        else{
                            if(j < (int)s.size() - 1){
                                First[g.first].erase(First[g.first].find('@'));
                            }else{
                                hasEps[g.first] = true;
                            }
                        }
                    }else{
                        First[g.first].insert(ch);
                        break;
                    }
                }
                if(!next){
                    break;
                }
            }
        }
    }

    for(auto it : hasEps){
        if(it.second){
            First[it.first].insert('@');
        }
    }
    cout << '\n';
    cout << "First : \n";
    for(auto it : First){
        cout << it.first << " ---> ";
        for(auto it1 : it.second){
            cout << it1 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void computeFollow(){
    for(auto g : grammer){
        for(auto rule : g.second){
            for(int i = 0; i < rule.size() - 1; i += 1){
                if(isVariable(rule[i])){
                    if(!isVariable(rule[i + 1])){
                        follow[rule[i]].insert(rule[i + 1]);
                    }
                }
            }
        }
    }

    int variable = grammer.size();
    for(int i = 1; i <= variable; i += 1){
        for(auto g : grammer){
            for(auto rule : g.second){
                for(int j = 0; j < (int)rule.size(); j += 1){
                    if(isVariable(rule[j])){
                        for(int k = j + 1; k < (int)rule.size(); k += 1){
                            if(!isVariable(rule[k])){
                                follow[rule[j]].insert(rule[k]);
                                break;
                            }else{
                                for(auto frst : First[rule[k]]){
                                    follow[rule[j]].insert(frst);
                                }
                                if(follow[rule[j]].count('@') == 0){
                                    break;
                                }else{
                                    follow[rule[j]].erase(follow[rule[j]].find('@'));
                                    if(k + 1 == (int)rule.size()){
                                        for(auto flo : follow[g.first]){
                                            follow[rule[j]].insert(flo);
                                        }
                                    }
                                }
                            }
                        }
                        if(j + 1 == (int)rule.size()){
                            for(auto flo : follow[g.first]){
                                follow[rule[j]].insert(flo);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Follow : \n";
    for(auto it : follow){
        cout << it.first << " ---> ";
        for(auto it1 : it.second){
            cout << it1 << ' ';
        }
        cout << '\n';
    }
}

int main(){
    inputGrammer();
    computeFirst();
    computeFollow();
    return 0;
}