#include<bits/stdc++.h>
using namespace std;
bool exist[10];
char s[10];
int main(){
    int i;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        exist[s[i]-'0']=true;
    }
    for(i=0;i<=9;i++){
        if(!exist[i]){
            printf("%d",i);
            break;
        }
    }
    return 0;
}