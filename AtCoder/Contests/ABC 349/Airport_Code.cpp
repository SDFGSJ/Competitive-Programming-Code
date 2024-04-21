#include<bits/stdc++.h>
using namespace std;
char s[100010],t[5];
int main(){
    scanf("%s%s",s,t);
    int i,ti=0;
    for(i=0;s[i]!='\0';i++){
        if('A'+(s[i]-'a')==t[ti]){
            ti++;
        }
    }
    if(ti<2 || (ti==2 && s[i]=='\0' && t[ti]!='X')){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}