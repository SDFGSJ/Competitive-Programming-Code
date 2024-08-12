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
    int n;
    scanf("%d",&n);
    long long ten=mypow(10,n), nine=mypow(9,n), eight=mypow(8,n);
    printf("%lld\n",((((ten-nine)*2 - (ten-eight))%mod)+mod)%mod);
    return 0;
}
/*
|A| = #seq that has at least 1 0 = 10^n - 9^n
|B| = #seq that has at least 1 9 = 10^n - 9^n
|A|B| = #seq that has at least 1 0 or at least 1 9 = 10^n - 8^n
find |A&B| = |A| + |B| - |A|B|
*/