#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);

    long long ans=LONG_LONG_MAX;
    for(long long i=1;i*i<=m;i++){
        long long quo=m/i;
        if(m%i!=0){
            quo++;
        }
        if(quo<=n){
            ans=min(ans,i*quo);
        }
    }

    if(ans==LONG_LONG_MAX){
        if(n*n>=m){
            ans=n*n;
        }else{
            ans=-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}