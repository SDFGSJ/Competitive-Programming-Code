#include<bits/stdc++.h>
using namespace std;
int wcnt[300],bcnt[300];
int main(){
    int w,b;
    scanf("%d%d",&w,&b);
    string s,pattern="wbwbwwbwbwbw";
    for(int i=0;i<20;i++){
        s+=pattern;
    }

    for(int i=0;i<s.length();i++){
        wcnt[i+1]=wcnt[i];
        bcnt[i+1]=bcnt[i];
        if(s[i]=='w'){
            wcnt[i+1]++;
        }else{
            bcnt[i+1]++;
        }
    }
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if(wcnt[j]-wcnt[i]==w && bcnt[j]-bcnt[i]==b){
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}