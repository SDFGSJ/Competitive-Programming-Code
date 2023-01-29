#include<bits/stdc++.h>
using namespace std;
char s[5];
int main(){
    int ans=0,i;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        ans+=s[i]-'0';
    }
    printf("%d",ans);
    return 0;
}