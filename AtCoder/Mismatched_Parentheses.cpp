#include<bits/stdc++.h>
using namespace std;
char s[200010];
stack<int> lparen;  //maintain the index of the rightmost '('
vector<pair<char,int>> ans; //<s[i],idx>
int main(){
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            ans.emplace_back(s[i],i);
            lparen.emplace(i);
        }else if(s[i]==')'){
            if(!lparen.empty()){
                int idx=lparen.top();lparen.pop();
                while(!ans.empty() && ans.back().second>=idx){
                    ans.pop_back();
                }
            }else{
                ans.emplace_back(s[i],i);
            }
        }else{
            ans.emplace_back(s[i],i);
        }
    }

    for(auto [ch,_]:ans){
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}
/*
whenever we meet a ')', get the index of the rightmost '(', and pop everything between '(' and ')'
*/