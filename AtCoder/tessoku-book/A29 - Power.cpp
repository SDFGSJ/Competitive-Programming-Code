#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long pow(long long a,long long b){
    long long result=1;
    while(b>0){
        if(b&1){
            result=(result*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return result;
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",pow(a,b));
    return 0;
}