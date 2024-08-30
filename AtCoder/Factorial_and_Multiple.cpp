#include<bits/stdc++.h>
using namespace std;
map<long long,int> fac; //<div,exp>
long long k;
bool ok(long long num){
    for(auto [div,exp]:fac){
        long long base=div,result=0;
        while(base<=num){
            result+=num/base;
            base*=div;
        }
        if(result<exp){
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%lld",&k);

    bool isprime=true;
    long long tmp=k;
    for(long long i=2;i*i<=k;i++){
        while(tmp%i==0){
            isprime=false;
            fac[i]++;
            tmp/=i;
        }
    }
    if(tmp!=1){ //remaining
        fac[tmp]++;
    }

    if(isprime){
        printf("%lld\n",k);
        return 0;
    }

    long long l=1,r=k;
    while(l+1<r){
        long long mid=(l+r)/2;
        if(ok(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%lld\n",r);
    return 0;
}
/*
FFFTTTTT => binary search
number of 2 that 8! contains = 8/2 + 8/4 + 8/8 = 7, which means 2**7 | 8!
number of x that n! contains = n/x + n/(x^2) + n/(x^3) + ... as long as (x^p)<=n
*/