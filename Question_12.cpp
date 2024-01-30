#include<bits/stdc++.h>
using namespace std;


class LexicalAnalyzer{
    map<string, string> prods = {
        {"EAE", "E"},
        {"EAE", "E"},
        {"EAE", "E"},
        {"EAE", "E"},
        {"(E)", "E"},
        {"ID", "E"},
        {"+", "A"},
        {"-", "A"},
        {"*", "A"},
        {"/", "A"}
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
        {"ID", "|"}
    };

public:
      string str;
      LexicalAnalyzer(string str1){
        this->str = str1;
      }
      bool isOperator(char c){
         if(c == '+' or c == '-' or c == '*' or c == '/'){
            return true;
         }else{
            return false;
         }
      }

      bool isBraket(char c){
          if(c == ')' or c == '('){
             return true;
          }else{
             return false;
          }
      }

      bool isValidOparend(string operand){
          if(operand[0] >= '0' and operand[0] <= '9'){
              int cnt = 0;
              for(int i = 0; i < (int)operand.size(); i += 1){
                cnt += 1;
              }

              if(cnt == (int)operand.size()){
                 return true;
              }else{
                  return false;
              }
          }else{
              if(tolower(str[0]) >= 'a' and tolower(str[0]) <= 'z'){
                 return true;
              }else return false;
          }
      }
      bool replaceWithID(){
          str = "(" + str + ")";
          vector<int> bracktesAndOperatorIndex;

          for(int i = 0; i < (int)str.size(); i += 1){
              if(isOperator(str[i]) or isBraket(str[i])){
                bracktesAndOperatorIndex.push_back(i);
              }
          }
          for(int i = 0; i <(int)bracktesAndOperatorIndex.size() - 1; i += 1){
              int idx1 = bracktesAndOperatorIndex[i], idx2 = bracktesAndOperatorIndex[i + 1];
              if(idx1 + 1 == idx2) continue;
              int len = idx2 - idx1 - 1;
              string operand = str.substr(idx1 + 1, len);
              if(!isValidOparend(operand)){
                  return false;
              }
          }

          string newId = "(";
          for(int i = 0; i < (int)bracktesAndOperatorIndex.size() - 1; i += 1){
              int idx1 = bracktesAndOperatorIndex[i], idx2 = bracktesAndOperatorIndex[i + 1];
              if(idx1 + 1 == idx2){
                newId += str[idx2];
              }else{
                 newId += "ID";
                 newId += str[idx2];
              }
          }

          newId.pop_back();
          str = newId.substr(1);
          return true;
      }

      bool reduce(){
          for(int i = 0; i < (int)str.size(); i += 1){
              for(auto prod : prods){
                   if(str.substr(i, prod.first.size()) == prod.first){
                       str.erase(i, prod.first.size());
                       str.insert(i, prod.second);
                       return true;
                   }
              }
          }

          return false;
      }
      void isValid(){
          if(replaceWithID()){
              cout << "Replace with ID : " << str << '\n';
          }

          while((int)str.size() > 1){
               if(!reduce()){
                   cout << "Invalid\n";
                   return;
               }
          }

          cout << "Valid\n";
      }
      
};

int main(){
    string str;
    cin >> str;

    LexicalAnalyzer lexicalAnalyzer(str);
    lexicalAnalyzer.isValid();
    return 0;
}