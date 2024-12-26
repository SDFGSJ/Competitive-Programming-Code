#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long pre[200010],suf[200010];
long long mypow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);

    pre[1]=1;suf[1]=n;
    for(int i=2;i<=200000;i++){
        pre[i]=(pre[i-1]*i)%mod;
        suf[i]=(suf[i-1]*(n-i+1))%mod;
    }
    long long all=mypow(2,n)-1, nCa=suf[a]*mypow(pre[a],mod-2)%mod, nCb=suf[b]*mypow(pre[b],mod-2)%mod;
    printf("%lld\n",((all - nCa - nCb)%mod+mod)%mod);
    return 0;
}
/*
pre[i] = (1*2*...*i)%M
suf[i] = n(n-1)...(n-i+1)%M
C(n,a) = n!/(a!(n-a)!) = n(n-1)...(n-a+1)/a! = suf[a]/pre[a] % mod
ans is (2^n)-1 - C(n,a) - C(n,b)
since the result might < 0
so we take mod => add mod => and take mod again
*/