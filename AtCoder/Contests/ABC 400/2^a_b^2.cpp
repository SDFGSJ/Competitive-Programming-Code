#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    scanf("%lld",&N);

    long long ans=(long long)sqrtl(N/2)+(long long)sqrtl(N/4);
    printf("%lld\n",ans);
    return 0;
}
/*
only need to focus on a=1,2
for a>=3, we can always reduce a to 1 or 2
if a is odd, 2^(2k+1) * b^2 = (2^k)^2 * 2 * b^2 = 2^1 * (2^k * b)^2 (a=1 case)
if a is even, 2^(2k+2) * b^2 = (2^k)^2 * 2^2 * b^2 = 2^2 * (2^k * b)^2 (a=2 case)
Editorial video watched
*/