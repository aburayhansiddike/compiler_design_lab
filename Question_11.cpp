#include<bits/stdc++.h>
using namespace std;


class SyntaxTree{
    public:
    bool isOperator(char c ){
        if(c == '+' or c == '-' or c == '*' or c == '/'){
            return true;
        }else return false;
    }

    bool isOperand(char c){
        if(c >= 'a' and c <= 'z'){
            return true;
        }else{
            return false;
        }
    }

    vector<vector<char>> getSyntaxTree(string str){
        const int row = 101, col = 101;
        vector<vector<char>> tree(row, vector<char>(col, ' '));
        int rootRow = 1, rootCol = 2;
        for(int i = 0; i < (int)str.size(); i += 1){
            if(isOperator(str[i])){
                tree[rootRow][rootCol] = str[i];
                tree[rootRow + 1][rootCol - 1] = '/';
                tree[rootRow + 1][rootCol + 1] = '\\';
                tree[rootRow + 2][rootCol - 2] = str[i - 1];
                rootRow += 2;
                rootCol += 2;
            }
        }
        tree[rootRow][rootCol] = str.back();
        return tree;
    }
};
int main(){
    string str;
    getline(cin >> ws, str);

    SyntaxTree syntaxTree;
    vector<vector<char>> tree = syntaxTree.getSyntaxTree(str);
    cout << "Syntax tree for equation is : " << str << '\n';
    for(int i = 0; i < (int)tree.size(); i += 1){
        for(int j = 0; j < (int)tree[0].size(); j += 1){
            cout << tree[i][j];
        }
        cout << '\n';
    }
    return 0;
}
