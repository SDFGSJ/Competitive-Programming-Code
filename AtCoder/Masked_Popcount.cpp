#include<bits/stdc++.h>
using namespace std;
long long pow2[62]; //pow2[i]=2**i
const int mod=998244353;
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);

    pow2[0]=1;
    for(int i=1;i<=60;i++){
        pow2[i]=pow2[i-1]*2;
    }

    long long ans=0;
    for(int i=0;i<60;i++){
        if(m&(1ll<<i)){ //beware of overflow by shifting int too much
            ans+=(n+1)/pow2[i+1]*pow2[i];
            ans%=mod;
            ans+=max((n+1)%pow2[i+1]-pow2[i], 0ll);
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
consider bit by bit
for bit 0 to bit 59 in m, if bit i=1
then calculate #{num | i-th bit of num = 1, num in [0,n]} = (n+1)/(2**(i+1)) * (2**i) + remain
where remain = max{(n+1) % (2**(i+1)) - 2**i, 0}
idea same as editorial https://atcoder.jp/contests/abc356/editorial/10144
*/