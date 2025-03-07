#include<bits/stdc++.h>
using namespace std;
char s[15],t[15];
bool valid(char ch){
    for(int i=0;i<7;i++){
        if("atcoder"[i]==ch){
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%s%s",s,t);
    int len=strlen(s);
    bool ok=true;
    for(int i=0;i<len;i++){
        if(s[i]!=t[i]){
            if(s[i]!='@' && t[i]!='@'){
                ok=false;
            }
            if(s[i]=='@' && !valid(t[i])){
                ok=false;
            }
            if(!valid(s[i]) && t[i]=='@'){
                ok=false;
            }
        }
    }

    if(ok){
        printf("You can win\n");
    }else{
        printf("You will lose\n");
    }
    return 0;
}
/*
simulation
if s[i] and t[i] are the same, no matter they are both character or '@', it is ok
if s[i] and t[i] are different, divide by cases:
    one of them is '@' => check whether the other is one of "atcoder"
    both of them are not '@' => ans is no
*/