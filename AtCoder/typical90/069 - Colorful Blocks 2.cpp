#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long mypow(long long a,long long b){
    long long result=1;
    while(b){
        if(b&1){
            result=(result*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return result;
}
int main(){
    long long n;
    int k;
    scanf("%lld%d",&n,&k);
    long long ans=0;
    if(n>=1){
        ans=k;
    }
    if(n>=2){
        ans=ans*(k-1)%mod;
    }
    if(n>=3){
        ans=ans*mypow(max(k-2,0),n-2)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}