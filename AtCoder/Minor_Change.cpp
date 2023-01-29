#include<bits/stdc++.h>
using namespace std;
char s[200010],t[200010];
int main(){
    int cnt=0,i;
    scanf("%s%s",s,t);
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=t[i]){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}