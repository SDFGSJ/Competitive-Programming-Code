#include<bits/stdc++.h>
using namespace std;
char s[300010];
bool box[26];
stack<char> stk;
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            stk.emplace(s[i]);
        }else if(s[i]==')'){    //pop until '('
            while(!stk.empty() && stk.top()!='('){
                char ch=stk.top();stk.pop();
                box[ch-'a']=false;
            }
            stk.pop();  //pop '('
        }else{
            if(box[s[i]-'a']){
                printf("No\n");
                return 0;
            }
            stk.emplace(s[i]);
            box[s[i]-'a']=true;
        }
    }
    printf("Yes\n");
    return 0;
}
/*
stack + bool array[26]
*/