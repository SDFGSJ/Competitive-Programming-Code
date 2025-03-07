#include<bits/stdc++.h>
using namespace std;
char s[200010];
stack<char> stk;
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='<'){
            stk.emplace(s[i]);
        }else{
            if(!stk.empty()){
                char t=stk.top();
                if(t=='(' && s[i]==')'){
                    stk.pop();
                    continue;
                }
                if(t=='[' && s[i]==']'){
                    stk.pop();
                    continue;
                }
                if(t=='<' && s[i]=='>'){
                    stk.pop();
                    continue;
                }
            }
            stk.emplace(s[i]);  //right paren doesnt match, push this into stack
        }
    }

    if(stk.size()>0){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}
/*
stack
parenthesis matching problem
*/