#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    int gcd=__gcd(a,b);
    long long cnt_a=n/a, cnt_b=n/b, lcm=a*b/gcd, cnt_lcm=n/lcm;
    long long ans=n*(n+1)/2 - a*cnt_a*(cnt_a+1)/2 - b*cnt_b*(cnt_b+1)/2 + lcm*cnt_lcm*(cnt_lcm+1)/2;
    printf("%lld\n",ans);
    return 0;
}
/*
there are "floor(N/A)" numbers that are multiple of A in [1,N]
there are "floor(N/B)" numbers that are multiple of B in [1,N]
there are "floor(N/lcm(A,B))" numbers that are multiple of lcm(A,B) in [1,N]
so the ans is sum(1 to N) - sum(A, 2A,...) - sum(B, 2B,...) + sum(lcm, 2*lcm,...)
*/