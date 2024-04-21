#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,ans=0;
    scanf("%lld",&x);
    if(x>=0){
        if(x%10==0){
            ans=x/10;
        }else{
            ans=x/10+1;
        }
    }else{
        ans=x/10;
    }
    printf("%lld\n",ans);
    return 0;
}