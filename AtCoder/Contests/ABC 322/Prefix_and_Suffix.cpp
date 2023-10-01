#include<bits/stdc++.h>
using namespace std;
char s[105],t[105];
int main(){
    int n,m,ans=0,i,j;
    bool ispre=true,issuf=true;
    scanf("%d%d%s%s",&n,&m,s,t);
    for(i=0;i<n;i++){
        if(s[i]!=t[i]){
            ispre=false;
        }
    }
    for(i=n-1, j=m-1;i>=0;i--, j--){
        if(s[i]!=t[j]){
            issuf=false;
        }
    }
    if(ispre && issuf){
        ans=0;
    }else if(ispre && !issuf){
        ans=1;
    }else if(!ispre && issuf){
        ans=2;
    }else{
        ans=3;
    }
    printf("%d\n",ans);
    return 0;
}