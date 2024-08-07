#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long mypow(long long a, long long b){
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
    long long w;
    scanf("%lld",&w);
    printf("%lld\n",12*mypow(7,w-1) % mod);
    return 0;
}
/*
First, consider 2x1 grid => 4*3 combinations
Second, consider 2x2 grid =>
(case 1)
ab
b? => (b = 1 choice) x (? = 3 choices) => 3 combinations
(case 2: c's color is different from b)
ac
b? => (c = 2 choices) x (? = 2 choices) => 4 combinations
3+4=7 for column 2,3,4...
*/