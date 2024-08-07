#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long twoinv;   //multiplicative inverse of 2
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
long long helper(unsigned long long lower, unsigned long long upper, long long digit){
    long long a = (((upper-lower+1)%mod)*digit)%mod;
    long long b = (lower+upper)%mod;
    return (((a*b)%mod)*twoinv)%mod;
}
unsigned long long calc(long long num){
    unsigned long long lower=1,upper=9,digit=1,ans=0;
    while(num>=upper){
        ans+=helper(lower,upper,digit);
        ans%=mod;
        lower*=10;
        upper=upper*10+9;
        digit++;
    }

    if(num-lower>=0){   //remaining part
        ans+=helper(lower,num,digit);
        ans%=mod;
    }
    return ans;
}
int main(){
    long long l,r;
    scanf("%lld%lld",&l,&r);
    twoinv=mypow(2,mod-2);
    printf("%lld\n",(calc(r)-calc(l-1)+mod)%mod);
    return 0;
}