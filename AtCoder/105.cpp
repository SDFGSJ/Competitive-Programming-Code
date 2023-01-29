#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    scanf("%d",&n);
    if(n<105){
        ans=0;
    }else if(n<135){
        ans=1;
    }else if(n<165){
        ans=2;
    }else if(n<189){
        ans=3;
    }else if(n<195){
        ans=4;
    }else{
        ans=5;
    }
    printf("%d\n",ans);
    return 0;
}