#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long mypow(long long a,long long b){
    long long result=1;
    while(b){
        if(b&1){
            result*=a;
            result%=mod;
        }
        a*=a,a%=mod;
        b>>=1;
    }
    return result;
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",mypow(a,b));
    return 0;
}