#include<bits/stdc++.h>
using namespace std;


class SyntaxTree{
    map<string, string> prods = {
        {"E+E", "E"},
        {"E-E", "E"},
        {"E*E", "E"},
        {"E/E", "E"},
        {"(E)", "E"},
        {"a", "E"},
        {"b", "E"},
        {"c", "E"},
    };

    map<string, string> edges = {
        {"E+E", "/|\\"},
        {"E-E", "/|\\"},
        {"E*E", "/|\\"},
        {"E/E", "/|\\"},
        {"(E)", "/|\\"},
        {"a", "|"},
        {"b", "|"},
        {"c", "|"},
    };

public:
      bool flg = true;
      string str;
      string isSpace = "";
      vector<string> tree;

      SyntaxTree(string str1){
         this -> str = str1;
         this -> tree.push_back(this -> str);
      }

      bool reduce(){
          string space = "";
          for(int i = 0; i < (int)str.size(); i += 1){
              if(i > 0){
                space += " ";
              }

              for(auto prod : prods){
                  if(str.substr(i, prod.first.size()) == prod.first){
                       str.erase(i, prod.first.size());
                       str.insert(i, prod.second);
                       tree.push_back(space + isSpace + edges[prod.first]);

                       if((int)prod.first.size() == 3){
                           isSpace += " ";
                       }
                       tree.push_back(isSpace + str);
                       return true;
                  }
              }
          }
          return false;
      }
      void treeGenaretion(){

          while(str.size() > 1){
              if(!reduce()){
                 flg = false;
                 cout << str << '\n';
                 return;
              }
          }

          while((int)tree.size() > 0){
             cout << tree.back() << '\n';
             tree.pop_back();
          }
      }
};

int main(){
    string str;
    cin >> str;

    SyntaxTree syntaxTree(str);
    syntaxTree.treeGenaretion();
    return 0;
}