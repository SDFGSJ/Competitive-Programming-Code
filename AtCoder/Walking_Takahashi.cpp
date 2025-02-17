#include<bits/stdc++.h>
using namespace std;
int main(){
    long long X,K,D,ans=LONG_LONG_MAX;
    scanf("%lld%lld%lld",&X,&K,&D);
    if(abs(X)/D>K){
        if(X<0){
            ans=X+D*K;
        }else{
            ans=X-D*K;
        }
    }else{
        K-=(abs(X)/D);K%=2;
        if(K==0){
            ans=min(abs(X%D), abs(X%D-D));
        }else{
            ans=min(abs(X%D+D), abs(X%D-D));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
if X/D>K
    ans=X-DK
else
    K-=(X/D), K%=2
    beware of sign of K%D
    if K==0: ans=min(abs(K%D), abs(K%D-D))
    else:ans=abs(K%D+D) or abs(K%D-D)
*/