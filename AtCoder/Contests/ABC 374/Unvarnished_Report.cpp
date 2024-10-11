#include<bits/stdc++.h>
using namespace std;
char s[105],t[105];
int main(){
    scanf("%s%s",s,t);
    int slen=strlen(s),tlen=strlen(t);
    int ans=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=t[i]){
            ans=i+1;
            break;
        }
    }
    if(slen!=tlen && ans==0){
        ans=min(slen,tlen)+1;
    }
    printf("%d\n",ans);
    return 0;
}